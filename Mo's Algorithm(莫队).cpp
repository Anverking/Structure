/*Ī��(Mo's Algorithm)ģ��*/
#include<iostream>
#include<cmath>
#include<map>
#include<algorithm>
const int maxn=1e4;
template<class T>
class mosalgo{
	private:
		int left,right,ans;
		T num[maxn];
		std::map<T,unsigned int>cnt;
		int Ans[maxn];
		inline void insert(int x){
	    	if(!cnt[num[x]])
				ans++;
	    	cnt[num[x]]++;
		}
		inline void remove(int x){
	    	cnt[num[x]]--;
	    	if(!cnt[num[x]])
				ans--;
		}
	public:
		inline mosalgo(){}
		inline void build(T*a)
		/*���캯��:������a��ʼ��Ī��.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			cnt.clear();
			left=right=ans=0; 
			memcpy(num+1,a,sizeof(a));
		}
		inline void query(int ql,int qr,int id)
		/*��ֵ����:���߲�ѯ��id��ѯ�ʵĴ�.
		ѯ������[ql,qr]���ж��ٸ���ͬ����.
		ʱ�临�Ӷ�:O(sqrt(n)). 
		*/
		{
			while(left<ql)
				remove(left++);
	        while(left>ql)
				insert(--left);
	        while(right<qr)
				insert(++right);
	        while(right>qr)
				remove(right--);
	        Ans[id]=ans;
		}
		inline int getans(const int i)
		/*��ֵ����:ѯ�ʵ�i�����߲�ѯ�Ĵ�.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			return Ans[i];
		}
};
int main(){
	
}
