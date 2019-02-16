/*前缀和数组(Prefix Sum Array)模板*/
#include<iostream>
const int maxn=1e4;
template<class T>
class presum{
	private:
		T sum[maxn];
	public:
		inline presum(){}
		inline void build(T*a,int n)
		/*建造函数:对长度为n的数组a建造前缀和数组.
		时间复杂度:O(n). 
		*/
		{
			sum[0]=a[0];
			for(int i=1;i<n;i++)
				sum[i]=sum[i-1]+a[i]; 
		} 
		inline T query_sum(int l,int r)
		/*求值函数:求一段区间[l,r]的和.
		时间复杂度:O(1). 
		*/
		{
			if(l)
				return sum[r]-sum[l-1];
			else
				return sum[r];
		}
		inline T operator[](const int i)
		/*求值函数:求第i个元素的值.
		时间复杂度:O(1). 
		*/
		{
			return query_sum(i);
		}
};
int main()
{

}
