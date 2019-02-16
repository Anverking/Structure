/*邻接表(Adjacency List)模板*/
#include<iostream>
#include<map>
#include<queue>
#include<vector>
const int maxn=1e4;
template<class T>
class adjlist{
	private:
		class node{
			public:
				std::vector<std::pair<int,T> >Edge;
		}List[maxn];
	public:
		class edge
		/*边类.*/
		{
			public:
				int from,to;
				T value;
				inline edge(){}
				inline edge(int u,int v,T w):from(u),to(v),value(w){}
		};
		inline adjlist(){}
		inline void clear()
		/*清空函数:清空整个图.
		时间复杂度:O(n). 
		*/
		{
			for(int i=0;i<maxn;i++)
				List[i].Edge.clear();
		}
		inline void insert(int u,int v,T w)
		/*插入函数:插入一条u到v的权值为w的边.
		时间复杂度:O(1). 
		*/
		{
			List[u].Edge.push_back(make_pair(v,w));
		}
		inline edge operator()(int u,int v)
		/*求值函数:求u到v边的值.
		时间复杂度:O(n). 
		*/
		{
			for(int i=0;i<List[u].edge.size();i++)
				if(List[u].Edge[i].first==v)
					return edge(u,v,List[u].Edge[i].second);
		}
		inline void dfs(int s,std::vector<edge>&v)
		/*遍历函数:以深度优先顺序从s开始遍历图,
		并将遍历到的边按次序存到v中.
		时间复杂度:O(m).
		*/
		{
			for(int i=0;i<List[s].Edge.size();i++)
			{
				dfs(List[s].Edge[i].first);
				v.push_back(edge(
				s,List[s].Edge[i].first,
				List[s].Edge[i].second
				));
			}
		}
		inline void bfs(int s,std::vector<edge>&v)
		/*遍历函数:以广度优先顺序从s开始遍历图,
		并将遍历到的边按次序存到v中.
		时间复杂度:O(m).
		*/
		{
			std::queue<int>q;
			q.push(s);
			while(!q.empty()){
				int head=q.front();
				q.pop();
				for(int i=0;i<List[head].Edge.size();i++)
				{
					q.push(List[head].Edge[i].first);
					v.push_back(edge(
					head,List[s].Edge[i].first,
					List.Edge[i].second
					));
				}
			}
		}
}; 
int main(){
	
}
