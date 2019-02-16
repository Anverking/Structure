/*伸展树(Splay Tree)模板*/
#include<iostream>
#include<cstring>
#include<vector>
const int maxn=1e7;
template<class T>
class splaytree{
	private:
		int rev[maxn],child[maxn][2],parent[maxn],cnt[maxn],siz[maxn],ncnt;
		T value[maxn];
		int root; 
		inline bool check(int x){
    		return child[parent[x]][1]==x;
		}
		inline void update(int x){
    		siz[x]=siz[child[x][0]]+siz[child[x][1]]+cnt[x];
		}
		inline void rotate(int x){
    		int y=parent[x],z=parent[y],k=check(x),w=child[x][k^1];
    		child[y][k]=w;
			parent[w]=y;
    		child[z][check(y)]=x;
			parent[x]=z;
    		child[x][k^1]=y;
			parent[y]=x;
    		update(y);
			update(x);
		}
		inline void find(T x)
		{
    		int cur=root;
    		while(child[cur][x>value[cur]]&&x!=value[cur])
        		cur=child[cur][x>value[cur]];
    		splay(cur);
		}
		inline void pushdown(int x) {
    		if(rev[x]){
        		std::swap(child[x][0],child[x][1]);
        		rev[child[x][0]]^=1;
        		rev[child[x][1]]^=1;
        		rev[x]=0;
    		}
		}
		inline void splay(int x,int goal=0){
    		while(parent[x]!=goal){
		        int y=parent[x],z=parent[y];
        		if(z!=goal){
            		if(check(x)==check(y))
						rotate(y);
            		else 
						rotate(x);
        		}
        		rotate(x);
    		}
    		if(!goal)
				root=x;
		}
		inline void _display(int now,std::vector<int>&v)
		{
			if(child[now][0])
				_display(child[now][0]);
			v.push_back(now);
			if(child[now][1])
				_display(child[now][1]);
		}
	public:
		inline splaytree():ncnt(0),root(0)
		/*构造函数:建造一棵新的树.
		时间复杂度:O(1) 
		*/
		{
			memset(child,0,sizeof(child));
			memset(parent,0,sizeof(parent));
			memset(cnt,0,sizeof(cnt));
			memset(value,0,sizeof(value));
			memset(rev,0,sizeof(rev));
			memset(siz,0,sizeof(siz));
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
		inline T operator[](const int i)
		/*求值函数:求编号为i的节点的值.
		时间复杂度:O(1).
		*/
		{
			return value[i];
		}
		inline void modify(int x,T d)
		/*修改函数:将编号为x的节点的值改为d.
		时间复杂度:O(log2 n) 
		*/
		{
			splay(x);
			value[x]=d;
			update(x);
		}
		inline void insert(T x)
		/*插入函数:在树中插入一个元素.
		时间复杂度:O(log2 n).
		*/
		{
    		int cur=root,p=0;
    		while(cur&&value[cur]!=x)
        		p=cur,
        		cur=child[cur][x>value[cur]];
    		if(cur)
        		cnt[cur]++;
    		else
			{
        		cur=++ncnt;
        		if(p)
					child[p][x>value[p]]=cur;
        		child[cur][0]=child[cur][1]=0;
        		parent[cur]=p;
				value[cur]=x;
        		cnt[cur]=siz[cur]=1;
    		}
    			splay(cur);
		}
		inline int getrank(T x)
		/*求值函数:求树中值t为第几小.
		时间复杂度:O(log2 n).
		*/
		{
			find(x);
			return siz[child[root][0]];
		}
		inline int getkth(int k)
		/*求值函数:求树中第k小的节点编号.
		时间复杂度:O(log2 n).
		*/
		{
    		int cur=root;
    		while(1){
    			pushdown(cur); 
        		if(child[cur][0]&&k<=siz[child[cur][0]])
            		cur=child[cur][0];
				else 
					if(k>siz[child[cur][0]]+cnt[cur])
            			k-=siz[child[cur][0]]+cnt[cur],
            			cur=child[cur][1];
        			else
            			return cur;
    		}
		}
		inline void reverse(int l,int r)
		/*建造函数:反转一段区间[l,r].
		时间复杂度:O(log2 n) 
		*/
		{
    		int x=getkth(l),y=getkth(r+2);
    		splay(x);
			splay(y,x);
    		rev[child[y][0]]^=1;
		}
		inline int prev(T x)
		/*求值函数:求值比x小且最大的节点的编号.
		时间复杂度:O(log2 n).
		*/
		{
		    find(x);
    		if(value[root]<x)return root;
    		int cur=child[root][0];
    		while(child[cur][1])
				cur=child[cur][1];
    		return cur;
		}
		inline int succ(T x)
		/*求值函数:求值比x大且最小的节点的编号.
		时间复杂度:O(log2 n).
		*/
		{
    		find(x);
    		if(value[root]>x)return root;
    		int cur=child[root][1];
    		while(child[cur][0])
				cur=child[cur][0];
    		return cur;
		}
		inline void remove(T x)
		/*删除函数:删除树中值为x的节点.
		时间复杂度:O(log2 n).
		*/
		{
    		int last=prev(x),next=succ(x);
    		splay(last);
			splay(next,last);
    		int del=child[next][0];
    		if(cnt[del]>1)
        		cnt[del]--,
        	splay(del);
   			else 
			   	child[next][0]=0;
		}
		inline void display(std::vector<int>&v)
		{
			_display(root,v);
		}
		inline void clear()
		/*清空函数:清空整棵树.
		时间复杂度:O(1).
		*/
		{
			root=ncnt=0;
			memset(child,0,sizeof(child));
			memset(parent,0,sizeof(parent));
			memset(cnt,0,sizeof(cnt));
			memset(value,0,sizeof(value));
			memset(rev,0,sizeof(rev));
			memset(siz,0,sizeof(siz));
		}
};
int main(){

}
