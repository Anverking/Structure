#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
const int maxn=1e3;
template<class T>
class bintree{
	private:
		class node{
			public:
				int father;
				std::vector<int>son;
				T value;
				inline node():father(0){}
		}tree[maxn];
		int cnt;
	public:
		inline bintree():cnt(0){}
		inline int creat(T v)
		{
			tree[++cnt].value=v;
			return cnt;
		}
		inline void clear()
		{
			cnt=0;
		}
		inline void insert(int u,int v)
		{
			tree[v].father=u;
			tree[u].son.push_back(v);
		}
		inline T& operator[](const int i)
		{
			return tree[i].value;	
		}
		inline int root(int x)
		{
			int a=x;
			while(tree[a].father)
				a=tree[a].father;
			return a;
		}
		inline int deep(int x)
		{
			int d=0,a=x;
			while(tree[a].father)
				a=tree[a].father,
				d++;
			return d;
		}
		inline void pre_dfs(int s,std::vector<int>&v)
		{
			v.push_back(s);
			for(int i=0;i<tree[s].son.size();i++)
				dfs(tree[s].son[i]);
		}
		inline void suf_dfs(int s,std::vector<int>&v)
		{
			for(int i=0;i<tree[s].son.size();i++)
				dfs(tree[s].son[i]);
			v.push_back(s);
		}
		inline void bfs(int s,std::vector<int>&v)
		{
			std::queue<int>q;
			q.push(s);
			while(!q.empty())
			{
				int f=q.front();
				q.pop();
				v.push_back(f);
				for(int i=0;i<tree[f].son.size();i++)
					q.push(tree[f].son[i]);		
			}
		}
		inline int query_lca(int a,int b)
		{
			int i=deep(a),j=deep(b);
			while(i>j)
				a=tree[a].father,
				i--;
			while(j>i)
				b=tree[b].father,
				j--;
			while(a!=b)
				a=tree[a].father,
				b=tree[b].father;
			return a;
		}
};
int main()
{
	
} 
