#include<iostream>
#include<cstring>
const int maxn=1e4;
template<class T>
class eulertree{
	private:
		class edge{
			public:
				int to,next;
		}Edge[maxn];
		inline void pushup(int x){
			sum[x]=sum[child[x][0]]+sum[child[x][1]]+value[x];
			size[x]=size[child[x][0]]+size[child[x][1]]+mark[x];
		}
		inline void pushdown(int x){
			if(x&&father[x])
				pushdown(father[x]);
		   	if(!x||!lazy[x])
			   	return;
		   	lazy[child[x][0]]+=lazy[x],
			lazy[child[x][1]]+=lazy[x];
		   	value[child[x][0]]+=lazy[x]*mark[child[x][0]],
			value[child[x][1]]+=lazy[x]*mark[child[x][1]];
		   	sum[child[x][0]]+=(T)size[child[x][0]]*lazy[x],
			sum[child[x][1]]+=(T)size[child[x][1]]*lazy[x];
		   	lazy[x]=0;
		}
		inline int check(int x){
		   	return child[father[x]][1]==x;
		}
		inline void rotate(int x,int d){
			int temp=child[x][d^1];
			child[x][d^1]=child[temp][d];
			if(child[x][d^1])
				father[child[x][d^1]]=x;
			father[temp]=father[x];
			if(father[x])
				child[father[x]][check(x)]=temp;
			father[x]=temp;
			child[temp][d]=x;
			pushup(x),
			pushup(temp);
		}
		inline int _build(T*a,int left,int right){
		   	if(left>right)
			   	return 0;
		   	int mid=(left+right)>>1;
		   	if(mid<right)
			   	father[child[mid][1]=_build(mid+1,right)]=mid;
		   	if(left<mid)
			   	father[child[mid][0]=_build(left,mid-1)]=mid;
		   	value[mid]=(dfn[mid]>0)?a[dfn[mid]]:-a[-dfn[mid]];
		   	mark[mid]=(dfn[mid]>0)?1:-1;
		   	pushup(mid);
		   	return mid;
		}
		inline void dfs(int x){
		   dfn[left[x]=++tot]=x;
		   for(int i=head[x];i;i=Edge[i].next)
		      dfs(Edge[i].to);
		   dfn[right[x]=++tot]=-x;
		}
		inline int getson(int x,int d){
		   	splay(x);
		   	x=child[x][d];
		   	while(child[x][d^1])
			   	x=child[x][d^1];
		     	return x;
		}
		inline void splay(int x,int goal=0){
		   	pushdown(x);
		   	while(father[x]!=goal)
			{
		    	if(father[father[x]]!=goal&&
			  	check(x)==check(father[x]))
		         	rotate(father[father[x]],check(x)^1);
		      	rotate(father[x],check(x)^1);
		    }
		}
		int father[maxn],size[maxn],child[maxn][2];
		int left[maxn],right[maxn],mark[maxn],dfn[maxn],tot;
		T lazy[maxn],sum[maxn],value[maxn];
		int head[maxn],cnt;
	public:
		inline eulertree():cnt(0),tot(0)
		{
			memset(size,0,sizeof(size));
			memset(father,0,sizeof(father));
			memset(child,0,sizeof(child));
			memset(left,0,sizeof(left));
			memset(right,0,sizeof(right));
			memset(mark,0,sizeof(mark));
			memset(dfn,0,sizeof(dfn));
			memset(head,0,sizeof(head));
		}
		inline void clear()
		{
			cnt=tot=0;
			memset(size,0,sizeof(size));
			memset(father,0,sizeof(father));
			memset(child,0,sizeof(child));
			memset(left,0,sizeof(left));
			memset(right,0,sizeof(right));
			memset(mark,0,sizeof(mark));
			memset(dfn,0,sizeof(dfn));
			memset(head,0,sizeof(head));
		}
		inline void insert(int x,int y){
		   	Edge[++cnt].to=y;
		   	Edge[cnt].next=head[x];
		   	head[x]=cnt;
		}
		inline void build(T*a,int n){
			memcpy(a+1,a,sizeof(a));
			dfs(1);
			_build(a,1,tot+1);
		}
		inline T query(int x)
		{
			splay(left[x]);
        	return sum[child[left[x]][0]]+value[left[x]];
		}
		inline void link(int x,int y)
		{
	        int a=getson(left[x],0),b=getson(right[x],1);
	        splay(a),
			splay(b,a);
	        int temp=child[b][0];
	        child[b][0]=0;
	        pushup(b),
			pushup(a);
	        splay(x,getson(right[y],0)),
			splay(right[y],x);
	        father[temp]=right[y];
	        child[right[y]][0]=temp;
	        pushup(right[y]),
			pushup(x);
		}
		inline void update(int x,int y)
		{
			int a=getson(left[x],0),b=getson(right[x],1);
        	splay(a,0),
			splay(b,a);
        	lazy[child[b][0]]+=y,
			value[child[b][0]]+=y*mark[child[b][0]],
			sum[child[b][0]]+=(T)size[child[b][0]]*y;
		}
};
int main()
{
	
}
