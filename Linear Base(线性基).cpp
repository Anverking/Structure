/*线性基(Linear Base)模板*/ 
#include<iostream>
const int maxn=60;
template<class T>
class linear_base{
	private:
		T arr[maxn+1];
    public:
	    inline void insert(T x)
		{
	        for(int i=maxn;i>=0;i--)
	            if(x&((T)(1)<<i))
	                if(!arr[i])
					{
						arr[i]=x;
						return;
					}
	                else 
						x^=arr[i];
	    }
	    inline bool check(T x)
		{
	        for(int i=maxn;i>=0;i--)
	            if(x&((T)(1)<<i))
	                if(!arr[i])
						return 0;
	                else 
						x^=arr[i];
	        return 1;
	    }
	    inline T query_max(){
	        T res=0;
	        for(int i=maxn;i>=0;i--)
				if((res^arr[i])>res)
					res^=arr[i];
	        return res;
	    }
	    inline T query_min(){
	        for(int i=0;i<=maxn;i++)
				if(arr[i])
					return arr[i];
	    }
	    inline T query_kth(int k){
	        T tmp[maxn+1],res=0,cnt=0;
	        for(T i=0;i<=maxn;i++)
			{
	            for(int j=i-1;j>=0;j--)
					if(arr[i]&((T)(1)<<j))
						arr[i]^=arr[j];
	            if(arr[i])
					tmp[cnt++]=arr[i];
	        }
	        for(int i=0;i<cnt;i++)
				if(k&((T)(1)<<i))
					res^=tmp[i];
	        return res;
	    }
}; 
int main()
{
	
}
