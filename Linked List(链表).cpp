/*链表(Linked List)模板*/
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
		/*构造函数:构造一个空的链表.
		时间复杂度:O(1). 
		*/
		{
			head=new node;
			tail=new node;
			head->next=tail;
			tail->prev=head;
		}
		inline ~linklist()
		/*析构函数:清空链表.
		时间复杂度:O(n). 
		*/
		{
			clear();
			delete head;
			delete tail;
		} 
		inline bool empty()
		/*判断函数:判断链表是否为空.
		时间复杂度:O(1). 
		*/
		{
			return head->next==tail&&tail->prev==head;
		}
		inline void clear()
		/*清空函数:清空链表.
		时间复杂度:O(n). 
		*/
		{
			destory(head);
			head=new node;
			tail=new node;
			head->next=tail;
			tail->prev=head;
		}
		inline void push_front(T x)
		/*插入函数:在链表头插入一个元素.
		时间复杂度:O(1). 
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
		/*插入函数:在链表尾插入一个元素.
		时间复杂度:O(1). 
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
		/*插入函数:在i处插入一个元素.
		时间复杂度:O(1). 
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
		/*删除函数:删除链表头的元素.
		时间复杂度:O(1). 
		*/
		{
			node*a=head->next->next;
			head->next=a;
			delete a->prev;
			a->prev=head;
		}
		inline void pop_back()
		/*删除函数:删除链表尾的元素.
		时间复杂度:O(1). 
		*/
		{
			node*a=tail->prev->prev;
			tail->prev=a;
			delete a->next;
			a->next=tail;
		}
		inline void remove(int i)
		/*删除函数:删除i处的元素.
		时间复杂度:O(1). 
		*/
		{
			i++;
			node*a=get(i);
			a->prev->next=a->next;
			a->next->prev=a->prev;
			delete a;
		}
		inline T& front()
		/*求值函数:求链表头.
		时间复杂度:O(1). 
		*/
		{
			return head->next->data;
		}
		inline T& back()
		/*求值函数:求链表尾.
		时间复杂度:O(1). 
		*/
		{
			return tail->prev->data;
		}
		inline T& operator[](int i)
		/*求值函数:求第i处的元素.
		时间复杂度:O(n). 
		*/
		{
			i++;
			node*a=head->next;
			while(i--&&a->next!=tail)
				a=a->next;
			return a->data;
		}
		inline int size()
		/*求值函数:求链表长.
		时间复杂度:O(n). 
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
