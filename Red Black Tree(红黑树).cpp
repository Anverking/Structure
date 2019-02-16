/*红黑树(Red Black Tree)模板*/
#include<iostream>
template<typename T>
class redblacktree{
	private:
        class node{
        	public:
    			T value;
    			bool color;
    			node*father;
    			node*lchild;
    			node*rchild;
    			int region;
    			inline node(
				T v=T(),bool RB=1,
            	node*f=NULL,node*l=NULL,node*r=NULL,int s=1)
        		:value(v),color(RB),father(f),
				lchild(l),rchild(r),region(s){}
    			inline node*next(){
        			node*ptn=rchild;
        			while(ptn->lchild){
            			--(ptn->region);
            			ptn=ptn->lchild;
        			}
        			return ptn;
    			}
    			inline node*prev(){
        			node*ptn=this;
        			if(!lchild){
            			while(ptn->father&&ptn->father->lchild==ptn)
                			ptn=ptn->father;
            			ptn=ptn->father;
        			}
					else
            			while(ptn->lchild)
                			ptn=ptn->lchild;
        			return ptn;
    			}
    			inline node*succ(){
        			node*ptn=this;
        			if(!rchild){
            			while(ptn->father&&ptn->father->rchild==ptn)
                			ptn=ptn->father;
            		ptn=ptn->father;
        			}
					else
            			while(ptn->rchild)
                			ptn=ptn->rchild;
        			return ptn;
    			}
    			inline void maintain(){
        			region=1;
        			if(lchild)
						region+=lchild->region;
        			if(rchild)
						region+=rchild->region;
    			}
		};
		inline node*brother(node*x){
			return (((x)->father->lchild==(x))?
			((x)->father->rchild):((x)->father->lchild));
		}
		inline bool islchild(node*x){
			return (x&&x->father->lchild==x);
		}
		inline bool isrchild(node*x){
			return (x&&x->father->rchild==x);
		}
        node*root;
        node*hot;
        inline void init(T v){
    		root=new node(v,0,NULL,NULL,NULL,1);
		}
        inline void connect(    
			node*nroot,node*nlc,node*nrc,
			node*ntree1,node*ntree2,node*ntree3,node*ntree4)
		{
    		nlc->lchild=ntree1;
    		if(ntree1)
				ntree1->father=nlc;
    		nlc->rchild=ntree2;
    		if(ntree2)
				ntree2->father=nlc;
    		nrc->lchild=ntree3;
    		if(ntree3)
				ntree3->father=nrc;
    		nrc->rchild=ntree4;
    		if(ntree4)
				ntree4->father=nrc;
    		nroot->lchild=nlc;
    		nlc->father=nroot;
    		nroot->rchild=nrc;
    		nrc->father=nroot;
    		nlc->maintain();
    		nrc->maintain();
    		nroot->maintain();
		}
        inline void solvered(node*nn){
    		while((!(nn->father))||nn->father->color){
        		if(nn==root){
            		root->color=0;
            	return;
        	}
        	node*pftr=nn->father;
        	if(!(pftr->color))
				return;
        	node*uncle=brother(nn->father);
        	node*grdftr=nn->father->father;
        	if(uncle&&uncle->color){
            	grdftr->color=1;
            	uncle->color=0;
            	pftr->color=0;
            	nn=grdftr;
        	}
			else
			{
            	if(islchild(pftr))
				{
                	if(islchild(nn))
					{
                    	pftr->father=grdftr->father;
                    	if(grdftr==root)
							root=pftr;
                    	else 
							if(grdftr->father->lchild==grdftr)
								grdftr->father->lchild=pftr;
                    	else 
							grdftr->father->rchild=pftr;
                    	connect(
						pftr,nn,grdftr,
						nn->lchild,nn->rchild,pftr->rchild,uncle);
                    	pftr->color=0;
                    	grdftr->color=1;
                	}
					else
					{
                    	nn->father=grdftr->father;
                    	if(grdftr==root)
							root=nn;
                    	else 
							if(grdftr->father->lchild==grdftr)
								grdftr->father->lchild=nn;
                    	else 
							grdftr->father->rchild=nn;
                    	connect(
						nn,pftr,grdftr,
						pftr->lchild,nn->lchild,nn->rchild,uncle);
                    	nn->color=0;
                    	grdftr->color=1;
                	}
            	} 
				else
				{
                	if(islchild(nn)){
                    	nn->father=grdftr->father;
                    	if(grdftr==root)
							root=nn;
                    	else 
							if(grdftr->father->lchild==grdftr)
								grdftr->father->lchild=nn;
                    	else 
							grdftr->father->rchild=nn;
                    	connect(
						nn,grdftr,pftr,
						uncle,nn->lchild,nn->rchild,pftr->rchild);
                    	nn->color=0;
                    	grdftr->color=1;
                	}
					else
					{
                    	pftr->father=grdftr->father;
                    	if(grdftr==root)
							root=pftr;
                    	else 
							if(grdftr->father->lchild==grdftr)
								grdftr->father->lchild=pftr;
                    	else 
							grdftr->father->rchild=pftr;
                    	connect(pftr,grdftr,nn,
						uncle,pftr->lchild,nn->lchild,nn->rchild);
                    	pftr->color=0;
                    	grdftr->color=1;
                	}
            	}
            	return;
        		}
    		}
		}
        inline void solveblack(node*nn){
    		while(nn!=root){
        		node*pftr=nn->father;
        		node*bthr=brother(nn);
        		if(bthr->color){
            		bthr->color=0;
            		pftr->color=1;
            		if(root==pftr)
						root=bthr;
            		if(pftr->father){
                		if(pftr->father->lchild==pftr)
                    		pftr->father->lchild=bthr;
                		else
                    		pftr->father->rchild=bthr;
            		}
            		bthr->father=pftr->father;
            		if(islchild(nn))
                		connect(
						bthr,pftr,bthr->rchild,
						nn,bthr->lchild,bthr->rchild->lchild,
						bthr->rchild->rchild);
            		else
                		connect(
						bthr,bthr->lchild,pftr,
						bthr->lchild->lchild,bthr->lchild->rchild,
						bthr->rchild,nn);
            		bthr=brother(nn);
            		pftr=nn->father;
        		}
        		if(bthr->lchild&&bthr->lchild->color)
				{
            		bool oldc=pftr->color;
            		pftr->color=0;
            		if(pftr->lchild==nn)
					{
                		if(pftr->father){
                    		if(pftr->father->lchild==pftr)
                        		pftr->father->lchild=bthr->lchild;
                    		else
                        		pftr->father->rchild=bthr->lchild;
                		}
                		bthr->lchild->father=pftr->father;
                		if(root==pftr)
							root=bthr->lchild;
                		connect(
						bthr->lchild,pftr,bthr,
						pftr->lchild,bthr->lchild->lchild,
						bthr->lchild->rchild,bthr->rchild);
            		}
					else{
                		bthr->lchild->color=0;
                		if(pftr->father){
                    		if(pftr->father->lchild==pftr)
                        		pftr->father->lchild=bthr;
                    		else
                        		pftr->father->rchild=bthr;
                		}
               			bthr->father=pftr->father;
                		if(root==pftr)
							root=bthr;
                		connect(bthr,bthr->lchild,pftr,
						bthr->lchild->lchild,bthr->lchild->rchild,
						bthr->rchild,pftr->rchild);
            		}
            		pftr->father->color=oldc;
            		return;
        		}
				else 
					if(bthr->rchild&&bthr->rchild->color)
					{
            			bool oldc=pftr->color;
            			pftr->color=0;
            			if(pftr->lchild==nn)
						{
                			bthr->rchild->color=0;
                			if(pftr->father){
                    			if(pftr->father->lchild==pftr)
                        			pftr->father->lchild=bthr;
                    			else
                        			pftr->father->rchild=bthr;
                			}
                		bthr->father=pftr->father;
                		if(root==pftr)
							root=bthr;
                		connect(bthr,pftr,bthr->rchild,
						pftr->lchild,bthr->lchild,
						bthr->rchild->lchild,bthr->rchild->rchild);
            			}
						else
						{
                			if(pftr->father){
                    			if(pftr->father->lchild==pftr)
                        			pftr->father->lchild=bthr->rchild;
                    			else
                        			pftr->father->rchild=bthr->rchild;
                			}
                			bthr->rchild->father=pftr->father;
                			if(root==pftr)
								root=bthr->rchild;
                			connect(bthr->rchild,bthr,pftr,
							bthr->lchild,bthr->rchild->lchild,
							bthr->rchild->rchild,pftr->rchild);
            			}
            			pftr->father->color=oldc;
            			return;
        			}
        		if(pftr->color)
				{
            		pftr->color=0;
            		bthr->color=1;
            		return;
        		}
		 		else 	
				{
            		bthr->color=1;
            		nn=pftr;
        		}
    		}
		}
        inline node*find(T v,const int op){
    		node*ptn=root;
    		hot=NULL;
    		while(ptn){
        		hot=ptn;
        		ptn->region+=op;
        		if(ptn->value>v)
            		ptn=ptn->lchild;
        		else
        	    	ptn=ptn->rchild;
    		}
    		return ptn;
		}
        inline node*rfind(T v,const int op){
    		node*ptn=root;
    		hot=NULL;
    		while(ptn&&ptn->value!=v){
        		hot=ptn;
        		ptn->region+=op;
        		if(ptn->value>v)
            		ptn=ptn->lchild;
		        else
        		    ptn=ptn->rchild;
    		}
    		return ptn;
		}
        inline node*findkth(int rank,node*ptn){
   			if(!(ptn->lchild)){
        		if(rank==1)
            		return ptn;
        		else
            		return findkth(rank-1,ptn->rchild);
    		}
			else{
        		if(ptn->lchild->region==rank-1)
					return ptn;
        		else 
					if(ptn->lchild->region>=rank)
						return findkth(rank,ptn->lchild);
        		else 
					return findkth(rank-(ptn->lchild->region)-1,ptn->rchild);
    		}
		}
        inline int findrank(T v,node*ptn){
    		if(!ptn)return 1;
    		else 
				if(ptn->value>=v)
					return findrank(v,ptn->lchild);
    		else 
				return(
				1+((ptn->lchild)?(ptn->lchild->region):0)
				+findrank(v,ptn->rchild));
		}
    public:
        class iterator
		/*类:迭代器*/
		{
    		private:
        		node*realnode;
    		public:
        		inline void operator++()
				/*运算符:求当前迭代器的后继.
				时间复杂度:O(1). 
				*/
				{
            		realnode=realnode->succ();
        		}
        		inline void operator--()
				/*运算符:求当前迭代器的前驱.
				时间复杂度:O(1). 
				*/
				{
            		realnode=realnode->prev();
        		}
        		inline T operator*()
				/*运算符:求迭代器的值.
				时间复杂度:O(1). 
				*/
				{
            		return realnode->value;
        		}
        		inline iterator(node*noden=NULL)
				:realnode(noden){}
        		inline iterator(T const&val)
				:realnode(rfind(val,0)){}
        		inline iterator(iterator const&iter)
				:realnode(iter.realnode){}
		};
        inline redblacktree():root(NULL),hot(NULL){}
        inline int getrank(T v)
		/*求值函数:求v在树中的排名.
		时间复杂度:O(log2 n). 
		*/
		{
    		return findrank(v,root);
		}
        inline iterator insert(T v)
		/*插入函数:插入一个数,并返回其迭代器.
		时间复杂度:O(log2 n). 
		*/
		{
    		node*ptn=find(v,1);
    		if(hot==NULL){
        		init(v);
        		return iterator(root);
    		}
    		ptn=new node(v,1,hot,NULL,NULL,1);
    		if(hot->value<=v)
        		hot->rchild=ptn;
    		else
        		hot->lchild=ptn;
    		solvered(ptn);
    		return iterator(ptn);
		}
        inline bool remove(T v)
		/*删除函数:删除值为v的数,并判断是否能删除.
		时间复杂度:O(log2 n). 
		*/
		{
    		node*ptn=rfind(v,-1);
    		if(!ptn)
				return 0;
    		node*suc;
   			while(ptn->lchild||ptn->rchild)
			{
        		if(!(ptn->lchild))
            		suc=ptn->rchild;
				else if(!(ptn->rchild))
            		suc=ptn->lchild;
        		else
            		suc=ptn->next();
        		(ptn->region)--;
        		ptn->value=suc->value;
        		ptn=suc;
    		}
    		if(!(ptn->color)){
        		(ptn->region)--;
        		solveblack(ptn);
    		}
    		if(ptn==root){
        		root=NULL;
        		delete ptn;
        		return 1;
    		}
    		if(ptn->father->lchild==ptn)
        		ptn->father->lchild=NULL;
    		else
        		ptn->father->rchild=NULL;
    		delete ptn;
    		return 1;
		}
        inline int size()
		/*求值函数:求树中节点数.
		时间复杂度:O(1). 
		*/
		{
    		return root->region;
		}
        inline bool empty()
		/*判断函数:判断树是否为空.
		时间复杂度:O(1). 
		*/
		{
    		return !root;
		}
        inline iterator getkth(int rank)
		/*求值函数:求第k小的元素的迭代器.
		时间复杂度:O(log2 n). 
		*/
		{
    		return iterator(findkth(rank,root));
		}
        inline iterator prev(T v)
		/*求值函数:求v在树中的前驱的迭代器.
		时间复杂度:O(log2 n). 
		*/
		{
    		node*ptn=root;
    		while(ptn){
        		hot=ptn;
        		if(ptn->value<v)
            		ptn=ptn->rchild;
        		else
            		ptn=ptn->lchild;
        	}
    		if(hot->value<v)
        		ptn=hot;
    		else
        		ptn=hot->prev();
    		return iterator(ptn);
		}
        inline iterator succ(T v)
		/*求值函数:求v在树中的后继的迭代器.
		时间复杂度:O(log2 n). 
		*/
		{
    		node*ptn=root;
    		while(ptn){
        		hot=ptn;
        		if(ptn->value>v)
            		ptn=ptn->lchild;
        		else
            		ptn=ptn->rchild;
    		}
    		if(hot->value>v)
        		ptn=hot;
    		else
        		ptn=hot->succ();
    		return iterator(ptn);
		}
};
int main(){

}
