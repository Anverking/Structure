/*AC自动机(Aho-Corasick Automaton)模板*/
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
		/*构造函数:建造一个空的自动机.
		时间复杂度:O(1). 
		*/
		{
    		memset(trie,0,sizeof(trie));
    		memset(edge,0,sizeof(edge));
    	}
   	 	inline void insert(const char*s)
		/*插入函数:插入一个模式串s.
		时间复杂度:O(Length). 
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
		/*建造函数:建造自动机.
		时间复杂度:O(nlog2 n).
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
		/*匹配函数:求有多少个模式串在文本串t中匹配到.
		时间复杂度:O(Length). 
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
		/*清空函数:清空自动机.
		时间复杂度:O(1). 
		*/
		{
    		cnt=0;
    		memset(trie,0,sizeof(trie));
    		memset(edge,0,sizeof(edge));
    	}
}; 
int main(){

}
