/*�ڽӱ�(Adjacency List)ģ��*/
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
		/*����.*/
		{
			public:
				int from,to;
				T value;
				inline edge(){}
				inline edge(int u,int v,T w):from(u),to(v),value(w){}
		};
		inline adjlist(){}
		inline void clear()
		/*��պ���:�������ͼ.
		ʱ�临�Ӷ�:O(n). 
		*/
		{
			for(int i=0;i<maxn;i++)
				List[i].Edge.clear();
		}
		inline void insert(int u,int v,T w)
		/*���뺯��:����һ��u��v��ȨֵΪw�ı�.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			List[u].Edge.push_back(make_pair(v,w));
		}
		inline edge operator()(int u,int v)
		/*��ֵ����:��u��v�ߵ�ֵ.
		ʱ�临�Ӷ�:O(n). 
		*/
		{
			for(int i=0;i<List[u].edge.size();i++)
				if(List[u].Edge[i].first==v)
					return edge(u,v,List[u].Edge[i].second);
		}
		inline void dfs(int s,std::vector<edge>&v)
		/*��������:���������˳���s��ʼ����ͼ,
		�����������ı߰�����浽v��.
		ʱ�临�Ӷ�:O(m).
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
		/*��������:�Թ������˳���s��ʼ����ͼ,
		�����������ı߰�����浽v��.
		ʱ�临�Ӷ�:O(m).
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
