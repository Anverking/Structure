/*�������(Difference Array)ģ��*/
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
		/*���캯��:�Գ���Ϊn������a����������.
		ʱ�临�Ӷ�:O(n). 
		*/
		{
			diff[0]=a[0];
			size=n;
			for(int i=1;i<n;i++)
				diff[i]=a[i]-a[i-1];
		}
		inline void update(int l,int r,T k)
		/*���ĺ���:��һ������[l,r]����k.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			diff[l]+=k;
			if(r<size)
				diff[r+1]-=k;
		}
		inline void modify(int i,T k)
		/*���ĺ���:����i��Ԫ�ؼ���k.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			update(i,i,k);
		}
		inline T operator[](const int i)
		/*��ֵ����:���i��Ԫ�ص�ֵ.
		ʱ�临�Ӷ�:O(n). 
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
