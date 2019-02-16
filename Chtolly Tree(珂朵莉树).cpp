/*çæ¶äÀòÊ÷(Chtolly Tree)Ä£°å*/
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
template<class T>
class chtotree{
	private:
		class node{
			public:
			    int left, right;
			    mutable T value;
			    inline bool operator<(const node&a)const
				{
			        return left<a.left;
			    }
			    inline node(int l,int r,T v):left(l),right(r),value(v){}
			    inline node(int l):left(l){}
		};
		std::set<node>tree;
		#define It typename std::set<node>::iterator
		inline It split(int pos)
		{
		    It it=tree.lower_bound(node(pos));
		    if(it!=tree.end()&&it->left==pos)
				return it;
		    it--;
		    int l=it->left,r=it->right;
		    T v=it->value;
		    tree.erase(it);
		    tree.insert(node(l,pos-1,v));
		    return tree.insert(node(pos,r,v)).first;
		}
		inline T fpm(T a,int b)
		{
			if(b==0)
				return 1;
			if(b==1)
				return a;
			if(b&1)
				return fpm(a,b-1)*a;
			T p=fpm(a,b>>1);
			return p*p;
		}
	public:
		inline It assign(int l,int r,T val)
		{
		    It it2=split(r+1),it1=split(l);
		    tree.erase(it1,it2);
		    tree.insert(node(l,r,val));
		}
		inline void update(int l,int r,T val)
		{
		    It it2=split(r+1),it1=split(l);
		    for(It it=it1;it!=it2;it++)
				it->value+=val;
		}
		inline T getkth(int l,int r,int k)
		{
		    It it2=split(r+1),it1=split(l);
		    std::vector<std::pair<T,int> >V;
		    for(It it=it1;it!=it2;it++)
				V.push_back(std::pair<T,int>(it->value,it->right-it->left+1));
		    std::sort(V.begin(),V.end());
		    for(int i=0;i<V.size();i++)
			{
		        k-=V[i].second;
		        if(k<=0)
					return V[i].first;
		    }
		}
		inline T query_sum(int l,int r,int x)
		{
		    It it2=split(r+1),it1=split(l);
		    T res=0;
		    for(It it=it1;it!=it2;it++)
				res=(res+(it->right-it->left+1)*fpm(it->value,x));
		    return res;
		}
		#undef It
};
int main() {
   
}
