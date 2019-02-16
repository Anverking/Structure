/*����(Linked List)ģ��*/
#include<iostream>
template<class T>
class linklist{
	private:
		class node{
			public:
				T data;
				node*next;
				node*prev;
				inline node():next(NULL),prev(NULL){}
		};
		node*head;
		node*tail;
		inline node*get(int i){
			node*a=head->next;
			while(i--)
				a=a->next;
			return a;
		}
		inline void destory(node*a){
			if(a->next)
				destory(a->next);
			delete a;
		}
	public:
		inline linklist()
		/*���캯��:����һ���յ�����.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			head=new node;
			tail=new node;
			head->next=tail;
			tail->prev=head;
		}
		inline ~linklist()
		/*��������:�������.
		ʱ�临�Ӷ�:O(n). 
		*/
		{
			clear();
			delete head;
			delete tail;
		} 
		inline bool empty()
		/*�жϺ���:�ж������Ƿ�Ϊ��.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			return head->next==tail&&tail->prev==head;
		}
		inline void clear()
		/*��պ���:�������.
		ʱ�临�Ӷ�:O(n). 
		*/
		{
			destory(head);
			head=new node;
			tail=new node;
			head->next=tail;
			tail->prev=head;
		}
		inline void push_front(T x)
		/*���뺯��:������ͷ����һ��Ԫ��.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			node*a=new node;
			a->data=x;
			a->next=head->next;
			head->next->prev=a;
			head->next=a;
			a->prev=head;
		}
		inline void push_back(T x)
		/*���뺯��:������β����һ��Ԫ��.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			node*a=new node;
			a->data=x;
			a->prev=tail->prev;
			tail->prev->next=a;
			tail->prev=a;
			a->next=tail;
		}
		inline void insert(int i,T x)
		/*���뺯��:��i������һ��Ԫ��.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			node*p=get(i);
			node*a=new node;
			a->data=x;
			a->prev=p->prev;
			p->prev->next=a;
			p->prev=a;
			a->next=p;
		}
		inline void pop_front()
		/*ɾ������:ɾ������ͷ��Ԫ��.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			node*a=head->next->next;
			head->next=a;
			delete a->prev;
			a->prev=head;
		}
		inline void pop_back()
		/*ɾ������:ɾ������β��Ԫ��.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			node*a=tail->prev->prev;
			tail->prev=a;
			delete a->next;
			a->next=tail;
		}
		inline void remove(int i)
		/*ɾ������:ɾ��i����Ԫ��.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			i++;
			node*a=get(i);
			a->prev->next=a->next;
			a->next->prev=a->prev;
			delete a;
		}
		inline T& front()
		/*��ֵ����:������ͷ.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			return head->next->data;
		}
		inline T& back()
		/*��ֵ����:������β.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			return tail->prev->data;
		}
		inline T& operator[](int i)
		/*��ֵ����:���i����Ԫ��.
		ʱ�临�Ӷ�:O(n). 
		*/
		{
			i++;
			node*a=head->next;
			while(i--&&a->next!=tail)
				a=a->next;
			return a->data;
		}
		inline int size()
		/*��ֵ����:������.
		ʱ�临�Ӷ�:O(n). 
		*/
		{
			node*a=head->next;
			int i=0;
			while(a->next!=tail)
				i++,
				a=a->next;
			return i+1;
		}
};
int main(){

}
