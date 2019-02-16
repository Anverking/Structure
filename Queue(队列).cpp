/*队列(Queue)模板*/
#include<iostream>
#include<cstring>
const int maxn=1e5;
template<class T>
class queue{
	private:
		T List[maxn];
		int head,tail;
	public:
		inline queue():head(1),tail(0)
		/*构造函数:建造一个空的队列.
		时间复杂度:O(1). 
		*/
		{
			memset(List,0,sizeof(List));
		}
		inline void push(T v)
		/*插入函数:在队尾插入一个元素.
		时间复杂度:O(1). 
		*/
		{
			List[++tail]=v;
		}
		inline void pop()
		/*删除函数:弹出队首的元素.
		时间复杂度:O(1). 
		*/
		{
			if(empty())
				return;
			head++;
		}
		inline T& front()
		/*求值函数:求队首元素.
		时间复杂度:O(1). 
		*/
		{
			if(empty())
				return 0;
			return List[head];
		}
		inline T& back()
		/*求值函数:求队尾函数.
		时间复杂度:O(1). 
		*/
		{
			if(empty())
				return 0;
			return List[tail];
		}
		inline bool empty()
		/*判断函数:判断队列是否为空.
		时间复杂度:O(1). 
		*/
		{
			return head>tail;
		}
		inline int size()
		/*求值函数:求队列的长.
		时间复杂度:O(1). 
		*/
		{
			return tail-head+1;
		}
		inline void clear()
		/*清空函数:清空队列.
		时间复杂度:O(1). 
		*/
		{
			head=1;
			tail=0;
			memset(List,0,sizeof(List));
		}
		inline T& operator[](const int i)
		/*求值函数:求队列中第i个元素的值.
		时间复杂度:O(1). 
		*/
		{
			return List[head+i];
		}
};
int main(){

}
