/*zkw线段树(Zkw Segment Tree)模板*/
#include<iostream>
#include<cstring>
const int maxn=1e4;
template<class T>
class zkwtree{
	private:
		T tree[maxn<<2],add[maxn<<2];
		int cnt;
	public:
		inline zkwtree():cnt(1)
		/*构造函数:建造一棵空的树.
		时间复杂度:O(1). 
		*/
		{
			memset(tree,0,sizeof(tree));
			memset(add,0,sizeof(add));
		}
		inline void build(T*a,int n)
		/*建造函数:对长度为n的数组a建造树.
		时间复杂度:O(nlog2 n). 
		*/
		{
    		for(cnt=1;cnt<=n+1;cnt<<=1);
    		int j=0;
    		for(int i=cnt+1;i<=cnt+n;i++)
				tree[i]=a[j++];
    		for(int i=cnt-1;i>=1;i--){
        		tree[i]=std::min(tree[i<<1],tree[i<<1|1]);
        		tree[i<<1]-=tree[i];
				tree[i<<1|1]-=tree[i];
    		}
		} 
		inline T operator[](const int i)
		/*求值函数:求第i个元素的值.
		时间复杂度:O(log2 n). 
		*/
		{
			return query_min(i,i);
		}
		inline void modify(const int i,T d)
		/*更改函数:将第i个数的值加上d.
		时间复杂度:O(log2 n). 
		*/
		{
			update(i,i,d);
		}
		inline void update(int s,int t,T k)
		/*更改函数:将区间[s,t]的所有元素的值加上k.
		时间复杂度:O(log2 n). 
		*/
		{
			s++,t++; 
    		int tmp;
    		for(s+=cnt-1,t+=cnt+1;s^t^1;s>>=1,t>>=1){
        		if(~s&1)tree[s^1]+=k;
        		if(t&1)tree[t^1]+=k;
        		tmp=std::min(tree[s],tree[s^1]);
        		tree[s]-=tmp;
				tree[s^1]-=tmp; 
				tree[s>>1]+=tmp;
        		tmp=std::min(tree[t],tree[t^1]);
        		tree[t]-=tmp;
				tree[t^1]-=tmp;
				tree[t>>1]+=tmp;
    		}
    		for(;s!=1;s>>=1){
        		tmp=std::min(tree[s],tree[s^1]);
        		tree[s]-=tmp;
				tree[s^1]-=tmp;
				tree[s>>1]+=tmp;
    		}
		} 
		inline T query_min(int s,int t)
		/*求值函数:求区间[s,t]中的最小值.
		时间复杂度:O(log2 n). 
		*/
		{
			s++,t++;
    		T sAns=0,tAns=0;
    		s+=cnt,t+=cnt;
    		if(s!=t){
        		for(;s^t^1;s>>=1,t>>=1) {
           		 	sAns+=tree[s];
					tAns+=tree[t];
           		 	if(~s&1)sAns=std::min(sAns,tree[s^1]);
            		if(t&1)tAns=std::min(tAns,tree[t^1]);
        		}
    		}
    		T ans=std::min(sAns+tree[s],tAns+tree[t]);
    		while(s>1)ans+=tree[s>>=1];
    		return ans;
		}
		inline T query_max(int s,int t)
		/*求值函数:求区间[s,t]中的最大值.
		时间复杂度:O(log2 n). 
		*/
		{
			s++,t++;
    		T sAns=0,tAns=0;
    		s+=cnt,t+=cnt;
    		if(s!=t){
      		  	for(;s^t^1;s>>=1,t>>=1) {
       		     	sAns+=tree[s];tAns+=tree[t];
            		if(~s&1)sAns=std::max(sAns,tree[s^1]);
            		if(t&1)tAns=std::max(tAns,tree[t^1]);
        		}
    		}
    		T ans=std::max(sAns+tree[s],tAns+tree[t]);
    		while(s>1)ans+=tree[s>>=1];
    		return ans;
		}
		inline void clear()
		/*清空函数:清空整棵树.
		时间复杂度:O(1). 
		*/
		{
			cnt=1;
			memset(tree,0,sizeof(tree));
			memset(add,0,sizeof(add));
		}
};
int main(){

}
