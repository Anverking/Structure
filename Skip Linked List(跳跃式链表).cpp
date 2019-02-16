/*��Ծʽ����(Skip Linked List)ģ��*/
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
		/*��ֵ����:��ȡһ�������ַ.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
    		int ret=1;
    		while(rand()%2&&ret<=maxl)
        		ret++;
    		return ret;
		}
		inline skiplist():tot(0),head(0),tail(0),top(0)
		/*���캯��:����һ���յ�����.
		ʱ�临�Ӷ�:O(l). 
		*/
		{
			memset(List,0,sizeof(List));
    		creat(head,-INF),creat(tail,INF);
    		for(int i=1;i<=maxl;i++)
        		slist[head].next[i]=tail;
		}
		inline void clear()
		/*��պ���:�������.
		ʱ�临�Ӷ�:O(l). 
		*/
		{
			tot=head=tail=top=0;
			memset(List,0,sizeof(List));
    		creat(head,-INF),creat(tail,INF);
    		for(int i=1;i<=maxl;i++)
        		slist[head].next[i]=tail;
		}
		inline T& operator[](const int i)
		/*��ֵ����:��ȡ�����i��λ�õ�ֵ.
		ʱ�临�Ӷ�:O(n/l). 
		*/
		{
			return slist[find(i)].value;
		}
		inline void push_front(T value)
		/*���뺯��:������ͷ����һ��Ԫ��.
		ʱ�临�Ӷ�:O(l). 
		*/
		{
			insert(0,value);
		}
		inline void push_back(T value)
		/*���뺯��:������β����һ��Ԫ��.
		ʱ�临�Ӷ�:O(l). 
		*/{
			insert(siz,value);
		}
		inline void insert(int key,T value)
		/*���뺯��:�������keyλ�ò���ֵvalue.
		ʱ�临�Ӷ�:O(l). 
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
		/*��ֵ����:������ĳ�.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			return siz;
		}
		inline bool empty()
		/*�жϺ���:�ж������Ƿ�Ϊ��.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			return !siz;
		}
		inline void pop_front()
		/*ɾ������:ɾ������ͷ.
		ʱ�临�Ӷ�:O(l). 
		*/
		{
			remove(0);
		}
		inline void pop_back()
		/*ɾ������:ɾ������β.
		ʱ�临�Ӷ�:O(l). 
		*/
		{
			remove(siz);
		}
		inline void remove(int key)
		/*ɾ������:ɾ������keyλ�õ�Ԫ��.
		ʱ�临�Ӷ�:O(l). 
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
		/*���Һ���:����λ��keyλ�õ�Ԫ��.
		ʱ�临�Ӷ�:O(n/l). 
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
