#include<iostream>
#include<cstring>
const int maxn=1e4;
class cactus{
	private:
		int cnt,ind,ans;
		int head[maxn],deep[maxn],DP[maxn];
		int low[maxn],dfn[maxn],father[maxn];
		int arr[maxn<<1],que[maxn<<1],left,right;
		class edge{
			public:
				int to,next;
		}Edge[maxn*maxn];
		inline void dp(int root,int x)
		{
			int tot=deep[x]-deep[root]+1;
			for(int i=x;i!=root;i=father[i])
				arr[tot--]=DP[i];
			arr[tot]=DP[root];
			tot=deep[x]-deep[root]+1;
			for(int i=1;i<=tot;i++)
				arr[i+tot]=arr[i];
			que[1]=1;
			left=right=1;
			for(int i=2;i<=2*tot;i++)
			{
				while(left<=right&&i-que[left]>tot/2)
					left++;
				ans=std::max(ans,arr[i]+i+arr[que[left]]-que[left]);
				while(left<=right&&arr[que[right]]-
				que[right]<=arr[i]-i)
				right--;
				que[++right]=i;
			}
			for(int i=2;i<=tot;i++)
				DP[root]=std::max(DP[root],
				arr[i]+std::min(i-1,tot-i+1));
		}
		inline void dfs(int x)
		{
			low[x]=dfn[x]=++ind;
			for(int i=head[x];i;i=Edge[i].next)
				if(Edge[i].to!=father[x])
				{
					if(!dfn[Edge[i].to])
					{
						father[Edge[i].to]=x;
						deep[Edge[i].to]=deep[x]+1;
						dfs(Edge[i].to);
						low[x]=std::min(low[x],low[Edge[i].to]);
					}
					else 
						low[x]=std::min(low[x],dfn[Edge[i].to]);
					if(dfn[x]<low[Edge[i].to])
					{
						ans=std::max(ans,DP[x]+DP[Edge[i].to]+1);
						DP[x]=std::max(DP[x],DP[Edge[i].to]+1);
					}
				}
			for(int i=head[x];i;i=Edge[i].next)
				if(father[Edge[i].to]!=x&&dfn[x]<dfn[Edge[i].to])
					dp(x,Edge[i].to);
		}
	public:
		inline cactus():cnt(0),ind(0),ans(0)
		{
			memset(head,0,sizeof(head));
			memset(deep,0,sizeof(deep));
			memset(DP,0,sizeof(DP));
			memset(low,0,sizeof(low));
			memset(dfn,0,sizeof(dfn));
			memset(father,0,sizeof(father));
			memset(arr,0,sizeof(arr));
			memset(que,0,sizeof(que));
		}
		inline void insert(int u,int v)
		{
			Edge[++cnt].to=v;
			Edge[cnt].next=head[u];
			head[u]=cnt;
			Edge[++cnt].to=u;
			Edge[cnt].next=head[v];
			head[v]=cnt;
		}
		inline void clear()
		{
			cnt=ind=ans=0;
			memset(head,0,sizeof(head));
			memset(deep,0,sizeof(deep));
			memset(DP,0,sizeof(DP));
			memset(low,0,sizeof(low));
			memset(dfn,0,sizeof(dfn));
			memset(father,0,sizeof(father));
			memset(arr,0,sizeof(arr));
			memset(que,0,sizeof(que));
		} 
		inline int query()
		{
			ans=0;
			dfs(1);
			return ans;
		}
};
int main()
{
	
}
