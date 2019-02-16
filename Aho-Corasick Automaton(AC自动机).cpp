/*AC�Զ���(Aho-Corasick Automaton)ģ��*/
#include<iostream>
#include<queue>
#include<cstring>
const int maxn=1e4;
class automaton{
	private:
    	int cnt;
    	int edge[maxn],fail[maxn],trie[maxn][26];
    public:
    	inline automaton():cnt(0)
		/*���캯��:����һ���յ��Զ���.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
    		memset(trie,0,sizeof(trie));
    		memset(edge,0,sizeof(edge));
    	}
   	 	inline void insert(const char*s)
		/*���뺯��:����һ��ģʽ��s.
		ʱ�临�Ӷ�:O(Length). 
		*/	
		{
   	   		int p=0;
        	for(int i=0;s[i];i++){
            	int k=s[i]-'a';
        	    if(!trie[p][k])
					trie[p][k]=++cnt;
        	    p=trie[p][k];
        	}
        	edge[p]++;
    	}
    	inline void build()
		/*���캯��:�����Զ���.
		ʱ�临�Ӷ�:O(nlog2 n).
		*/
		{
        	std::queue<int>q;
        	memset(fail,0,sizeof(fail));
        	for(int i=0;i<26;i++)
				if(trie[0][i])
					q.push(trie[0][i]);
        	while(!q.empty()){
            	int k=q.front();
				q.pop();
            	for(int i=0;i<26;i++){
            	    if(trie[k][i]){
                	    fail[trie[k][i]]=trie[fail[k]][i];
                	    q.push(trie[k][i]);
                	}
                	else trie[k][i]=trie[fail[k]][i];
            	}
        	}
    	}
    	inline int query(const char*t)
		/*ƥ�亯��:���ж��ٸ�ģʽ�����ı���t��ƥ�䵽.
		ʱ�临�Ӷ�:O(Length). 
		*/
		{
        	int p=0,res=0;
        	for(int i=0;t[i];i++){
        	    p=trie[p][t[i]-'a'];
        	    for(int j=p;j&&~edge[j];j=fail[j])
					res+=edge[j],edge[j]=-1;
        	}
        	return res;
    	}
    	inline void clear()
		/*��պ���:����Զ���.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
    		cnt=0;
    		memset(trie,0,sizeof(trie));
    		memset(edge,0,sizeof(edge));
    	}
}; 
int main(){

}
