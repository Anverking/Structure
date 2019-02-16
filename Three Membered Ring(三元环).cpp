/*三元环(Three Membered Ring)模板*/
#include<iostream>
#include<vector> 
#include<cstring>
const int maxn=1e4;
class tring{
	private:
		std::vector<int>adj[maxn];
		int deg[maxn],vis[maxn];
		class edge{
			public:
				int from,to;
		}Edge[maxn*3];
		int cnt;
	public:
		inline tring():cnt(0)
		/*构造函数:建造一个空图.
		时间复杂度:O(1). 
		*/
		{
			memset(deg,0,sizeof(deg));
			memset(vis,0,sizeof(vis));
		} 
		inline void insert(int u,int v)
		/*插入函数:插入一条u到v的有向边.
		时间复杂度:O(1). 
		*/
		{
			cnt++;
			Edge[cnt].from=u;
			Edge[cnt].to=v;
			deg[Edge[cnt].from]++,
			deg[Edge[cnt].to]++;
		}
		inline int query()
		/*求值函数:统计图中有多少个三元环.
		时间复杂度:O(m*sqrt(m)). 
		*/
		{
			int ans=0;
			for(int i=1;i<=cnt;i++)
			{
        		int u=Edge[i].from,v=Edge[i].to;
        		if(deg[u]<deg[v]||
				(deg[u]==deg[v]&&u>v))
					std::swap(u,v);
        		adj[u].push_back(v);
    		}
		    for(int x=1;x<=maxn;x++)
			{
		        for(auto y:adj[x])
					vis[y]=x;
		        for(auto y:adj[x])
		            for(auto z:adj[y])
		                if(vis[z]==x)
		                    ans++;
		    }
		    return ans;
		}
		inline void clear()
		/*清空函数:清空图.
		时间复杂度:O(1). 
		*/
		{
			cnt=0;
			memset(deg,0,sizeof(deg));
			memset(vis,0,sizeof(vis));
			for(auto x:adj)
				x.clear();
		} 
};
int main()
{

}
