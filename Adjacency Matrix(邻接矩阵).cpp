/*邻接矩阵(Adjacency Matrix)模板*/
#include<iostream>
#include<cstring>
const int maxn=1e3;
template<class T>
class adjmat{
	private:
		T graph[maxn][maxn];
		bool vis[maxn][maxn];
	public:
		inline adjmat()
		/*构造函数:构造一个空的图.
		时间复杂度:O(1). 
		*/
		{
			memset(vis,0,sizeof(vis));
		}
		inline void clear()
		/*清空函数:清空整个图.
		时间复杂度:O(1). 
		*/
		{
			memset(vis,0,sizeof(vis));
		}
		inline void insert(int u,int v,T w)
		/*插入函数:插入一条u到v的权值为w的边.
		时间复杂度:O(1). 
		*/
		{
			graph[u][v]=w;
			vis[u][v]=1;
		}
		inline T operator()(int u,int v)
		/*求值函数:求u到v的边权.
		若u到v没有边,返回0.
		时间复杂度:O(1). 
		*/
		{
			return vis[u][v]*graph[u][v];
		}
};
int main(){
	
}
