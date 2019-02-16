/*�ֵ���(Prefix Trie)ģ��*/
#include<iostream>
#include<cstring>
const int maxn=1e4;
class trie{
	private:
		int root,tot,child[maxn][26];
		bool flag[maxn];
	public:
		inline trie()
		/*���캯��:����һ�ÿ���.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			memset(child[1],0,sizeof(child[1]));
			flag[1]=false;
			root=tot=1;
		}
		inline void insert(const char*str)
		/*���뺯��:����һ���ַ���.
		ʱ�临�Ӷ�:O(Length). 
		*/
		{
			int*cur=&root;
			for(const char*p=str;*p;p++)
			{
				cur=&child[*cur][*p-'a'];
				if(*cur==0)
				{
					*cur=++tot;
					memset(child[tot],0,sizeof(child[tot]));
					flag[tot]=false;
				}
			}
			flag[*cur]=true;
		}
		inline bool query(const char*str)
		/*�жϺ���:�ж�һ���ַ����Ƿ����.
		ʱ�临�Ӷ�:O(Length). 
		*/
		{
			int*cur=&root;
			for(const char*p=str;*p&&*cur;p++)
				cur=&child[*cur][*p-'a'];
			return(*cur&&flag[*cur]);
		}
};
int main(){

}
