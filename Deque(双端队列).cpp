/*Ë«¶Ë¶ÓÁÐ(Deque)Ä£°å*/
#include<iostream>
const int maxn=1e5;
template<class T>
class deque{
	private:
		int head,tail;
		T que[maxn*2];
	public:
		inline deque():head(maxn+1),tail(maxn){}
		inline void push_back(T v)
		{
			que[++tail]=v;
		}
		inline void push_front(T v)
		{
			que[--head]=v;
		} 
		inline void pop_back()
		{
			if(empty())
				return;
			tail--;
		}
		inline void pop_front()
		{
			if(empty())	
				return;
			head++;
		}
		inline T& front()
		{
			return que[head];
		}
		inline T& back()
		{
			return que[tail];
		}
		inline T& operator[](const int i)
		{
			if(i>=size())
				return 0;
			return que[head+i];
		}
		inline int size()
		{
			return tail-head+1;
		}
		inline bool empty()
		{
			return head>tail;
		}
		inline void clear()
		{
			head=maxn+1;
			tail=maxn;
		}
}; 
int main()
{

}
