/*优先队列(Priority Queue)模板*/
#include<iostream>
#include<cstring>
const int maxn=1e4;
const int INF=0x3f3f3f3f; 
template<class T> 
class prioque{
	private:
		T heap[maxn];
		int idx[maxn],pos[maxn],cnt,len;
		inline void up(int i){
			T x=heap[i];
			int y=idx[i];
			for(int j=i/2;j>=1;j/=2){
				if(heap[j]>x){
					heap[i]=heap[j];
					idx[i]=idx[j];
					pos[idx[i]]=i;
					i=j;
				}
				else 
					break;
			}
			heap[i]=x;
			idx[i]=y;
			pos[y]=i;
		}
		inline void down(int i){
			T x=heap[i];
			int y=idx[i];
			for(int j=i*2;j<=len;j*=2){
				j+=(j<len&&heap[j]>heap[j+1]);
				if(heap[j]<x){
					heap[i]=heap[j];
					idx[i]=idx[j];
					pos[idx[i]]=i;
					i=j;
				}
				else 
					break;
			}
			heap[i]=x;
			idx[i]=y;
			pos[y]=i;
		}
	public:
		inline prioque():cnt(0),len(0)
		/*构造函数:建造一个空的队列.
		时间复杂度:O(1). 
		*/
		{
			memset(idx,0,sizeof(idx));
			memset(pos,0,sizeof(pos));
		}
		inline void push(T v)
		/*插入函数:往队尾插入一个元素.
		时间复杂度:O(log2 n). 
		*/
		{
			heap[++len]=v;
			idx[len]=++cnt;
			pos[idx[len]]=len;
			up(len);
		}
		inline T top()
		/*求值函数:求队列中最小的元素.
		时间复杂度:O(1). 
		*/
		{
			return heap[1];
		}
		inline int pop()
		/*删除函数:删除最小元素,并返回其在原队列中的位置编号.
		时间复杂度:O(log2 n). 
		*/
		{
			std::swap(heap[1],heap[len]);
			std::swap(idx[1],idx[len--]);
			pos[idx[1]]=1;
			down(1);
			return idx[len+1]-1;
		}
		inline T operator[](const int i)
		/*求值函数:求在原队列中的第i个元素.
		时间复杂度:O(1). 
		*/
		{
			return heap[pos[i+1]];
		}
		inline void modify(int i,T v)
		/*更改函数:将在原队列中的第i个元素的值改为v.
		时间复杂度:O(log2 n). 
		*/
		{
			heap[pos[i+1]]=v;
			down(pos[i+1]);
			up(pos[i+1]);
		}
		inline void remove(int i)
		/*删除函数:删除在原队列中的第i个元素.
		时间复杂度:O(log2 n). 
		*/
		{
			heap[pos[i+1]]=-INF;
			up(pos[i+1]);
			pop();
		}
		inline bool empty()
		/*判断函数:判断队列是否为空.
		时间复杂度:O(1). 
		*/
		{
			return !len;
		}
		inline int size()
		/*求值函数:求队列的长.
		时间复杂度:O(1). 
		*/
		{
			return len;
		}
		inline void clear()
		/*清空函数:清空队列.
		时间复杂度:O(1). 
		*/
		{
			cnt=len=0;
			memset(idx,0,sizeof(idx));
			memset(pos,0,sizeof(pos));
		}
};
int main(){

}
