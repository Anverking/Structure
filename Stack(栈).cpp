/*ջ(Stack)ģ��*/
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
		/*���캯��:����һ����ջ.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			memset(List,0,sizeof(List));
		}
		inline void push(T v)
		/*���뺯��:��ջ������һ��Ԫ��.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			List[head++]=v;
		}
		inline void pop()
		/*ɾ������:����ջ��.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			if(empty())
				return;
			head--;
		}
		inline T& top()
		/*��ֵ����:��ջ��.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			if(empty())
				return 0;
			return List[head-1];
		}
		inline bool empty()
		/*�жϺ���:�ж�ջ�Ƿ�Ϊ��.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			return !head;
		}
		inline int size()
		/*��ֵ����:��ջ�ĳ�.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			return head;
		}
		inline void clear()
		/*��պ���:���ջ.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			head=0;
			memset(List,0,sizeof(List));
		}
};
int main(){

}
