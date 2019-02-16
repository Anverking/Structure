/*莫队(Mo's Algorithm)模板*/
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
		/*建造函数:以数组a初始化莫队.
		时间复杂度:O(1). 
		*/
		{
			cnt.clear();
			left=right=ans=0; 
			memcpy(num+1,a,sizeof(a));
		}
		inline void query(int ql,int qr,int id)
		/*求值函数:离线查询第id次询问的答案.
		询问区间[ql,qr]中有多少个不同的数.
		时间复杂度:O(sqrt(n)). 
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
		/*求值函数:询问第i次离线查询的答案.
		时间复杂度:O(1). 
		*/
		{
			return Ans[i];
		}
};
int main(){
	
}
