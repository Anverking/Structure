/*��Ȩ���鼯(Disjoint Set)ģ��*/
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
		/*���캯��:����һ���յļ���.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			memset(father,0,sizeof(father));
			memset(dist,0,sizeof(dist));
			memset(size,0,sizeof(size));
		}
		inline int creat()
		/*���캯��:����һ���µĶ���Ԫ��.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			cnt++;
			father[cnt]=cnt;
			dist[cnt]=0;
			size[cnt]=1;
			return cnt;
		}
		inline int operator[](const int i)
		/*��ֵ����:��i��ֵ.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			return dist[i];
		}
		inline void build(int n)
		/*���캯��:����һ����n��Ԫ�صļ���.
		ʱ�临�Ӷ�:O(n). 
		*/
		{
			for(int i=1;i<=n;i++){
				father[i]=i;
				dist[i]=0;
				size[i]=1;
			}
		}
		inline int find(int x)
		/*���Һ���:��x���ڼ��ϵĴ���.
		ʱ�临�Ӷ�:O(1). 
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
		/*�ϲ�����:����ʽ�ϲ�a��b���ڵļ���.
		ʱ�临�Ӷ�:O(1). 
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
