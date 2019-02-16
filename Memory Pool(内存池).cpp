/*�ڴ��(Memory Pool)ģ��*/
#include<iostream>
#include<list>
template<class T>
class mempool{
	private:
		std::list<T*>buf;
	public:
		inline mempool(){}
		inline T*creat()
		/*���캯��:���ڴ��ĩβ����һ���µ��ڴ�.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			buf.push_back(new T());
			return buf.back();
		}
		inline T*operator[](const int i)
		/*��ֵ����:���ڴ���еĵ�i���ڴ�.
		ʱ�临�Ӷ�:O(n). 
		*/
		{
			int j=0;
			for(typename std::list<T*>
			::iterator it=buf.begin();
			it!=buf.end()&&j<=i;j++,it++
			)
			if(j==i)
				return *it;
			return NULL;
		}
		inline void free(const int i)
		/*���캯��:�ͷ��ڴ���еĵ�i���ڴ�.
		ʱ�临�Ӷ�:O(n). 
		*/
		{
			int j=0;
			for(typename std::list<T*>
			::iterator it=buf.begin();
			it!=buf.end()&&j<=i;j++,it++
			)
			if(j==i){
				delete *it;
				buf.erase(it);
				return;
			}
		}
		inline void clear()
		/*��պ���:����ڴ��,���ͷ������ڴ�.
		ʱ�临�Ӷ�:O(n). 
		*/
		{
			for(typename std::list<T*>
			::iterator it=buf.begin();
			it!=buf.end();it++
			)
				delete*it;
			buf.clear();
		}
}; 
int main(){

}
