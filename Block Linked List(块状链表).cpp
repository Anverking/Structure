/*¿é×´Á´±í(Block Linked List)Ä£°å*/
#include<iostream>
#include<cstring>
#include<cmath>
const int maxn=1e4;
const int maxm=sqrt(maxn);
template<class T>
class rope{
	private:
		class data{
			public:
				int s;
				T a[maxm+maxm+5];
				data*next;
				inline data():s(0),add(0),sum(0){
					next=NULL;
				}
				T add,sum;
		};
		inline void destory(data*k){
			if(k->next!=NULL)
				destory(k->next);
			delete k;
		}
		int sz;
		data*root;
	public:
		inline rope():sz(0){
			root=NULL;
		}
		inline void clear()
		{
			destory(root);
		}
		inline void push_front(T x){
			insert(0,x);
		}
		inline void pop_front(){
			remove(0);
		}
		inline int size(){
			return sz;
		}
		inline void push_back(T x){
			insert(size()-1,x); 
		}
		inline void pop_back(){
			remove(size()-1);
		}
		inline void insert(int pos,T x){
			pos++;
			sz++;
			if(root==NULL)
			{
				root=new data;
				root->s=1;
				root->a[1]=x;
				return;
			}
			data*k=root;
			while(pos>k->s&&k->next!=NULL){
				pos-=k->s;
				k=k->next;
			}
			memmove(k->a+pos+1,k->a+pos,sizeof(T)*(k->s-pos+1));
			k->s++;
			k->a[pos]=x;
			if(k->s==2*sz)
			{
				data*t=new data;
				t->next=k->next;
				k->next=t;
				memcpy(t->a+1,k->a+sz+1,sizeof(T)*sz);
				t->s=k->s=sz;
			}
		}
		inline void remove(int pos){
			sz--;
			pos++;
			data*k=root;
			while(pos>k->s&&k->next!=NULL)
			{
				pos-=k->s;
				k=k->next;
			}
			memmove(k->a+pos,k->a+pos+1,sizeof(T)*(k->s-pos));
			k->s--;
		}
		inline T& operator[](int pos){
			pos++;
			data*k=root;
			while(pos>k->s&&k->next!=NULL){
				pos-=k->s;
				k=k->next;
			}
			return k->a[pos];
		}
		inline~rope(){
			destory(root);
		}
};
int main()
{

}
