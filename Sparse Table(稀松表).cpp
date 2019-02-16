/*ϡ�ɱ�(Sparse Table)ģ��*/
#include<iostream>
#include<cstring>
const int maxn=1e3;
template<class T>
class st_table{
	private:
		T stmin[maxn][33],stmax[maxn][33];
		int pre[maxn];
	public:
		inline st_table()
		/*���캯��:��ʼ��ST��.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			memset(pre,0,sizeof(pre));
			memset(stmin,0,sizeof(stmin));
			memset(stmax,0,sizeof(stmax));
		}
		inline void build(T*a,int n)
		/*���캯��:�����Գ���Ϊn������a����ST��.
		ʱ�临�Ӷ�:O(nlog2 n). 
		*/
		{
			pre[1]=0;
			for(int i=2;i<=n;i++){
				pre[i]=pre[i-1];
				if((1<<pre[i]+1)==i)
				++pre[i];
			}
			for(int i=n-1;i>=0;i--){
				stmin[i][0]=stmax[i][0]=a[i];
				for(int j=1;(i+(1<<j)-1)<n;j++){
					stmin[i][j]=
					std::min(
					stmin[i][j-1],
					stmin[i+(1<<j-1)][j-1]
					);
					stmax[i][j]=
					std::max(
					stmax[i][j-1],
					stmax[i+(1<<j-1)][j-1]
					);
				}
			}
		}
		inline T query_min(int l,int r)
		/*��ֵ����:��ѯһ�������е���Сֵ.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			int len=r-l+1,k=pre[len];
			return std::min(stmin[l][k],stmin[r-(1<<k)+1][k]);
		}
		inline T query_max(int l,int r)
		/*��ֵ����:��ѯһ�������е����ֵ.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			int len=r-l+1,k=pre[len];
			return std::max(stmax[l][k],stmax[r-(1<<k)+1][k]);
		}
};
int main(){

}
