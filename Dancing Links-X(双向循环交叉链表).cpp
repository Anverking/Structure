/*双向循环交叉链表(Dancing Links-X)模板*/
#include<iostream>
#include<cstring>
#include<vector>
const int maxn=1e3;
class dancelinks
{
	private:
		#define display(i,a,s) for(int i=a[s];i!=s;i=a[i]) 
	    int cnt,sz;
	    int head;
	    int left[maxn],right[maxn],up[maxn],down[maxn];
	    int size[maxn]; 
	    int col[maxn],row[maxn];
	    int ans[maxn];
	    int ansd;
	public:
		inline dancelinks(){}
	    inline void build(int m)
	    {
	        head=0;
	        for(int i=0;i<=m;i++)
	        {
	            up[i]=i;
	            down[i]=i;
	            left[i]=i-1;
	            right[i]=i+1;
	        } 
	        right[m]=head;
	        left[head]=m;
	        sz=m+1;
	        memset(size,0,sizeof(size));
	    }
	    inline void addrow(int R,std::vector<int>columns)
		//添加第r行,cloumns[i]代表第r行存在哪些数
	    //例如colums = {1,2,9}，代表01矩阵中第r行第2个是1，如此类推 
	    {
	        int first=sz;
	        for(int i=0;i<columns.size();i++)
	        {
	            int c=columns[i];
	            left[sz]=sz-1;
	            right[sz]=sz+1;
	            down[sz]=c;
	            up[sz]=up[c]; 
	            down[up[c]]=sz;
	            up[c]=sz;
	            col[sz]=c;
	            row[sz]=R;
	            ++size[c];
	            ++sz; 
	        }
	        right[sz-1]=first ;
			left[first]=sz-1; 
	    }
	    inline void remove(int c)//删除第c列 
	    {
	        right[left[c]]=right[c];
	        left[right[c]]=left[c];
	        //先删虚拟节点 
	        display(i,down,c)//遍历第c列的down列表
	            display(j,right,i)//遍历第c列每个节点
	                {
						down[up[j]]=down[j];
						up[down[j]]=up[j];
						size[col[j]]--;
					}//删除上述遍历的所有节点 
	    }
	    inline void restore(int c)//恢复 = 删除逆操作，不解释 
	    {
	        display(i,up,c)
	            display(j,left,i)
	                {
						size[col[j]]++;
						down[up[j]]=j;
						up[down[j]]=j;
					}
	        right[left[c]]=c;
	        left[right[c]]=c;
	    }
	    inline bool dance(int step=0)//step为递归深度 
	    {
	        if(right[head]==head)//找到解 
	        {
	            ansd=step;
	            return 1;
	        }
	        int c=right[head];//第一个没被删除的列 
	        display(i,right,head)
	            if(size[i]<size[c])
	                c=i;
	        //贪心找节点最少的一列，这样可以让枚举情况最少
	        remove(c);//删除 
	        display(i,down,c)//c列表下的每一个节点 
	        {
	            //目前选取第row[i]行来覆盖
	            //那么就应当把第row[i]行所覆盖的其他列也给删除
	            ans[step]=row[i];
	            display(j,right,i)
	                remove(col[j]);
	            if(dance(step+1))
	                return 1;//如果找到解了，直接返回
	            //要不然还要恢复并且尝试下一个i
	            display(j,left,i)
	                restore(col[j]); 
	        }
	        restore(c);
	        //恢复
	        return 0; 
	    }
	    inline void getans(std::vector<int>Ans)
	    {
	    	Ans.clear();
	        for(int i=0;i<ansd;i++)
	            Ans.push_back(ans[i]);
	    }
	    #undef display
};
int main(){
	
}
