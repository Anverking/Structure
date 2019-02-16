#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
const int maxn=1e7;
template<class T>
class seg_splay{
	private:
		int cnt,siz;
		__gnu_pbds::tree<T,__gnu_pbds::null_type,
		std::less<T>,__gnu_pbds::rb_tree_tag,
		__gnu_pbds::tree_order_statistics_node_update>
		val[maxn*30];  
		inline void add(int&rt,T pos,int v){
			if(!rt)
				rt=++cnt;
			if(v==1)
				val[rt].insert(pos);
			else 
				val[rt].erase(pos);
		}
		inline T query(int &rt,T pos,int l,int r){
			if(!rt)
				rt=++cnt;
			return val[rt].order_of_key(pos+1)-1;
		}
		inline T count(int&rt,int l,int r){
			return query(rt,r,0,siz)-query(rt,l-1,0,siz);
		}
		int L[maxn*30],R[maxn*30],rot[maxn*30],tot,rt;
		inline void add(int&rt,int v,T pos,
		int val,int l=-maxn,int r=maxn){
			if(!rt)
				rt=++tot;
			add(rot[rt],pos,val);
			if(l==r)
				return;
			int mid=(l+r)>>1;
			if(v<=mid)
				add(L[rt],v,pos,val,l,mid);
			else 
				add(R[rt],v,pos,val,mid+1,r);
		}
		inline T get(int&rt,T v,int Lg,int Rg,
		int l=-maxn,int r=maxn){
			if(rot[rt]==0||l==r)
				return count(rot[rt],Lg,Rg);
			int mid=l+r>>1;
			if(v<=mid)
				return get(L[rt],v,Lg,Rg,l,mid);
			else 
				return count(rot[L[rt]],Lg,Rg)+
			get(R[rt],v,Lg,Rg,mid+1,r);
		}
		inline T findkth(int &rt,int k,int Lg,int Rg,int l=-maxn,int r=maxn){
			if(l==r)
				return r;
			int mid=(l+r)>>1,x=count(rot[L[rt]],Lg,Rg);
			if(k<=x)
				return findkth(L[rt],k,Lg,Rg,l,mid);
			else 
				return findkth(R[rt],k-x,Lg,Rg,mid+1,r);
		}
		T num[maxn];
	public:
		inline seg_splay():rt(0),cnt(0),tot(0){
			memset(L,0,sizeof(L));
			memset(R,0,sizeof(R));
			memset(rot,0,sizeof(rot));
		}
		inline void build(int*a,int n)
		{
			siz=n;
			for(int i=0;i<n;i++)
				add(rt,num[i],i+1,1);
		}
		inline int getrank(int l,int r,int x)
		{
			return get(rt,x-1,l,r)+1;
		}
		inline int getkth(int l,int r,int k)
		{
			return findkth(rt,k,l,r);
		}
		inline void modify(int pos,int k)
		{
			add(rt,num[pos],pos,-1);
			add(rt,num[pos]=k,pos,1);
		}
		inline int prev(int l,int r,int k)
		{
			return findkth(rt,get(rt,k-1,l,r),l,r);
		}
		inline int succ(int l,int r,int k)
		{
			return findkth(rt,get(rt,k,l,r)+1,l,r);
		}
};
int main(){

}
