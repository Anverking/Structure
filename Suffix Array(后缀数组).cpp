/*后缀数组(Suffix Array)模板*/
#include<iostream>
#include<cstring>
const int maxn=1e4;
class sufarray{
	private:
		int sufa[maxn],het[maxn];
		inline void radix(int*str,int*a,int*b,int n,int m){
			int count[maxn];
			memset(count,0,sizeof(count));
			for(int i=0;i<n;i++)
				count[str[a[i]]]++;
			for(int i=1;i<=m;i++)
				count[i]+=count[i-1];
			for(int i=n-1;i>=0;i--)
				b[--count[str[a[i]]]]=a[i];
		}
		inline void suffixa(int*str,int*sa,int n,int m){
			int rank[maxn],a[maxn],b[maxn];
			memset(rank,0,sizeof(rank));
			memset(a,0,sizeof(a));
			memset(b,0,sizeof(b));
			for(int i=0;i<n;i++)
				rank[i]=i;
			radix(str,rank,sa,n,m);
			rank[sa[0]]=0;
			for(int i=1;i<n;i++)
				rank[sa[i]]=rank[sa[i-1]]+
				(str[sa[i]]!=str[sa[i-1]]);
			for(int i=0;(1<<i)<n;i++){
				for(int j=0;j<n;j++)
				{
					a[j]=rank[j]+1;
					b[j]=j+(1<<i)>=n?0:rank[j+(1<<i)]+1;
					sa[j]=j;
				}
			}
			radix(b,sa,rank,n,n);
			radix(a,rank,sa,n,n);
			rank[sa[0]]=0;
			for(int j=1;j<n;j++){
				rank[sa[j]]=rank[sa[j-1]]+
				(a[sa[j-1]]!=a[sa[j]]||b[sa[j-1]]!=b[sa[j]]);
			}
		}
		inline void calc(int*str,int*sa,int*h,int n){
			int rank[maxn];
			memset(rank,0,sizeof(rank));
			int k=0;
			h[0]=0;
			for(int i=0;i<n;i++)
				rank[sa[i]]=i;
			for(int i=0;i<n;i++)
			{
				k=k==0?0:k-1;
				if(rank[i]!=0)
					while(str[i+k]==str[sa[rank[i]-1]+k])
						k++;
				h[rank[i]]=k;
			}
		}
		public:
			inline sufarray()
			/*构造函数:初始化数组.
			时间复杂度:O(1). 
			*/
			{
				memset(sufa,0,sizeof(sufa));
				memset(het,0,sizeof(het));
			}
			inline void build(const char*str)
			/*建造函数:以字符串str建造后缀数组.
			时间复杂度:O(n). 
			*/
			{
				int m=0,i;
				int s[maxn];
				for(i=0;str[i];i++)
					m=std::max((int)str[i],m),
					s[i]=str[i];
				suffixa(s,sufa,i,m);
				calc(s,sufa,het,i);
			}
			inline int query(int i,int j)
			/*求值函数:求str的长度为i的后缀与长度为j的
			最长公共前缀的长度.
			时间复杂度:O(n). 
			*/
			{
				int ans=maxn+5;
				if(sufa[i]>sufa[j])
					std::swap(i,j);
				int k=1;
				while(k!=sufa[j])
				{
					ans=std::min(sufa[i]+k,ans);
					k++;
				}
				ans=std::min(sufa[j],ans);
				return ans;
			}
};
int main(){

}
