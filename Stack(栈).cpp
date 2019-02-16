/*栈(Stack)模板*/
#include<iostream>
#include<cstring>
const int maxn=1e5;
template<class T>
class stack{
	private:
		T List[maxn];
		int head;
	public:
		inline stack():head(0)
		/*构造函数:建造一个空栈.
		时间复杂度:O(1). 
		*/
		{
			memset(List,0,sizeof(List));
		}
		inline void push(T v)
		/*插入函数:在栈顶插入一个元素.
		时间复杂度:O(1). 
		*/
		{
			List[head++]=v;
		}
		inline void pop()
		/*删除函数:弹出栈顶.
		时间复杂度:O(1). 
		*/
		{
			if(empty())
				return;
			head--;
		}
		inline T& top()
		/*求值函数:求栈顶.
		时间复杂度:O(1). 
		*/
		{
			if(empty())
				return 0;
			return List[head-1];
		}
		inline bool empty()
		/*判断函数:判断栈是否为空.
		时间复杂度:O(1). 
		*/
		{
			return !head;
		}
		inline int size()
		/*求值函数:求栈的长.
		时间复杂度:O(1). 
		*/
		{
			return head;
		}
		inline void clear()
		/*清空函数:清空栈.
		时间复杂度:O(1). 
		*/
		{
			head=0;
			memset(List,0,sizeof(List));
		}
};
int main(){

}
