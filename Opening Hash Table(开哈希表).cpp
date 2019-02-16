/*开哈希表(Opening Hash Table)模板*/
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
		/*插入函数:在表中插入v.
		时间复杂度:O(1). 
		*/
		{
			table[hash(v)].push_back(v);
		}
		inline void clear()
		/*清空函数:清空哈希表.
		时间复杂度:O(n). 
		*/
		{
			for(int i=0;i<maxn;i++)
				table[i].clear();
		}
		inline bool remove(T v)
		/*删除函数:在表中删除v,并返回是否能删除. 
		时间复杂度:O(1). 
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
		/*查找函数:判断表中是否有v.
		时间复杂度:O(1). 
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
