/*���ȶ���(Priority Queue)ģ��*/
#include<iostream>
#include<cstring>
const int maxn=1e4;
const int INF=0x3f3f3f3f; 
template<class T> 
class prioque{
	private:
		T heap[maxn];
		int idx[maxn],pos[maxn],cnt,len;
		inline void up(int i){
			T x=heap[i];
			int y=idx[i];
			for(int j=i/2;j>=1;j/=2){
				if(heap[j]>x){
					heap[i]=heap[j];
					idx[i]=idx[j];
					pos[idx[i]]=i;
					i=j;
				}
				else 
					break;
			}
			heap[i]=x;
			idx[i]=y;
			pos[y]=i;
		}
		inline void down(int i){
			T x=heap[i];
			int y=idx[i];
			for(int j=i*2;j<=len;j*=2){
				j+=(j<len&&heap[j]>heap[j+1]);
				if(heap[j]<x){
					heap[i]=heap[j];
					idx[i]=idx[j];
					pos[idx[i]]=i;
					i=j;
				}
				else 
					break;
			}
			heap[i]=x;
			idx[i]=y;
			pos[y]=i;
		}
	public:
		inline prioque():cnt(0),len(0)
		/*���캯��:����һ���յĶ���.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			memset(idx,0,sizeof(idx));
			memset(pos,0,sizeof(pos));
		}
		inline void push(T v)
		/*���뺯��:����β����һ��Ԫ��.
		ʱ�临�Ӷ�:O(log2 n). 
		*/
		{
			heap[++len]=v;
			idx[len]=++cnt;
			pos[idx[len]]=len;
			up(len);
		}
		inline T top()
		/*��ֵ����:���������С��Ԫ��.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			return heap[1];
		}
		inline int pop()
		/*ɾ������:ɾ����СԪ��,����������ԭ�����е�λ�ñ��.
		ʱ�临�Ӷ�:O(log2 n). 
		*/
		{
			std::swap(heap[1],heap[len]);
			std::swap(idx[1],idx[len--]);
			pos[idx[1]]=1;
			down(1);
			return idx[len+1]-1;
		}
		inline T operator[](const int i)
		/*��ֵ����:����ԭ�����еĵ�i��Ԫ��.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			return heap[pos[i+1]];
		}
		inline void modify(int i,T v)
		/*���ĺ���:����ԭ�����еĵ�i��Ԫ�ص�ֵ��Ϊv.
		ʱ�临�Ӷ�:O(log2 n). 
		*/
		{
			heap[pos[i+1]]=v;
			down(pos[i+1]);
			up(pos[i+1]);
		}
		inline void remove(int i)
		/*ɾ������:ɾ����ԭ�����еĵ�i��Ԫ��.
		ʱ�临�Ӷ�:O(log2 n). 
		*/
		{
			heap[pos[i+1]]=-INF;
			up(pos[i+1]);
			pop();
		}
		inline bool empty()
		/*�жϺ���:�ж϶����Ƿ�Ϊ��.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			return !len;
		}
		inline int size()
		/*��ֵ����:����еĳ�.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			return len;
		}
		inline void clear()
		/*��պ���:��ն���.
		ʱ�临�Ӷ�:O(1). 
		*/
		{
			cnt=len=0;
			memset(idx,0,sizeof(idx));
			memset(pos,0,sizeof(pos));
		}
};
int main(){

}
