/*树链剖分(Splited Link Tree)模板*/
#include<iostream>
#include<cstring>
const int maxn=1e4;
template<class T>
class splitree{
	private:
		class edge{
			public:
				int next,to;
		}line[maxn*2];
		class node{
			public:
				int left,right,leson,rison;
				T lazy;
				T sum;
		}tree[maxn*2];
		int root,head[maxn],cnt,ncnt,father[maxn],dist[maxn],son[maxn],size[maxn],top[maxn],idx[maxn],rank[maxn];
		T value[maxn];
		inline void dfs1(int x)
		{
    		size[x]=1,dist[x]=dist[father[x]]+1;
    		for(int v,i=head[x];i;i=line[i].next)
        		if((v=line[i].to)!=father[x])
        		{
            		father[v]=x,dfs1(v),size[x]+=size[v];
            		if(size[son[x]]<size[v])
                	son[x]=v;
        		}
		}
		inline void dfs2(int x,int tp)
		{
    		top[x]=tp,idx[x]=++cnt,rank[cnt]=x;
    		if(son[x])
        		dfs2(son[x],tp);
    		for(int v,i=head[x];i;i=line[i].next)
        		if((v=line[i].to)!=father[x]&&v!=son[x])
            		dfs2(v,v);
		}
		inline void pushup(int x)
		{
    		tree[x].sum=(tree[tree[x].leson].sum+tree[tree[x].rison].sum);
		}
		inline void pushdown(int x)
		{
    		if(tree[x].lazy)
    		{
        		int ls=tree[x].leson,rs=tree[x].rison,lz=tree[x].lazy;
        		tree[ls].lazy+=lz,
				tree[rs].lazy+=lz;
        		tree[ls].sum+=lz*length(ls),
				tree[rs].sum+=lz*length(rs);
        		tree[x].lazy=0;
    		}
		}
		inline void update(int l,int r,T c,int x)
		{
    		if(tree[x].left>=l&&tree[x].right<=r)
    		{
        		tree[x].lazy+=c,
				tree[x].sum+=length(x)*c;
        		return;
    		}
    		pushdown(x);
    		int mid=(tree[x].left+tree[x].right)>>1;
    		if(mid>=l)
        		update(l,r,c,tree[x].leson);
    		if(mid<r)
        		update(l,r,c,tree[x].rison);
    		pushup(x);
		}
		inline T query(int l,int r,int x)
		{
    		if(tree[x].left>=l&&tree[x].right<=r)
        		return tree[x].sum;
    		pushdown(x);
    		int mid=(tree[x].left+tree[x].right)>>1;
			T tot=0;
    		if(mid>=l)
        		tot+=query(l,r,tree[x].leson);
    		if(mid<r)
        		tot+=query(l,r,tree[x].rison);
    		return tot;
		}
		inline void _build(int l,int r,int x)
		{
    		if(l==r)
    		{
        		tree[x].sum=value[rank[l]],
				tree[x].left=tree[x].right=l;
        		return;
    		}
    		int mid=l+r>>1;
    		tree[x].leson=cnt++,
			tree[x].rison=cnt++;
    		_build(l,mid,tree[x].leson),
			_build(mid+1,r,tree[x].rison);
    		tree[x].left=tree[tree[x].leson].left,
			tree[x].right=tree[tree[x].rison].right;
    		pushup(x);
		}
	public:
		inline splitree():root(0),cnt(0),ncnt(0)
		/*构造函数:建造一棵空树.
		时间复杂度:O(1). 
		*/
		{
			memset(value,0,sizeof(value));
			memset(head,0,sizeof(head));
			memset(father,0,sizeof(father));
			memset(dist,0,sizeof(dist));
			memset(son,0,sizeof(son));
			memset(size,0,sizeof(size));
			memset(top,0,sizeof(top));
			memset(idx,0,sizeof(idx));
			memset(rank,0,sizeof(rank));
		}
		inline void clear()
		/*清空函数:清空整棵树.
		时间复杂度:O(1). 
		*/
		{
			root=cnt=ncnt=0;
			memset(value,0,sizeof(value));
			memset(head,0,sizeof(head));
			memset(father,0,sizeof(father));
			memset(dist,0,sizeof(dist));
			memset(son,0,sizeof(son));
			memset(size,0,sizeof(size));
			memset(top,0,sizeof(top));
			memset(idx,0,sizeof(idx));
			memset(rank,0,sizeof(rank));
		}
		inline int creat(T d)
		/*建造函数:建造一个新节点.
		时间复杂度:O(1). 
		*/
		{
			ncnt++;
			tree[ncnt].left=tree[ncnt].right=
			tree[ncnt].leson=tree[ncnt].rison=0;
			tree[ncnt].lazy=tree[ncnt].sum=d;
			return ncnt;
		}
		inline void insert(int x,int y)
		/*建造函数:添加一条x到y的有向边.
		时间复杂度:O(1). 
		*/
		{
    		line[++cnt].next=head[x];
    		line[cnt].to=y;
    		head[x]=cnt;
    		line[++cnt].next=head[y];
    		line[cnt].to=x;
    		head[x]=cnt;
		}
		inline void build(int n,int rt)
		/*建造函数:以n为节点数rt为根节点建树.
		时间复杂度:O(nlog2 n). 
		*/
		{
			cnt=0,dfs1(rt),dfs2(rt,rt);
    		cnt=0,_build(1,n,root=cnt++);
		}
		inline int length(int x)
		/*求值函数:求x所在链的长.
		时间复杂度:O(1). 
		*/
		{
    		return tree[x].right-tree[x].left+1;
		}
		inline T link_sum(int x,int y)
		/*求值函数:求x到y路径上的点值和.
		时间复杂度:O(log2 n). 
		*/
		{
    		T ret=0;
    		while(top[x]!=top[y])
    		{
        		if(dist[top[x]]<dist[top[y]])
            		std::swap(x,y);
        		ret+=query(idx[top[x]],idx[x],root);
        		x=father[top[x]];
    		}
    		if(idx[x]>idx[y])
        		std::swap(x,y);
    		return ret+query(idx[x],idx[y],root);
		}
		inline void link_update(int x,int y,T c)
		/*更改函数:将x到y的路径上的所有节点的值加上c.
		时间复杂度:O(log2 n). 
		*/
		{
    		while(top[x]!=top[y])
    		{
        		if(dist[top[x]]<dist[top[y]])
            		std::swap(x,y);
        		update(idx[top[x]],idx[x],c,root);
        		x=father[top[x]];
    		}
    		if(idx[x]>idx[y])
        		std::swap(x,y);
    		update(idx[x],idx[y],c,root);
		}
		inline void tree_update(int x,T c)
		/*更改函数:将以x为根的子树中的所有节点的值加上c.
		时间复杂度:O(log2 n). 
		*/
		{
			update(idx[x],idx[x]+size[x]-1,c,root);
		}
		inline T tree_sum(int x)
		/*求值函数:求以x为根的子树中所有节点的值之和.
		时间复杂度:O(log2 n). 
		*/
		{
			return query(idx[x],idx[x]+size[x]-1,root);
		}
};
int main()
{

}
