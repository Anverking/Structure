/*��׺�Զ���(Suffix Automaton)ģ��*/
#include<iostream>
#include<cstring>
const int maxn=1e3;
class sufmaton
{
	private:
    	int child[maxn][26];
    	int pre[maxn],step[maxn];
    	int last,tot;
    	int Min[maxn],Max[maxn];
    public:
    	inline sufmaton():last(0),tot(0)
    	/*���캯��:����һ���յ��Զ���.
		ʱ�临�Ӷ�:O(1). 
		*/
    	{
        	memset(child[0],-1,sizeof(child[0]));
        	pre[0]=-1;
			step[0]=0;
        	Min[0]=Max[0]=0;
    	}
    	inline void clear()
    	/*��պ���:����Զ���.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			last=tot=0;
			memset(child[0],-1,sizeof(child[0]));
			pre[0]=-1;
			step[0]=0;
			Min[0]=Max[0]=0;
		}
    	inline void extend(int c)
    	/*���뺯��:���Զ���ĩβ����һ���ַ�.
		ʱ�临�Ӷ�:O(log2 n). 
		*/
    	{
        	c-='a';
        	int p=last,np=++tot;
        	step[np]=step[p]+1;
        	memset(child[np],-1,sizeof(child[np]));
        	Min[np]=Max[np]=step[np];
        	while(~p&&child[p][c]==-1)
				child[p][c]=np,
				p=pre[p];
        	if(p==-1)
				pre[np]=0;
        	else
			{
            	int q=child[p][c];
            	if(step[q]!=step[p]+1){
                	int nq=++tot;
                	memcpy(child[nq],child[q],sizeof(child[q]));
                	step[nq]=step[p]+1;
                	Min[nq]=Max[nq]=step[nq];
                	pre[nq]=pre[q];
                	pre[q]=pre[np]=nq;
                	while(~p&&child[p][c]==q)
						child[p][c]=nq,
						p=pre[p];
            	}
            	else 
					pre[np]=q;
        	}
        	last=np;
    	}
    	inline void find(const char*s)
    	/*ƥ�亯��:���ַ���s����ƥ��.
		ʱ�临�Ӷ�:O(n). 
		*/
    	{
        	int len=strlen(s);
        	int u=0;
        	int tmp=0;
        	for(int i=0;i<=tot;i++)
        		Max[i]=0;
        	for(int i=0;i<len;i++)
        	{
            	int c=s[i]-'a';
            	if(~child[u][c])
					tmp++,u=child[u][c];
            	else
				{
                	while(~u&&child[u][c]==-1)
						u=pre[u];
                	if(~u)
						tmp=step[u]+1,
						u=child[u][c];
                	else 
						tmp=0,
						u=0;
            	}
            	Max[u]=std::max(Max[u],tmp);
        	}
        	for(int i=tot;i>=1;i--)
				Max[pre[i]]=std::max(Max[pre[i]],Max[i]);
        	for(int i=0;i<=tot;i++)
				Min[i]=std::min(Min[i],Max[i]);
    	}
    	inline int calc()
    	/*��ֵ����:��������ƥ�䴮��������ִ��ĳ���.
		ʱ�临�Ӷ�:O(n). 
		*/
    	{
        	int res=0;
        	for(int i=0;i<=tot;i++)
				res=std::max(res,Min[i]);
        	return res;
    	}
};
int main(){

}
