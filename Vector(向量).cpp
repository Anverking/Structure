#include<iostream>
#include<cstring>
#include<malloc.h>
template<class T> 
class vector{
	private:
		int siz;
		T*arr;
	public:
		static const int status=5;
		inline vector():siz(status)
		{
			arr=(T*)malloc(sizeof(T)*status);
		}
		inline void insert(int pos,T x)
		{
			T s[siz];
			for(int i=0;i<siz;i++)
				s[i]=arr[i];
			free(arr);
			siz++;
			arr=(T*)malloc(sizeof(T)*siz);
			for(int i=0;i<pos;i++)
				arr[i]=s[i];
			arr[pos]=x;
			for(int i=pos+1;i<siz;i++)
				arr[i]=s[i-1];
		}
		inline void modify(int pos,T x)
		{
			arr[pos]=x;
		}
		inline void remove(int pos)
		{
			if(!siz)
				return;
			T s[siz];
			for(int i=0;i<siz;i++)
				s[i]=arr[i];
			free(arr);
			siz--;
			arr=(T*)malloc(sizeof(T)*siz);
			for(int i=0;i<pos;i++)
				arr[i]=s[i];
			for(int i=pos;i<siz;i++)
				arr[i]=s[i+1];
		}
		inline T& operator[](const int i)
		{
			return arr[i];
		}
		inline int size()
		{
			return siz;
		}
		inline void push_back(T x)
		{
			insert(siz-1,x);
		}
		inline void pop_back()
		{
			remove(siz-1);
		}
		inline void push_front(T x)
		{
			insert(0,x);
		}
		inline void pop_front()
		{
			remove(0);
		}
};
int main()
{

}
