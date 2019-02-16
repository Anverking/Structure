/*Fhq Treapģ��*/
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
		/*���캯��:����һ�ÿ���.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			srand((unsigned)(time(0)));
			memset(data,0,sizeof(data));
			memset(child,0,sizeof(child));
			memset(rnd,0,sizeof(rnd));
			memset(siz,0,sizeof(siz));
		}
		inline T operator[](const int i)
		/*��ֵ����:����Ϊi�Ľڵ��ֵ.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			return data[i];
		}
		inline int size()
		/*��ֵ����:�����Ĵ�С.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			return siz[root];
		}
		inline bool empty()
		/*�жϺ���:�ж����Ƿ�Ϊ��.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			return !siz[root];
		}
		inline int merge(int x,int y)
		/*�ϲ�����:�ϲ���x��yΪ��������. 
		ʱ�临�Ӷ�:O(log2 n).
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
		/*�ʷֺ���:���������ʳ���������,һ��ΪǰkС�Ľڵ�,һ��Ϊ�����ڵ�.
		ʱ�临�Ӷ�:O(log2 n).
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
		/*��������:����һ��ֵΪx�Ľڵ�.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
    		tot++;
    		data[tot]=x;
			rnd[tot]=rand();
			siz[tot]=1;
    		return tot;
		}
		inline void insert(T t)
		/*���뺯��:�����в���һ��ֵΪt�Ľڵ�.
		ʱ�临�Ӷ�:O(log2 n). 
		*/
		{
			int x=rand(),y=rand();
			split(root,t,x,y);
			root=merge(merge(x,creat(t)),y);
		}
		inline void remove(T t)
		/*ɾ������:ɾ������ֵΪt�Ľڵ�.
		ʱ�临�Ӷ�:O(log2 n) 
		*/
		{
			int x=rand(),y=rand(),z=rand();
			split(root,t,x,z);    
			split(x,t-1,x,y);
			y=merge(child[y][0],child[y][1]);
			root=merge(merge(x,y),z);
		}
		inline int prev(T t)
		/*��ֵ����:��ֵ��xС�����Ľڵ�ı��.
		ʱ�临�Ӷ�:O(log2 n).
		*/
		{
			int x=rand(),y=rand();
			split(root,t-1,x,y);    
			int i=getkth(siz[x]);
			root=merge(x,y);
			return i;
		}
		inline int succ(T t)
		/*��ֵ����:��ֵ��x�������ҵĽڵ�ı��.
		ʱ�临�Ӷ�:O(log2 n).
		*/
		{
			int x=rand(),y=rand();
			split(root,t,x,y);    
			int i=getkth(1);
			root=merge(x,y);
			return i;
		}
		inline int getrank(T t)
		/*��ֵ����:������ֵtΪ�ڼ�С.
		ʱ�临�Ӷ�:O(log2 n). 
		*/
		{
			int x=rand(),y=rand();
			split(root,t-1,x,y);
            int i=siz[x]+1;
            root=merge(x,y);
            return i;
		}
		inline int getkth(int k)
		/*��ֵ����:�����е�kС�Ľڵ���.
		ʱ�临�Ӷ�:O(log2 n).
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
		/*��պ���:���������.
		ʱ�临�Ӷ�:O(1). 
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
