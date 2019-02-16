#include<iostream>
#include<cstring>
#include<queue>
const int INF=0x3f3f3f3f;
const int maxn=1e3;
template<class T>
class gonorytree{
	private:
		class Edge{
			public:
				int to,next;
				T capa;
		}edge[maxn<<1];
		int head[maxn],cnt,n,now;
		int pdx[maxn],tdx[maxn],col[maxn];
		int fa[9][maxn],mn[9][maxn],dep[maxn];	
		inline void add_edge(int u,int v,T w)
		{
		    edge[++cnt].to=v;
		    edge[cnt].capa=w;
		    edge[cnt].next=head[u];
		    head[u]=cnt;
		    n=std::max(std::max(u,v),n);
		}		
		class Edge2{
			public:
				int to,next;
				T capa,flow;
		}edge2[maxn];
		int head2[maxn],cnt2,s,t;
		int d[maxn],cur[maxn];
		bool vis[maxn];		
		inline bool BFS()
		{
		    std::queue<int>q;
			q.push(s);
		    memset(vis,0,sizeof(vis));
		    vis[s]=1;
			d[s]=0;
		    while(!q.empty())
		    {
		        int u=q.front();q.pop();
		        for(int t=head2[u];~t;t=edge2[t].next)
		        {
		            int v=edge2[t].to;
		            if(!vis[v]&&edge2[t].capa>edge2[t].flow)
		            {
		                d[v]=d[u]+1;
		                vis[v]=1;
		                q.push(v);
		            }
		        }
		    }
		    return vis[t];
		}
		inline T DFS(int u,int a)
		{
		    if(u==t||a==0)
				return a;
		    T res=0,flow;
		    for(int &t=cur[u];~t;t=edge2[t].next)
		    {
		        int v=edge2[t].to;
		        if(d[v]!=d[u]+1) 
					continue;
		        flow=DFS(v,std::min(a,edge2[t].capa-
				edge2[t].flow));
		        if(!flow)
					continue;
		        edge2[t].flow+=flow;
		        edge2[t^1].flow-=flow;
		        res+=flow;
				a-=flow;
		        if(a==0)
					break;
		    }
		    return res;
		}	
		inline T Dinic(int x,int y)
		{
		    T flow=0;
			s=x;
			t=y;
		    for(int i=0;i<=cnt2;i++)
				edge2[i].flow=0;
		    while(BFS())
		    {
		        memcpy(cur,head2,sizeof(head2));
		        flow+=DFS(s,INF);
		    }
		    return flow;
		}
		inline void dfs(int u)
		{
		    col[u]=now;
		    for(int t=head2[u];~t;t=edge2[t].next)
		        if(edge2[t].capa>edge2[t].flow&&
				col[edge2[t].to]!=now)
		            dfs(edge2[t].to);
		}
		inline void _build(int l,int r)
		{
			if(l>=r) return;
			int x=pdx[l],y=pdx[l+1];
			T cut=Dinic(x,y);
			now++;
			dfs(x);
			int p=l,q=r;
			for(int i=l;i<=r;i++)
			    if(col[pdx[i]]==now)
					tdx[p++]=pdx[i];
			    else 
					tdx[q--]=pdx[i];
			for(int i=l;i<=r;i++)
				pdx[i]=tdx[i];
			add_edge(x,y,cut);
			add_edge(y,x,cut);
			_build(l,p-1);
			_build(q+1,r);
		}
		inline void dfs(int u,int la)
		{
		    for(int i=1;i<=8;i++)
		    {
		        fa[i][u]=fa[i-1][fa[i-1][u]];
		        mn[i][u]=std::min(mn[i-1][u],mn[i-1][fa[i-1][u]]);
		    }
		    for(int t=head[u];t;t=edge[t].next)
		    {
		        int v=edge[t].to;
		        if(v==la)
					continue;
		        dep[v]=dep[u]+1;
		        mn[0][v]=edge[t].capa;
		        fa[0][v]=u;
				dfs(v,u);
		    }
		}
	public:
		inline gonorytree():cnt(0),now(0),n(0),cnt2(-1){
			memset(head2,-1,sizeof(head2));
			memset(head,0,sizeof(head));
			memset(pdx,0,sizeof(pdx));
			memset(tdx,0,sizeof(tdx));
			memset(col,0,sizeof(col));
			memset(fa,0,sizeof(fa));
			memset(mn,0,sizeof(mn));
			memset(dep,0,sizeof(dep));
			memset(d,0,sizeof(d));
			memset(cur,0,sizeof(cur));
		}
		inline void insert(int u,int v,T w)
		{
		    edge2[++cnt]=Edge2{v,w,0,head2[u]};
			head2[u]=cnt;
		    edge2[++cnt]=Edge2{u,w,0,head2[v]};
			head2[v]=cnt;
			n=std::max(n,std::max(u,v));
		}
		inline void build()
		{
			for(int i=1;i<=n;i++)
				pdx[i]=i;
    		_build(1,n);
    		dep[1]=1;
			dfs(1,0);
		}
		inline int getcut(int x,int y)
		{
		    int res=INF;
		    if(dep[x]<dep[y])
				std::swap(x,y);
		    for(int i=8;i>=0;i--)
		        if(dep[fa[i][x]]>=dep[y])
		        {
		            res=std::min(res,mn[i][x]);
		            x=fa[i][x];
		        }
		    if(x==y)
				return res;
		    for(int i=8;i>=0;i--)
		        if(fa[i][x]!=fa[i][y])
		        {
		            res=std::min(res,mn[i][x]);
		            res=std::min(res,mn[i][y]);
		            x=fa[i][x];
					y=fa[i][y];
		        }
		    res=std::min(res,std::min(mn[0][x],mn[0][y]));
		    return res;
		}
};
int main()
{

}
