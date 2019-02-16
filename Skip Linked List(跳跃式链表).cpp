/*跳跃式链表(Skip Linked List)模板*/
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<ctime>
const int INF=0x3f3f3f3f;
const int maxn=1e4;
const int maxl=2;
template<class T>
class skiplist{
	private:
		class node
		{
			public:
    			int key;
				T value;
    			int next[maxl+5];
		}slist[maxn+10];
		int tot,head,tail,siz;
		int List[maxn+10],top;
		inline void free(int p)
		{
    		List[++top]=p;
		}
		inline void creat(int &p,int key,T value=0)
		{
    		if(top)
        		p=List[top--];
    		else
        		p=++tot;
    			slist[p].key=key;
    			slist[p].value=value;
		}	
	public:
		inline int rand_level()
		/*求值函数:获取一个随机地址.
		时间复杂度:O(1). 
		*/
		{
    		int ret=1;
    		while(rand()%2&&ret<=maxl)
        		ret++;
    		return ret;
		}
		inline skiplist():tot(0),head(0),tail(0),top(0)
		/*构造函数:建造一个空的链表.
		时间复杂度:O(l). 
		*/
		{
			memset(List,0,sizeof(List));
    		creat(head,-INF),creat(tail,INF);
    		for(int i=1;i<=maxl;i++)
        		slist[head].next[i]=tail;
		}
		inline void clear()
		/*清空函数:清空链表.
		时间复杂度:O(l). 
		*/
		{
			tot=head=tail=top=0;
			memset(List,0,sizeof(List));
    		creat(head,-INF),creat(tail,INF);
    		for(int i=1;i<=maxl;i++)
        		slist[head].next[i]=tail;
		}
		inline T& operator[](const int i)
		/*求值函数:获取链表第i个位置的值.
		时间复杂度:O(n/l). 
		*/
		{
			return slist[find(i)].value;
		}
		inline void push_front(T value)
		/*插入函数:在链表头插入一个元素.
		时间复杂度:O(l). 
		*/
		{
			insert(0,value);
		}
		inline void push_back(T value)
		/*插入函数:在链表尾插入一个元素.
		时间复杂度:O(l). 
		*/{
			insert(siz,value);
		}
		inline void insert(int key,T value)
		/*插入函数:在链表的key位置插入值value.
		时间复杂度:O(l). 
		*/
		{
			siz++;
    		int p=head;
    		int update[maxl+5];
    		int k=rand_level();
    		for(int i=maxl;i;i--)
    		{
        		while(slist[p].next[i]^tail&&
				slist[slist[p].next[i]].key<key)
            	p=slist[p].next[i];
        		update[i]=p;
    		}
    		int temp;
    		creat(temp,key,value);
    		for(int i=k;i;i--)
    		{
        		slist[temp].next[i]=slist[update[i]].next[i];
        		slist[update[i]].next[i]=temp;
    		}
		}
		inline int size()
		/*求值函数:求链表的长.
		时间复杂度:O(1). 
		*/
		{
			return siz;
		}
		inline bool empty()
		/*判断函数:判断链表是否为空.
		时间复杂度:O(1). 
		*/
		{
			return !siz;
		}
		inline void pop_front()
		/*删除函数:删除链表头.
		时间复杂度:O(l). 
		*/
		{
			remove(0);
		}
		inline void pop_back()
		/*删除函数:删除链表尾.
		时间复杂度:O(l). 
		*/
		{
			remove(siz);
		}
		inline void remove(int key)
		/*删除函数:删除链表key位置的元素.
		时间复杂度:O(l). 
		*/
		{
			siz--;
    		int p=head;
    		int update[maxl+5];
    		for(int i=maxl;i;i--)
    		{
        		while(slist[p].next[i]^tail&&
				slist[slist[p].next[i]].key<key)
            	p=slist[p].next[i];
        		update[i]=p;
    		}
    		free(slist[p].next[1]);
    		for(int i=maxl;i;i--)
    		{
        		if(slist[slist[update[i]].next[i]].key==key)
            	slist[update[i]].next[i]=
				slist[slist[update[i]].next[i]].next[i];
    		}
		}
		inline int find(int key)
		/*查找函数:查找位于key位置的元素.
		时间复杂度:O(n/l). 
		*/
		{
    		int p=head;
    		for(int i=maxl;i;i--)
        	while(slist[p].next[i]^tail&&
			slist[slist[p].next[i]].key<key)
            p=slist[p].next[i];
    		return slist[p].next[1];
		}
};
int main(){

}
