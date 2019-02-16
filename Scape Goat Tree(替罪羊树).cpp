/*替罪羊树(Scape Goat Tree)模板*/
#include<iostream>
#include<cstring>
const int maxn=1e7;
const double alpha=0.75;
template<class T>
class scapegoat{
	private:
    	int ncnt,root,sz;
    	int child[maxn][2],siz[maxn];
		T value[maxn];
		int cnt[maxn],cur[maxn],father[maxn];
		inline int isbad(int x){
        	return 
			(double)siz[x]*alpha>
			std::max(siz[child[x][0]],siz[child[x][1]]);
    	}
    	inline void recycle(int k){
        	if(!k)
				return;
        	recycle(child[k][0]);
        	cur[++ncnt]=k;
        	recycle(child[k][1]);
    	}
    	inline int build(int l,int r){
        	if(l>r)
				return 0;
        	int mid=(l+r)>>1,id=cur[mid];
        	father[child[id][0]=build(l,mid-1)]=id;
        	father[child[id][1]=build(mid+1,r)]=id;
        	siz[id]=siz[child[id][0]]+siz[child[id][1]]+1;
        	return id;
    	}
    	inline void rebuild(int k){
        	ncnt=0;
			recycle(k);
        	int f=father[k],
			chk=(child[f][1]==k),id=build(1,ncnt);
        	father[child[f][chk]=id]=f;
        	if(k==root)
				root=id;
    	}
    	public:
    		inline scapegoat():sz(0),root(0){}
    		inline void clear()
			/*清空函数:清空整棵树.
			时间复杂度:O(1). 
			*/
			{
    			sz=root=0;
    		}
    		inline T operator[](const int i)
			/*求值函数:求i号节点的值.
			时间复杂度:O(1). 
			*/
			{
    			return value[i];
    		}
    		inline int size()
			/*求值函数:求树的大小.
			时间复杂度:O(1). 
			*/
			{
    			return siz[root];
    		} 
    		inline bool empty()
			/*判断函数:判断树是否为空.
			时间复杂度:O(1). 
			*/
			{
    			return !siz[root];
    		}
    		inline void insert(T x)
			/*插入函数:在树中插入值x.
			时间复杂度:O(log2 n). 
			*/
			{
        		if(!root)
				{
					value[root=++sz]=x,
					siz[root]=1,
					father[root]=0;
					return;
				}
       			int tmp=root;
        		while(1)
				{
            		siz[tmp]++;
            		int f=tmp,chk=(x>=value[tmp]);
					tmp=child[tmp][chk];
            		if(!tmp){
                		siz[++sz]=1,
						value[sz]=x,
						father[sz]=f,
						child[f][chk]=sz;
                		break;
            		}
        		}
        		int flag=0;
        		for(int i=sz;i;i=father[i])
					if(!isbad(i))
						flag=i;
        		if(flag)
					rebuild(flag);
    		}
    		inline int find(T x)
			/*查找函数:查找值为x的节点编号.
			时间复杂度:O(log2 n). 
			*/
			{
        		int tmp=root;
        		while(tmp){
            		if(x==value[tmp])
						return tmp;
            		int chk=(x>=value[tmp]);
            		tmp=child[tmp][chk];
        		}
        		return tmp;
    		}
    		inline void remove(T x)
			/*删除函数:删除值为x的节点.
			时间复杂度:O(log2 n). 
			*/
			{
    			int k=find(x);
    			if(!k)	
    				return;
        		if(child[k][0]&&child[k][1]){
            		int tmp=child[k][0];
            		while(child[tmp][1]) 
						tmp=child[tmp][1];
            		value[k]=value[tmp];
					k=tmp;
        		}
        		int s=child[k][0]?child[k][0]:child[k][1],
				f=father[k],
				chk=(child[f][1]==k);
        		child[f][chk]=s;
				father[s]=f;
        		for(int i=f;i;i=father[i])
					siz[i]--;
        		if(root==k)
					root=s;
    		}
    		inline int getrank(T x)
			/*求值函数:求值x在树中是第几小的.
			时间复杂度:O(log2 n). 
			*/
			{
        		int tmp=root,res=0;
        		while(tmp)
				{
            		if(x<=value[tmp])
						tmp=child[tmp][0];
            		else 
						res+=siz[child[tmp][0]]+1,
						tmp=child[tmp][1];
        		}
        		return res+1;
    		}
    		inline int getkth(int k)
			/*求值函数:求树中第k小的节点编号.
			时间复杂度:O(log2 n). 
			*/
			{
        		int tmp=root;
        		while(tmp)
				{
            		if(k<=siz[child[tmp][0]])
					{
                		tmp=child[tmp][0];
						continue;
            		}
            		k-=siz[child[tmp][0]];
            		if(k==1)
						return tmp;
					k--;
            		tmp=child[tmp][1];
        		}
    		}
    		inline int prev(T x)
			/*求值函数:求树中比x小且最大的节点编号.
			时间复杂度:O(log2 n). 
			*/
			{
        		int ret=0,tmp=root;
        		while(tmp)
				{
            		if(value[tmp]<x&&value[tmp]>value[ret])
						ret=tmp,
						tmp=child[tmp][1];
            		else 
						tmp=child[tmp][0];
        		}
        		return ret;
    		}
    		inline int succ(T x)
			/*求值函数:求树中比x大且最小的节点编号.
			时间复杂度:O(log2 n). 
			*/
			{
        		int ret=0,tmp=root;
        		while(tmp){
            		if(value[tmp]>x&&value[tmp]<value[ret])
						ret=tmp,
						tmp=child[tmp][0];
            		else 
						tmp=child[tmp][1];
        		}
        		return ret;
    		}
};
int main()
{	

}
