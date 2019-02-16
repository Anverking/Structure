/*差分数组(Difference Array)模板*/
#include<iostream>
#include<cstring>
const int maxn=1e4;
template<class T>
class difference{
	private:
		T diff[maxn];
		int size;
	public:
		inline difference():size(0){}
		inline void build(T*a,int n)
		/*建造函数:以长度为n的数组a建造差分数组.
		时间复杂度:O(n). 
		*/
		{
			diff[0]=a[0];
			size=n;
			for(int i=1;i<n;i++)
				diff[i]=a[i]-a[i-1];
		}
		inline void update(int l,int r,T k)
		/*更改函数:将一段区间[l,r]加上k.
		时间复杂度:O(1). 
		*/
		{
			diff[l]+=k;
			if(r<size)
				diff[r+1]-=k;
		}
		inline void modify(int i,T k)
		/*更改函数:将第i个元素加上k.
		时间复杂度:O(1). 
		*/
		{
			update(i,i,k);
		}
		inline T operator[](const int i)
		/*求值函数:求第i个元素的值.
		时间复杂度:O(n). 
		*/
		{
			if(i>=size)	
				return 0;
			T s=diff[0];
			for(int j=1;j<=i;j++)
				s+=diff[j];
			return s;
		}
}; 
int main()
{

}
