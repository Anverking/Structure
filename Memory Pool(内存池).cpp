/*内存池(Memory Pool)模板*/
#include<iostream>
#include<list>
template<class T>
class mempool{
	private:
		std::list<T*>buf;
	public:
		inline mempool(){}
		inline T*creat()
		/*建造函数:在内存池末尾申请一块新的内存.
		时间复杂度:O(1). 
		*/
		{
			buf.push_back(new T());
			return buf.back();
		}
		inline T*operator[](const int i)
		/*求值函数:求内存池中的第i块内存.
		时间复杂度:O(n). 
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
		/*建造函数:释放内存池中的第i块内存.
		时间复杂度:O(n). 
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
		/*清空函数:清空内存池,并释放所有内存.
		时间复杂度:O(n). 
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
