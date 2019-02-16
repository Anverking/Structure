/*��ʽǰ����(Linked Forward Star)ģ��*/
#include<iostream>
#include<cstring>
#include<queue>
const int INF=0x3f3f3f3f;
const int maxn=1e4;
template<class T>
class linkstar{
	private:
		class node{
			public:
    			int from,to;
				T value;
		}edge[maxn<<1];
		T dist[maxn];
		int head[maxn],cnt[maxn],tot,vis[maxn],que[maxn],n,neg;
	public:
		typedef std::pair<T,int> P;
		inline linkstar():tot(0),n(0),neg(0)
		/*���캯��:����һ����ͼ.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			memset(head,0,sizeof(head));
		}
		inline T query(int t)
		/*��ֵ����:��Դ�㵽t�����·.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			return dist[t];
		}
		inline void insert(int u,int v,T w)
		/*���뺯��:����һ��u��v�ı�ȨΪw�������.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			if(w<0)
				neg=1;
			edge[++tot].from=head[u];
			edge[tot].to=v;
			edge[tot].value=w;
			head[u]=tot;
			n=std::max(n,std::max(u,v));
		}
		inline bool build(int s)
		/*���캯��:����sԴ������·,�������Ƿ���ڸ���. 
		ʱ�临�Ӷ�:O((m+n)log2 n)��<=O(mn). 
		*/
		{
			if(neg)
			{
				int l,r;
			    l=r=0;
			    memset(dist,INF,sizeof(dist));
			    memset(vis,0,sizeof(vis));
				memset(cnt,0,sizeof(cnt));
				memset(que,0,sizeof(que));
			    vis[s]=1;
				cnt[s]=1;
				dist[s]=0;
			    que[r++]=s;
			    while(l!=r)
			    {
			        int u=que[l++];
			        if(l>n)
						l=0;
			        vis[u]=0;
			        for(int i=head[u];i;i=edge[i].from)
			        {
			            if(dist[edge[i].to]>dist[u]+edge[i].value)
			            {    
			                dist[edge[i].to]=dist[u]+edge[i].value;
			                cnt[edge[i].to]=cnt[u]+1;
			                if(cnt[edge[i].to]>=n&&edge[i].value<0)
			                    return 1;
			                if(!vis[edge[i].to])
			                 {
			                    vis[edge[i].to]=1;
			                    if(dist[edge[i].to]>dist[que[l]])
			                    {
			                        l--;
			                        if(l<0)
			                            l=n;
			                        que[l]=edge[i].to;
			                    }
			                    else
			                    {
			                        que[r++]=edge[i].to;
			                        if(r>n)
			                            r=0;
			                    }
			                }
			            }
			        }
			    }
			    return 0;
			}
			memset(dist,INF,sizeof(dist));
    		std::priority_queue<P,std::vector<P>,std::greater<P> >Q;
    		dist[s]=0;
    		Q.push(P(0,s));
    		while(!Q.empty()){
        		P p=Q.top();
        		Q.pop();
        		int v=p.second;
        		if(dist[v]<p.first)continue;
        		for(int i=head[v];i;i=edge[i].from){
            		node e=edge[i];
            		if(e.value+dist[v]<dist[e.to]){
                		dist[e.to]=e.value+dist[v];
                		Q.push(P(dist[e.to],e.to));
            		}
        		}
    		}
    		return 0;
		}
		inline void clear()
		/*��պ���:���ͼ.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			tot=n=neg=0;
			memset(head,0,sizeof(head));
		}
};
int main(){


}
