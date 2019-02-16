/*稀松表(Sparse Table)模板*/
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
		/*构造函数:初始化ST表.
		时间复杂度:O(1). 
		*/
		{
			memset(pre,0,sizeof(pre));
			memset(stmin,0,sizeof(stmin));
			memset(stmax,0,sizeof(stmax));
		}
		inline void build(T*a,int n)
		/*建造函数:建造以长度为n的数组a建造ST表.
		时间复杂度:O(nlog2 n). 
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
		/*求值函数:查询一段区间中的最小值.
		时间复杂度:O(1). 
		*/
		{
			int len=r-l+1,k=pre[len];
			return std::min(stmin[l][k],stmin[r-(1<<k)+1][k]);
		}
		inline T query_max(int l,int r)
		/*求值函数:查询一段区间中的最大值.
		时间复杂度:O(1). 
		*/
		{
			int len=r-l+1,k=pre[len];
			return std::max(stmax[l][k],stmax[r-(1<<k)+1][k]);
		}
};
int main(){

}
