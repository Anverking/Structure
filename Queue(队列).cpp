/*����(Queue)ģ��*/
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
		/*���캯��:����һ���յĶ���.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			memset(List,0,sizeof(List));
		}
		inline void push(T v)
		/*���뺯��:�ڶ�β����һ��Ԫ��.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			List[++tail]=v;
		}
		inline void pop()
		/*ɾ������:�������׵�Ԫ��.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			if(empty())
				return;
			head++;
		}
		inline T& front()
		/*��ֵ����:�����Ԫ��.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			if(empty())
				return 0;
			return List[head];
		}
		inline T& back()
		/*��ֵ����:���β����.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			if(empty())
				return 0;
			return List[tail];
		}
		inline bool empty()
		/*�жϺ���:�ж϶����Ƿ�Ϊ��.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			return head>tail;
		}
		inline int size()
		/*��ֵ����:����еĳ�.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			return tail-head+1;
		}
		inline void clear()
		/*��պ���:��ն���.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			head=1;
			tail=0;
			memset(List,0,sizeof(List));
		}
		inline T& operator[](const int i)
		/*��ֵ����:������е�i��Ԫ�ص�ֵ.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			return List[head+i];
		}
};
int main(){

}
