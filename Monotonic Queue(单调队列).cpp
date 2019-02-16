/*��������(Monotonic Queue)ģ��*/
#include<iostream>
#include<queue>
#include<cstring>
const int maxn=1e4;
template<class T>
class monque{
	private:
		class node{
			public:
				T value;
				int idx;
		}Q[maxn];
		T ans[maxn];
	public:
		inline monque()
		/*���캯��:����һ���յĶ���.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			memset(Q,0,sizeof(Q));
			memset(ans,0,sizeof(ans));
		}
		inline void build(T*a,int n,int m)
		/*���캯��:�Գ���Ϊn������a����һ������Ϊm�ĵ�������.
		ʱ�临�Ӷ�:O(n). 
		*/ 
		{
			std::deque<node>q;
			for(int i=0;i<n;i++)
				Q[i].value=a[i],
				Q[i].idx=i;	
			ans[0]=0;
			for(int i=1;i<n;i++)
			{
				while(!q.empty()&&q.back().value>=Q[i-1].value)
					q.pop_back();
				q.push_back(Q[i-1]);
				while(q.front().idx<i-m)
					q.pop_front();
				ans[i]=q.front().value;
			}
		}
		inline T query(const int i)
		/*��ֵ����:��i-m��i��Ԫ����Сֵ.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			return ans[i];
		}
};
int main(){
	
}
