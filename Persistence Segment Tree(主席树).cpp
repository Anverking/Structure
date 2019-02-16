/*主席树(Persistence Segment Tree)模板*/
#include<iostream>
#include<cstring>
#include<algorithm>
const int maxn=1e3;
template<class T>
class pertree{
	private:
		int cnt,pos,ques;
		int sum[maxn<<5];
		int root[maxn],lchild[maxn<<5],rchild[maxn<<5];
		T bits[maxn];
		inline void _build(int&t,int l,int r)
		{
    		t=++cnt;
    		if(l==r)
        		return;
    		int mid=(l+r)>>1;
    		_build(lchild[t],l,mid);
    		_build(rchild[t],mid+1,r);
		}
		inline int modify(int rt,int l,int r)
		{
    		int cur=++cnt;
    		lchild[cur]=lchild[rt];
			rchild[cur]=rchild[rt];
			sum[cur]=sum[rt]+1;
    		if(l==r)
        		return cur;
    		int mid=(l+r)>>1;
    		if(pos<=mid)
				lchild[cur]=modify(lchild[cur],l,mid);
    		else 
				rchild[cur]=modify(rchild[cur],mid+1,r);
    		return cur;
		}
		inline T query(int u,int v,int l,int r,int k)
		{
    		T ans;
			int mid=(l+r)>>1,x=sum[lchild[v]]-sum[lchild[u]];
    		if(l==r)
        		return l;
    		if(x>=k)
				ans=query(lchild[u],lchild[v],l,mid,k);
    		else 
				ans=query(rchild[u],rchild[v],mid+1,r,k-x);
    		return ans;
		}
	public:
		inline pertree():cnt(0),pos(0),ques(0)
		/*构造函数:建造一棵空的主席树.
		时间复杂度:O(1). 
		*/
		{
			memset(lchild,0,sizeof(lchild));
			memset(rchild,0,sizeof(rchild));
			memset(sum,0,sizeof(sum));
			memset(bits,0,sizeof(bits));
		}
		inline void build(T*a,int n)
		/*建造函数:以长度为n的数组a建造主席树.
		时间复杂度:O(nlog2 n). 
		*/
		{
			memcpy(bits+1,a,sizeof(a));
			std::sort(bits+1,bits+n+1);
    		ques=std::unique(bits+1,bits+n+1)-bits-1;
    		_build(root[0],1,ques);
    		for(int i=1;i<=n;i++)
    		{
        		pos=std::lower_bound
				(bits+1,bits+ques+1,a[i-1])-bits;
        		root[i]=modify(root[i-1],1,ques);
    		}
		}
		inline T query_kth(int l,int r,int k)
		/*求值函数:求区间[l,r]中的第k小值.
		时间复杂度:O(log2 n). 
		*/
		{
			l++,r++;
			return bits[
			(query(root[l-1],root[r],1,ques,k))];
		}
};
int main()
{

}
