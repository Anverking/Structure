/*循环队列(Circular Queue)模板*/
#include<iostream>
#include<cstring>
template<class T,const int circle>
class cirque{
	private:
		T base[circle+5];
		int front;
		int rear;
	public:
		inline cirque():front(0),rear(0){}
		inline bool push(T x)
		{
		    if ((rear+1)%circle==front)
		        return 0;
		    base[rear]=x;
		    rear=(rear+1)%circle;
		    return 1;
		}
		inline bool pop()
		{
		    if(front==rear)
		        return 0;
		    front=(front+1)%circle;
		    return 1;
		}
		inline void clear()
		{
    		front=rear=0;
		}
		inline void size()
		{
			return rear-front+1;
		}
		inline bool full()
		{
			return (rear+1)%circle==front;
		}
		inline bool empty()
		{
			return rear==front;
		}
};
int main()
{

}
