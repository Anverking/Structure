/*ɢ����(Hash Tree)ģ��*/
#include<iostream>
#include<cstring>
const int maxn=32;
const int prime[10]={2,3,5,7,11,13,17,19,23,29};
inline unsigned long long myhash(int key,int level)
{
	return key%prime[level%10];
}
template<class T1,class T2,unsigned long long(hash)(T1,int)=myhash>
class hashtree
{
	private:
		class hashnode
		{
			public:
				inline hashnode(){
					occupied=0;
					memset(child,NULL,maxn*sizeof(hashnode*));
				} 
				inline hashnode(T1 key,T2 value){
					m_key=key;
					m_value=value;
					occupied=0;
					memset(child,NULL,maxn*sizeof(hashnode*));
				}
				T1 m_key;
				T2 m_value;
				bool occupied;
				hashnode*child[maxn];
		};
		hashnode*root;
		inline void _insert(hashnode*node,int level,T1 key,T2 value)
		{
			if(!node->occupied)
			{
				node->m_key=key;
				node->m_value=value;
				node->occupied=1;
				return;
			}
			int index=hash(key,level);
			if(!node->child[index])
			{
				node->child[index]=new hashnode;
			}
			level++;
			_insert(node->child[index],
			level,key,value);
		}
		inline T2& find(hashnode*node,int level,T1 key)
		{
			if(node->occupied)
				if(node->m_key==key)
					return node->m_value; 
			int index=hash(key,level);
			if(!node->child[index])
				return 0;
			level++;
			return find(node->child[index],
			level,key);
		}
		inline void _remove(hashnode*node,int level,T1 key)
		{
			if(node->occupied)
			{
				if(node->m_key==key)
				{
					node->occupied=0;
					return;
				}
			}
			int index=hash(key,level);
			if(!node->child[index])
				return;
			level++;
			_remove(node->child[index],level,key);
		}
	public:
		inline hashtree()
		/*���캯��:����յ�ɢ����.
		ʱ�临�Ӷ�:O(1).
		*/
		{
			root=new hashnode;
		}
		inline void insert(T1 key,T2 value)
		/*���뺯��:����һ��ӳ��key-value.
		ʱ�临�Ӷ�:O(loglogn). 
		*/
		{
			_insert(root,0,key,value);
		}
		inline T2& operator[](T1 key)
		/*��ֵ����:��key��ӳ��.
		ʱ�临�Ӷ�:O(loglogn). 
		*/
		{
			return find(root,0,key);
		}
		inline void remove(T1 key)
		/*ɾ������:ɾ��key��ӳ��.
		ʱ�临�Ӷ�:O(loglogn). 
		*/
		{
			_remove(root,0,key);
		}
		inline void clear()
		{
			root=new hashnode;
		} 
};
int main()
{

}
