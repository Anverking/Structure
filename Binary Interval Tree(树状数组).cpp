/*树状数组(Binary Interval Tree)模板*/
#include<iostream>
#include<cstring>
const int maxn=1e4;
template<class T>
class bitree{
	private:
		T tree[maxn<<2];
		int size;
		inline T pre_sum(int x){
			T sum=0;
			while(x){
				sum+=tree[x];
				x-=(x)&(-x);
			}
			return sum;
		}
	public:
		inline bitree():size(0) 
		/*构造函数:建造一棵空树.
		时间复杂度:O(1). 
		*/
		{
			memset(tree,0,sizeof(tree));
		}
		inline void build(int n)
		/*建造函数:将树状数组的长度设置为n.
		时间复杂度:O(1). 
		*/
		{
			size=n;
		}
		inline void update(int x,T num)
		/*更改函数:将第x个数加上num.
		时间复杂度:O(log2 n). 
		*/
		{
    		while(x<=size){
        		tree[x]+=num;
        		x+=(x)&(-x);
    		}
		}
		inline T query_sum(int l,int r)
		/*求值函数:求区间[l,r]的和.
		时间复杂度:O(log2 n). 
		*/
		{
			if(l==0)
				return pre_sum(r+1);
			return pre_sum(r+1)-pre_sum(l);
		}
		inline T operator[](const int i)
		/*求值函数:求第i个元素的值.
		时间复杂度:O(log2 n). 
		*/
		{
			return query_sum(i,i);
		}
		inline void clear()
		/*清空函数:清空整棵树.
		时间复杂度:O(1).  
		*/
		{
			memset(tree,0,sizeof(tree));
			size=0;
		}
};
int main(){

}
