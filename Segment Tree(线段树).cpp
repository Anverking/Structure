/*�߶���(Segment Tree)ģ��*/
#include<iostream>
#include<cstring>
const int maxn=1e3;
template<class T>
class segment{
	private:
		class node{
			public:
				int left,right;
				T value,add;
		}tree[maxn<<2];
		inline void _build(T*a,int p,int l,int r){
    		tree[p].left=l;
			tree[p].right=r;
    		if(l==r){
        		tree[p].value=a[l];
        		return;
    		}
    		int mid=(l+r)>>1;
    		_build(a,p<<1,l,mid);
    		_build(a,(p<<1)+1,mid+1,r);
    		tree[p].value=tree[p<<1].value+tree[(p<<1)+1].value;
		} 
		inline void pushdown(int p){
    		if(tree[p].add){
        		tree[p<<1].value+=
				tree[p].add*(tree[p<<1].right-tree[p<<1].left+1);
        		tree[(p<<1)+1].value+=
				tree[p].add*(tree[(p<<1)+1].right-tree[(p<<1)+1].left+1);
        		tree[p<<1].add+=tree[p].add;
        		tree[(p<<1)+1].add+=tree[p].add;
        		tree[p].add=0;
    		}
		}
		inline void _update(int p,int x,int y,T z){
    		if(x<=tree[p].left&&y>=tree[p].right){
        		tree[p].value+=z*(tree[p].right-tree[p].left+1);
        		tree[p].add+=z;
        		return;
    		}
   			pushdown(p);
    		int mid=(tree[p].left+tree[p].right)>>1;
    		if(x<=mid)
				_update((p<<1),x,y,z);
    		if(y>mid)
				_update((p<<1)+1,x,y,z);
    		tree[p].value=tree[p<<1].value+tree[(p<<1)+1].value;   
		}
		inline T query(int p,int x,int y){
    		if(x<=tree[p].left&&y>=tree[p].right)
				return tree[p].value;
    		pushdown(p);
    		int mid=(tree[p].left+tree[p].right)>>1;
    		T ans=0;
    		if(x<=mid)
				ans+=query(p<<1,x,y);
    		if(y>mid)
				ans+=query((p<<1)+1,x,y);
    		return ans;
		}
	public:
		inline segment(){}
		inline void build(T*a,int n)
		/*���캯��:�Գ���Ϊn������a�����߶���.
		ʱ�临�Ӷ�:O(nlog2 n). 
		*/
		{
			int b[n+1];
			for(int i=0;i<n;i++)
				b[i+1]=a[i];
			_build(a,1,1,n);
		}
		inline void update(int l,int r,T k)
		/*���ĺ���:��һ������[l,r]����k.
		ʱ�临�Ӷ�:O(log2 n). 
		*/
		{
			_update(1,l+1,r+1,k);
		}
		inline T operator[](const int i)
		/*��ֵ����:���i��Ԫ�ص�ֵ.
		ʱ�临�Ӷ�:O(log2 n). 
		*/
		{
			return query_sum(i,i);
		}
		inline void modify(int i,T k)
		/*���ĺ���:����i��������k.
		ʱ�临�Ӷ�:O(log2 n). 
		*/
		{
			update(i,i,k);
		}
		inline T query_sum(int l,int r)
		/*��ֵ����:��һ������[l,r]�ĺ�.
		ʱ�临�Ӷ�:O(log2 n). 
		*/
		{
			return query(1,l+1,r+1);
		}
};
int main(){

}
