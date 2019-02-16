/*二维线段树(Matrix Segment Tree)模板*/
#include<iostream>
#include<cstring>
const int maxn=1e2;
template<class T>
class matsegtree{
	private:
		T tree[maxn*3][maxn*3];
		int size;
		inline void add_y(int d,int dy,int L,int R,int y,T a) 
		{
		    tree[d][dy]+=a;
		    if(L==R)
		        return;
		    int mid=(L+R)>>1;
		    if(mid>=y)
		        add_y(d,dy<<1,L,mid,y,a);
		    else
		        add_y(d,dy<<1|1,mid+1,R,y,a);
		}
		inline void add_x(int d,int L,int R,int x,int y,T a)
		{
		    add_y(d,1,1,size,y,a);
		    if(L==R)
		        return;
		    int mid=(L+R)>>1;
		    if(mid>=x)
		        add_x(d<<1,L,mid,x,y,a);
		    else
		        add_x(d<<1|1,mid+1,R,x,y,a);
		}
		inline T sum_y(int d,int dy,int L,int R,int b,int t)
		{
		    if(L==b&&R==t)
		        return tree[d][dy];
		    int mid=(L+R)>>1;
		    if(mid>=t)
		        return sum_y(d,dy<<1,L,mid,b,t);
		    else 
				if(mid<b)
		        	return sum_y(d,dy<<1|1,mid+1,R,b,t);
		    else 
		        return sum_y(d,dy<<1,L,mid,b,mid)+
				sum_y(d,dy<<1|1,mid+1,R,mid+1,t);
		}
		inline T sum_x(int d,int L,int R,int l,int r,int b,int t)
		{
		    if(L==l&&R==r)
		        return sum_y(d,1,1,size,b,t);
		    int mid=(L+R)>>1;
		    if(mid>=r)
		        return sum_x(d<<1,L,mid,l,r,b,t);
		    else 
				if(mid<l)
		        	return sum_x(d<<1|1,mid+1,R,l,r,b,t);
		    else 
		        return sum_x(d<<1,L,mid,l,mid,b,t)+
				sum_x(d<<1|1,mid+1,R,mid+1,r,b,t);
		}
	public:
		inline matsegtree():size(0)
		/*构造函数:建造一棵空的线段树.
		时间复杂度:O(1). 
		*/
		{
			memset(tree,0,sizeof(tree));
		}
		inline void build(int n)
		/*建造函数:将二维线段树的大小设置为n*n.
		时间复杂度:O(1). 
		*/
		{
			size=n;
		}
		inline void clear()
		/*清空函数:清空线段树.
		时间复杂度:O(1). 
		*/
		{
			memset(tree,0,sizeof(tree));
			size=0;
		}
		inline void modify(int x,int y,T a)
		/*更改函数:将第[x,y]个数加上a.
		时间复杂度:O(log2 n). 
		*/
		{
			add_x(1,1,size,x+1,y+1,a);
		}
		inline T query_sum(int l,int r,int b,int t)
		/*求值函数:求二维区间[(l,r),(b,t)]的和.
		时间复杂度:O(log2 n). 
		*/
		{
			return sum_x(1,1,size,l+1,r+1,b+1,t+1);
		}
		inline T operator()(const int x,const int y)
		/*求值函数:求第[x,y]个元素的值.
		时间复杂度:O(log2 n). 
		*/
		{
			return query_sum(x,y,x,y);
		}
};
int main()
{
	
}
