/*��Ԫ��(Three Membered Ring)ģ��*/
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
		/*���캯��:����һ����ͼ.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			memset(deg,0,sizeof(deg));
			memset(vis,0,sizeof(vis));
		} 
		inline void insert(int u,int v)
		/*���뺯��:����һ��u��v�������.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			cnt++;
			Edge[cnt].from=u;
			Edge[cnt].to=v;
			deg[Edge[cnt].from]++,
			deg[Edge[cnt].to]++;
		}
		inline int query()
		/*��ֵ����:ͳ��ͼ���ж��ٸ���Ԫ��.
		ʱ�临�Ӷ�:O(m*sqrt(m)). 
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
		/*��պ���:���ͼ.
		ʱ�临�Ӷ�:O(1). 
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
