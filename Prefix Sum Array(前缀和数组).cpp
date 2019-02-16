/*ǰ׺������(Prefix Sum Array)ģ��*/
#include<iostream>
const int maxn=1e4;
template<class T>
class presum{
	private:
		T sum[maxn];
	public:
		inline presum(){}
		inline void build(T*a,int n)
		/*���캯��:�Գ���Ϊn������a����ǰ׺������.
		ʱ�临�Ӷ�:O(n). 
		*/
		{
			sum[0]=a[0];
			for(int i=1;i<n;i++)
				sum[i]=sum[i-1]+a[i]; 
		} 
		inline T query_sum(int l,int r)
		/*��ֵ����:��һ������[l,r]�ĺ�.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			if(l)
				return sum[r]-sum[l-1];
			else
				return sum[r];
		}
		inline T operator[](const int i)
		/*��ֵ����:���i��Ԫ�ص�ֵ.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			return query_sum(i);
		}
};
int main()
{

}
