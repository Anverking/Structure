/*带权并查集(Disjoint Set)模板*/
#include<iostream>
#include<cstring>
const int maxn=1e4;
class diset{
	private:
		int father[maxn];
		int dist[maxn];
		int size[maxn];
		int cnt;
	public:
		inline diset():cnt(0)
		/*构造函数:构造一个空的集合.
		时间复杂度:O(1). 
		*/
		{
			memset(father,0,sizeof(father));
			memset(dist,0,sizeof(dist));
			memset(size,0,sizeof(size));
		}
		inline int creat()
		/*建造函数:建造一个新的独立元素.
		时间复杂度:O(1). 
		*/
		{
			cnt++;
			father[cnt]=cnt;
			dist[cnt]=0;
			size[cnt]=1;
			return cnt;
		}
		inline int operator[](const int i)
		/*求值函数:求i的值.
		时间复杂度:O(1). 
		*/
		{
			return dist[i];
		}
		inline void build(int n)
		/*建造函数:建造一个有n个元素的集合.
		时间复杂度:O(n). 
		*/
		{
			for(int i=1;i<=n;i++){
				father[i]=i;
				dist[i]=0;
				size[i]=1;
			}
		}
		inline int find(int x)
		/*查找函数:求x所在集合的代表.
		时间复杂度:O(1). 
		*/
		{
			if(father[x]==x)
				return x;
			int y=father[x];
			father[x]=find(y);
			dist[x]+=dist[y];
			return father[x];
		}
		inline void merge(int a,int b)
		/*合并函数:启发式合并a与b所在的集合.
		时间复杂度:O(1). 
		*/
		{
			a=find(a);
			b=find(b);
			if(a!=b){
				if(size[b]>size[a]){
					father[a]=b;
					dist[a]=size[b];
					size[b]+=size[a];
				}
				else{
					father[b]=a;
					dist[b]=size[a];
					size[a]+=size[b];
				} 
			}
		}
};
int main(){
	
}
