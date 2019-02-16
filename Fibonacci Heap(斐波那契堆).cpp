/*斐波那契堆(Fibonacci Heap)模板*/
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
template<class T>
class fibheap{
    private:
    	class fibnode{
    		public:
        		T key;
        		int degree;
        		fibnode*left;
        		fibnode*right;
        		fibnode*child;
        		fibnode*parent;
        		bool marked;
        		inline fibnode(T value){
            		key=value;
            		degree=0;
            		marked=0;
            		left=this;
            		right=this;
            		parent=NULL;
            		child=NULL;
        		}
		};
        int keynum;
        int maxdegree;
        fibnode*min;
        fibnode**cons;
    public:
        inline fibheap()
        /*构造函数:建造一个空堆.
		时间复杂度:O(1). 
		*/
		{
    		keynum=0;
    		maxdegree=0;
    		min=NULL;
    		cons=NULL;
		}
        inline void insert(T key)
        /*插入函数:往堆中插入一个元素. 
		时间复杂度:O(log2 n) 
		*/
		{
    		fibnode*node;
    		node=new fibnode(key);
    		if(node==NULL)
        	return;
    		insert(node);
		}
        inline void pop()
        /*弹出函数:弹出堆顶. 
		时间复杂度:O(log2 n) 
		*/
		{
    		if(min==NULL)
        	return;
    		fibnode*child=NULL;
    		fibnode*m=min;
    		while(m->child!=NULL)
    		{
        		child=m->child;
        		removenode(child);
        		if(child->right==child)
            	m->child=NULL;
        		else
            	m->child=child->right;
        		addnode(child,min);
        		child->parent=NULL;
    		}
    		removenode(m);
  			if(m->right==m)
        	min=NULL;
    		else
    		{
        		min=m->right;
        		consolidate();
    		}
    		keynum--;
    		delete m;
		}
        inline void merge(fibheap<T>*other)
        /*合并函数:合并两个堆. 
		时间复杂度:O(1) 
		*/
		{
    		if(other==NULL)
        	return;
    		if(other->maxdegree>this->maxdegree)
        	std::swap(*this,*other);
    		if((min)==NULL)                
    		{
        		min=other->min;
        		keynum=other->keynum;
        		return;
    		}
    		else if((other->min)==NULL){
				return;                
        	}
    		else
    		{
        		catlist(min,other->min);
        		if(min->key>other->min->key)
            	min=other->min;
        		keynum+=other->keynum;
        		return;
    		}
		}
        inline bool minmodify(T*pkey)
        /*修改函数:修改最小值
		时间复杂度:O(1) 
		*/
		{
    		if(min==NULL||pkey==NULL)
       		return 0;
    		*pkey=min->key;
    		return 1;
		}
        inline void update(T oldkey,T newkey)
        /*修改函数:将堆中值为oldkey的元素的值修改为newkey.
		时间复杂度:O(log2 n) 
		*/
		{
    		fibnode*node;
    		node=search(oldkey);
    		if(node)
        		update(node,newkey);
		}
        inline void remove(T key)
		/*删除函数:删除队堆中值为key的元素. 
		时间复杂度:O(log2 n) 
		*/
		{
    		fibnode*node;
    		if(min==NULL)
        		return;
    		node=search(key);
    		if(node==NULL)
        		return;
    		erase(node);
		}
        inline bool find(T key)
        /*判断函数:判断堆中是否存在值为key的元素. 
		时间复杂度:O(1) 
		*/
		{
    		return search(key)!=NULL?1:0;
		}
		inline T top()
		/*求值函数:求堆中元素最小值.
		时间复杂度:O(1) 
		*/
		{
			return min->key;
		}
        inline void clear()
        /*清空函数:清空堆.
		时间复杂度:O(1) 
		*/
		{
			removenode(min);
    		free(cons);
    		keynum=0;
    		maxdegree=0;
    		min=NULL;
    		cons=NULL;
		}
    private:
        inline void removenode(fibnode*node)
		{
    		node->left->right=node->right;
    		node->right->left=node->left;
		}
        inline void addnode(fibnode*node,fibnode*root)
		{
    		node->left=root->left;
    		root->left->right=node;
    		node->right=root;
    		root->left=node;
		}
		inline void catlist(fibnode*a,fibnode*b)
		{
    		fibnode*tmp;
    		tmp=a->right;
    		a->right=b->right;
    		b->right->left=a;
    		b->right=tmp;
    		tmp->left=b;
		}
        inline void insert(fibnode*node)
		{
    		if(keynum==0)
        	min=node;
    		else
       		{
        		addnode(node,min);
        		if(node->key<min->key)
            		min=node;
    		}
    		keynum++;
		}
        inline fibnode*extract()
		{
    		fibnode*p=min;
    		if(p==p->right)
        	min=NULL;
    		else
    		{
        		removenode(p);
        		min=p->right;
    		}
    		p->left=p->right=p;
    		return p;
		}
        inline void linked(fibnode*node,fibnode*root)
		{
    		removenode(node);
    		if(root->child==NULL)
        		root->child=node;
    		else
        		addnode(node, root->child);
    		node->parent=root;
    		root->degree++;
    		node->marked=0;
		}
        inline void makecons()
		{
    		int old=maxdegree;
    		maxdegree=(log(keynum)/log(2.0))+1;
    		if(old>=maxdegree)
        		return;
    		cons=(fibnode**)realloc(cons, 
            sizeof(fibheap<T>*)*(maxdegree+1));
		}
        inline void consolidate()
		{
    		int d,D;
    		fibnode*x,*y,*tmp;
    		makecons();
    		D=maxdegree+1;
    		for(int i=0;i<D;i++)
        	cons[i]=NULL;
    		while(min)
    		{
        		x=extract(); 
        		d=x->degree;
        		while(cons[d]!=NULL)
        		{
           			y=cons[d];               
            		if(x->key>y->key) 
                		std::swap(x,y);
            		linked(y,x);
            		cons[d]=NULL;
            		d++;
        		}
        		cons[d]=x;
    		}
    		min=NULL;
    		for(int i=0;i<D;i++)
    		{
        		if (cons[i])
        			{
            		if(min==NULL)
                		min=cons[i];
            		else
            		{
                		addnode(cons[i],min);
                		if((cons[i])->key<min->key)
                    	min=cons[i];
            		}
        		}
    		}
		}
        inline void renewdegree(fibnode*parent,int degree)
		{
    		parent->degree-=degree;
    		if(parent->parent)
        		renewdegree(parent->parent,degree);
		}
        inline void cut(fibnode*node,fibnode*parent)
		{
    		removenode(node);
    		renewdegree(parent,node->degree);
    		if(node==node->right) 
        		parent->child=NULL;
    		else 
        		parent->child=node->right;
    		node->parent=NULL;
    		node->left=node->right=node;
    		node->marked=0;
    		addnode(node,min);
		}
		inline void cascut(fibnode*node) 
		{
    		fibnode*parent=node->parent;
    		if(parent)
    		{
        		if (node->marked==0) 
        		node->marked=1;
        		else
        		{
            		cut(node,parent);
            		cascut(parent);
        		}
    		}
		}
        inline void decrease(fibnode*node,T key)
		{
    		fibnode*parent;
    		if(min==NULL||node==NULL) 
        		return;
    		if(key>=node->key)
        		return;
    		node->key=key;
    		parent=node->parent;
    		if(parent&&node->key<parent->key)
    		{
        		cut(node,parent);
        		cascut(parent);
    		}
    		if(node->key<min->key)
        		min=node;
		}
        inline void increase(fibnode*node,T key)
		{
    		fibnode*child,*parent,*right;
    		if(min==NULL||node==NULL) 
        		return;
    		if(key<=node->key)
    			return;
    		while(node->child)
    		{
        		child=node->child;
        		removenode(child);
        		if(child->right==child)
            	node->child=NULL;
        		else
            	node->child=child->right;
        		addnode(child,min);
        		child->parent=NULL;
    		}
    		node->degree=0;
    		node->key=key;
    		parent=node->parent;
    		if(parent)
    		{
        		cut(node,parent);
        		cascut(parent);
    		}
    		else if(min==node)
    		{
        		right=node->right;
        		while(right!=node)
        		{
            	if(node->key>right->key)
                	min=right;
            	right=right->right;
        		}
    		}
		}
        inline void update(fibnode*node,T key)
		{
    		if(key<node->key)
        		decrease(node,key);
    		else if(key>node->key)
        		increase(node,key);
   	 		else
        		return;
		}
        inline fibnode*search(fibnode*root,T key)
		{
    		fibnode*t=root;
    		fibnode*p=NULL;
    		if(root==NULL)
        	return root;
    		do
    		{
        		if(t->key==key)
        		{
           			p=t;
            		break;
        		} 
        		else
        		{
            		if((p=search(t->child,key))) 
                	break;
        		}    
        		t=t->right;
    		}while(t!=root);
    		return p;
		}
        inline fibnode*search(T key)
		{
    		if(min==NULL)
        		return NULL;
    		return search(min,key);
		}
        inline void erase(fibnode*node)
		{
    		T m=min->key-1;
    		decrease(node,m-1);
    		pop();
		}
};
int main(){

}
