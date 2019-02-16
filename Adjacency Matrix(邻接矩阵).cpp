/*�ڽӾ���(Adjacency Matrix)ģ��*/
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
		/*���캯��:����һ���յ�ͼ.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			memset(vis,0,sizeof(vis));
		}
		inline void clear()
		/*��պ���:�������ͼ.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			memset(vis,0,sizeof(vis));
		}
		inline void insert(int u,int v,T w)
		/*���뺯��:����һ��u��v��ȨֵΪw�ı�.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			graph[u][v]=w;
			vis[u][v]=1;
		}
		inline T operator()(int u,int v)
		/*��ֵ����:��u��v�ı�Ȩ.
		��u��vû�б�,����0.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			return vis[u][v]*graph[u][v];
		}
};
int main(){
	
}
