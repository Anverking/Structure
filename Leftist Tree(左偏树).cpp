/*左偏树(Leftist Tree)模板*/
#include<iostream>
#include<cstring>
const int maxn=1e4;
template<class T>
class leftist{
	private:
		T value[maxn];
		int left[maxn],right[maxn],dist[maxn];
		int cnt;
	public:
		inline leftist():cnt(0)
		/*构造函数:建造一棵空树.
		时间复杂度:O(1). 
		*/
		{
			memset(left,0,sizeof(left));
			memset(right,0,sizeof(right));
			memset(dist,0,sizeof(dist));
		}
		inline void merge(int&x,int y)
		/*合并函数:合并以x为根的树与以y为根的树.
		时间复杂度:O(log2 n). 
		*/
		{
			if(!x||!y)
				return x|y;
			if(value[x]>value[y])
				std::swap(x,y);
			right[x]=merge(right[x],y);
			if(dist[left[x]]<dist[right[x]])
				std::swap(left[x],right[x]);
			dist[x]=dist[right[x]]+1;
		}
		inline int creat(T v)
		/*建造函数:新建一个节点.
		时间复杂度:O(1). 
		*/
		{
			cnt++;
			value[cnt]=v;
			left[cnt]=right[cnt]=dist[cnt]=0;
			return cnt;
		}
		inline void push(int&x,T v)
		/*插入函数:往以x为根的树中插入一个元素.
		时间复杂度:O(log2 n). 
		*/ 
		{
			x=merge(x,creat(v));
		}
		inline void pop(int&x)
		/*删除函数:删除x号节点.
		时间复杂度:O(log2 n). 
		*/ 
		{
			x=merge(left[x],right[x]);
		}
		inline void modify(int&i,T x)
		{
			pop(i);
			push(i,x);
		} 
		inline T top(int x)
		/*求值函数:求以x为根的树中的元素最小值.
		时间复杂度:O(1). 
		*/
		{
			return value[x];
		}
		inline void clear()
		/*清空函数:清空所有的树.
		时间复杂度:O(1). 
		*/
		{
			cnt=0;
			memset(left,0,sizeof(left));
			memset(right,0,sizeof(right));
			memset(dist,0,sizeof(dist));
		}
};
int main(){

}
