#include<iostream>
#include<cstring>
#include<malloc.h>
typedef unsigned long long ULL;
template<class T,const ULL maxn>
class array{
	private:
		T*arr;
		ULL siz;
	public:
		inline array():siz(maxn)
		{
			arr=(T*)malloc(sizeof(T)*maxn);
		}
		inline T& operator[](const int i)
		{
			return arr[i];
		}
		inline ULL size()
		{
			return siz;
		}
		inline void memset(T s)
		{
			::memset(arr,s,sizeof(arr));
		}
		inline void recycle()
		{
			free(arr);
			arr=malloc(sizeof(T)*maxn);
		}
};
int main()
{

}
