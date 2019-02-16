/*��ƫ��(Leftist Tree)ģ��*/
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
		/*���캯��:����һ�ÿ���.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			memset(left,0,sizeof(left));
			memset(right,0,sizeof(right));
			memset(dist,0,sizeof(dist));
		}
		inline void merge(int&x,int y)
		/*�ϲ�����:�ϲ���xΪ����������yΪ������.
		ʱ�临�Ӷ�:O(log2 n). 
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
		/*���캯��:�½�һ���ڵ�.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			cnt++;
			value[cnt]=v;
			left[cnt]=right[cnt]=dist[cnt]=0;
			return cnt;
		}
		inline void push(int&x,T v)
		/*���뺯��:����xΪ�������в���һ��Ԫ��.
		ʱ�临�Ӷ�:O(log2 n). 
		*/ 
		{
			x=merge(x,creat(v));
		}
		inline void pop(int&x)
		/*ɾ������:ɾ��x�Žڵ�.
		ʱ�临�Ӷ�:O(log2 n). 
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
		/*��ֵ����:����xΪ�������е�Ԫ����Сֵ.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			return value[x];
		}
		inline void clear()
		/*��պ���:������е���.
		ʱ�临�Ӷ�:O(1). 
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
