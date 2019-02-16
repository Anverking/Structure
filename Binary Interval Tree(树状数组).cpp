/*��״����(Binary Interval Tree)ģ��*/
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
		/*���캯��:����һ�ÿ���.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			memset(tree,0,sizeof(tree));
		}
		inline void build(int n)
		/*���캯��:����״����ĳ�������Ϊn.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			size=n;
		}
		inline void update(int x,T num)
		/*���ĺ���:����x��������num.
		ʱ�临�Ӷ�:O(log2 n). 
		*/
		{
    		while(x<=size){
        		tree[x]+=num;
        		x+=(x)&(-x);
    		}
		}
		inline T query_sum(int l,int r)
		/*��ֵ����:������[l,r]�ĺ�.
		ʱ�临�Ӷ�:O(log2 n). 
		*/
		{
			if(l==0)
				return pre_sum(r+1);
			return pre_sum(r+1)-pre_sum(l);
		}
		inline T operator[](const int i)
		/*��ֵ����:���i��Ԫ�ص�ֵ.
		ʱ�临�Ӷ�:O(log2 n). 
		*/
		{
			return query_sum(i,i);
		}
		inline void clear()
		/*��պ���:���������.
		ʱ�临�Ӷ�:O(1).  
		*/
		{
			memset(tree,0,sizeof(tree));
			size=0;
		}
};
int main(){

}
