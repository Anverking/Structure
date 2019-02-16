/*����ϣ��(Opening Hash Table)ģ��*/
#include<iostream>
#include<list>
const int maxn=1e4;
typedef unsigned long long ULL;
inline ULL myhash(int x)
{
	return ((((x*x+1)^(x+1))&x)+(x&1))%maxn; 
} 
template<class T,ULL(hash)(T)=myhash>
class openhash{
	private:
		std::list<T>table[maxn];
	public:
		inline openhash(){}
		inline void insert(T v)
		/*���뺯��:�ڱ��в���v.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			table[hash(v)].push_back(v);
		}
		inline void clear()
		/*��պ���:��չ�ϣ��.
		ʱ�临�Ӷ�:O(n). 
		*/
		{
			for(int i=0;i<maxn;i++)
				table[i].clear();
		}
		inline bool remove(T v)
		/*ɾ������:�ڱ���ɾ��v,�������Ƿ���ɾ��. 
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			typename std::list<T>::iterator it=table[hash(v)].begin();
			for(;it!=table[hash(v)].end();it++)
			{
				if(*it==v)
				{
					table[hash(v)].erase(it);
					return 1;
				}
			}
			return 0;
		}
		inline bool find(T v)
		/*���Һ���:�жϱ����Ƿ���v.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			typename std::list<T>::iterator it=table[hash(v)].begin();
			for(;it!=table[hash(v)].end();it++)
				if(*it==v)
					return 1;
			return 0;
		}
};
int main(){

}
