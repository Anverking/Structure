/*Link-Cut��(Link-Cut Tree)ģ��*/
#include<iostream>
#include<cstring>
const int maxn=1e7;
template<class T>
class linkcut{
	private:
		int cnt;
		int father[maxn],child[maxn][2];
		T value[maxn],sum[maxn];
		int stk[maxn];
		bool rev[maxn];
		inline bool isroot(int x){
    		return child[father[x]][0]==x||child[father[x]][1]==x;
		}
		inline void update(int x){
    		sum[x]=sum[child[x][0]]+sum[child[x][1]]+value[x];
		}
		inline void reverse(int x){
			int t=child[x][0];
			child[x][0]=child[x][1];
			child[x][1]=t;
			rev[x]^=1;
		}
		inline void pushdown(int x){
    		if(rev[x]){
        		if(child[x][0])reverse(child[x][0]);
        		if(child[x][1])reverse(child[x][1]);
        		rev[x]=0;
    		}
		}
		inline void rotate(int x){
    		int y=father[x],z=father[y],k=child[y][1]==x,w=child[x][k^1];
    			if(isroot(y))
					child[z][child[z][1]==y]=x;
				child[x][k^1]=y;
				child[y][k]=w;
    			if(w)
					father[w]=y;
				father[y]=x;
				father[x]=z;
    			update(y);
		}
		inline void splay(int x){
    		int y=x,z=0;
    		stk[++z]=y;
    		while(isroot(y))
				stk[++z]=y=father[y];
    		while(z)
				pushdown(stk[z--]);
    		while(isroot(x))
			{
        		y=father[x];
				z=father[y];
        		if(isroot(y))
            		rotate((child[y][0]==x)^(child[z][0]==y)?x:y);
        		rotate(x);
    		}
    		update(x);
		}
		inline void access(int x){
    		for(int y=0;x;x=father[y=x])
        		splay(x),child[x][1]=y,update(x);
		}
		inline void makeroot(int x){
    		access(x);
			splay(x);
    		reverse(x);
		}
	public:
		inline linkcut():cnt(0)
		/*���캯��:����һ�ÿյ���.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			memset(father,0,sizeof(father));
			memset(rev,0,sizeof(rev));
			memset(child,0,sizeof(child));
			memset(stk,0,sizeof(stk));
		}	
		inline int creat(T x)
		/*���캯��:����һ���µĽڵ�.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			cnt++;
			value[cnt]=sum[cnt]=x;
			father[cnt]=child[cnt][0]=child[cnt][1]=rev[cnt]=0;
			return cnt;
		}
		inline int root(int x)
		/*��ֵ����:��x�������ĸ��ı��.
		ʱ�临�Ӷ�:O(log2 n). 
		*/
		{
    		access(x);
			splay(x);
    		while(child[x][0])
				pushdown(x),x=child[x][0];
    		splay(x);
    		return x;
		}
		inline void split(int x,int y)
		/*���캯��:��ȡx��y��·��.
		ʱ�临�Ӷ�:O(log2 n). 
		*/
		{
    		makeroot(x);
    		access(y);
			splay(y);
		}
		inline void link(int x,int y)
		/*���캯��:���һ��x��y�ı�.
		ʱ�临�Ӷ�:O(log2 n). 
		*/
		{
    		makeroot(x);
    		if(root(y)!=x)
				father[x]=y;
		}
		inline void modify(int x,T d)
		/*���ĺ���:����x�Žڵ��ֵ.
		ʱ�临�Ӷ�:O(log2 n). 
		*/
		{
			splay(x);
			value[x]=d;
			update(x);
		}
		inline T query_sum(int x,int y)
		/*��ֵ����:��x��y·���ϵ�ֵ��.
		ʱ�临�Ӷ�:O(log2 n). 
		*/
		{
			split(x,y);
			return sum[y];
		}
		inline T operator[](const int i)
		/*��ֵ����:��i�Žڵ��ֵ.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			return value[i];
		}
		inline void cut(int x,int y)
		/*���캯��:ɾ��x��y�ı�.
		ʱ�临�Ӷ�:O(log2 n). 
		*/
		{
    		makeroot(x);
    		if(root(y)==x&&father[x]==y&&!child[x][1]){
        		father[x]=child[y][0]=0;
        		update(y);
    		}
		}
};
int main(){

} 
