/*闭哈希表(Closing Hash Table)模板*/
#include<iostream>
#include<cstring>
const int maxn=1e4;
typedef unsigned long long ULL;
inline ULL myhash(int x)
{
	return ((((x*x+1)^(x+1))&x)+(x&1))%maxn; 
} 
inline ULL myfind(ULL i)
{
	return (i^(i&(1+i*i)))+1;
}
template<class T,ULL(hash)(T)=myhash,ULL(address)(ULL)=myfind>
class closehash{
	private:
		T table[maxn];
		bool vis[maxn];
	public:
		inline closehash()
		/*构造函数:构造一个空哈希表.
		时间复杂度:O(1). 
		*/
		{
			memset(vis,0,sizeof(vis));
		}
	
		inline void clear()
		/*清空函数:清空哈希表.
		时间复杂度:O(1). 
		*/
		{
			memset(vis,0,sizeof(vis));
		}
		inline void insert(T v)
		/*插入函数:在表中插入v.
		时间复杂度:O(1). 
		*/
		{
			ULL h=hash(v);
			if(!vis[h])
			{
				table[h]=v;
				vis[h]=1;
				return;
			}
			while(vis[h])
				h=address(h);
			table[h]=v;
			vis[h]=1;
		}
		inline void remove(T v)
		/*删除函数:在表中删除v.
		时间复杂度:O(1). 
		*/
		{
			ULL h=hash(v);
			if(table[h]==v){
				vis[h]=0;
				return;
			}
			while(table[h]!=v)
				h=address(h);
			vis[h]=0;
		}
};
int main(){
	
}
