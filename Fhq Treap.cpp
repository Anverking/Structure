/*Fhq Treap模板*/
#include<iostream>
#include<ctime>
#include<cstring>
#include<cstdlib>
const int maxn=1e7;
template<class T>
class treap{
	private:
		int tot,root;
    	int child[maxn][2];
    	int rnd[maxn],siz[maxn];
    	T data[maxn];
		inline void update(int x)
		{
    		siz[x]=siz[child[x][0]]+1+siz[child[x][1]];
    		return;
		}
	public:
		inline treap():root(0),tot(0)
		/*构造函数:建造一棵空树.
		时间复杂度:O(1). 
		*/
		{
			srand((unsigned)(time(0)));
			memset(data,0,sizeof(data));
			memset(child,0,sizeof(child));
			memset(rnd,0,sizeof(rnd));
			memset(siz,0,sizeof(siz));
		}
		inline T operator[](const int i)
		/*求值函数:求编号为i的节点的值.
		时间复杂度:O(1). 
		*/
		{
			return data[i];
		}
		inline int size()
		/*求值函数:求树的大小.
		时间复杂度:O(1). 
		*/
		{
			return siz[root];
		}
		inline bool empty()
		/*判断函数:判断树是否为空.
		时间复杂度:O(1). 
		*/
		{
			return !siz[root];
		}
		inline int merge(int x,int y)
		/*合并函数:合并以x与y为根的子树. 
		时间复杂度:O(log2 n).
		*/
		{
    		if(!x||!y)return x|y;
    		if(rnd[x]<rnd[y])
    		{
        		child[x][1]=merge(child[x][1],y);
        		update(x);
        		return x;    
    		}
    		else 
    		{
        		child[y][0]=merge(x,child[y][0]);
        		update(y);
        		return y;
    		}
		}
		inline void split(int now,int k,int &x,int &y)
		/*剖分函数:将整棵树剖成两棵子树,一棵为前k小的节点,一棵为其它节点.
		时间复杂度:O(log2 n).
		*/
		{
    		if(!now) 
    		{
        		x=y=0;
        		return;
    		}
    		if(k>=data[now]) 
    		{
        		x=now;
        		split(child[now][1],k,child[now][1],y);    
    		}
    		else 
    		{
        		y=now;
        		split(child[now][0],k,x,child[now][0]);    
    		}
   			update(now);
    		return;
		}
		inline int creat(T x)
		/*创建函数:创建一个值为x的节点.
		时间复杂度:O(1). 
		*/
		{
    		tot++;
    		data[tot]=x;
			rnd[tot]=rand();
			siz[tot]=1;
    		return tot;
		}
		inline void insert(T t)
		/*插入函数:在树中插入一个值为t的节点.
		时间复杂度:O(log2 n). 
		*/
		{
			int x=rand(),y=rand();
			split(root,t,x,y);
			root=merge(merge(x,creat(t)),y);
		}
		inline void remove(T t)
		/*删除函数:删除树中值为t的节点.
		时间复杂度:O(log2 n) 
		*/
		{
			int x=rand(),y=rand(),z=rand();
			split(root,t,x,z);    
			split(x,t-1,x,y);
			y=merge(child[y][0],child[y][1]);
			root=merge(merge(x,y),z);
		}
		inline int prev(T t)
		/*求值函数:求值比x小且最大的节点的编号.
		时间复杂度:O(log2 n).
		*/
		{
			int x=rand(),y=rand();
			split(root,t-1,x,y);    
			int i=getkth(siz[x]);
			root=merge(x,y);
			return i;
		}
		inline int succ(T t)
		/*求值函数:求值比x大且最且的节点的编号.
		时间复杂度:O(log2 n).
		*/
		{
			int x=rand(),y=rand();
			split(root,t,x,y);    
			int i=getkth(1);
			root=merge(x,y);
			return i;
		}
		inline int getrank(T t)
		/*求值函数:求树中值t为第几小.
		时间复杂度:O(log2 n). 
		*/
		{
			int x=rand(),y=rand();
			split(root,t-1,x,y);
            int i=siz[x]+1;
            root=merge(x,y);
            return i;
		}
		inline int getkth(int k)
		/*求值函数:求树中第k小的节点编号.
		时间复杂度:O(log2 n).
		*/
		{
			int now=root;
    		while (1)
    		{
        		if(k<=siz[child[now][0]])
					now=child[now][0];
        		else 
        		{
            		if(k==siz[child[now][0]]+1)
						return now;
            		else
            		{
                		k=k-(siz[child[now][0]]+1);
                		now=child[now][1];    
            		}    
        		}    
    		}
		}
		inline void clear()
		/*清空函数:清空整棵树.
		时间复杂度:O(1). 
		*/
		{
			root=tot=0;
			memset(data,0,sizeof(data));
			memset(child,0,sizeof(child));
			memset(rnd,0,sizeof(rnd));
			memset(siz,0,sizeof(siz));
		}
};
int main(){

}
