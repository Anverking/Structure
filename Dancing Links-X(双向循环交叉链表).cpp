/*˫��ѭ����������(Dancing Links-X)ģ��*/
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
		//��ӵ�r��,cloumns[i]�����r�д�����Щ��
	    //����colums = {1,2,9}������01�����е�r�е�2����1��������� 
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
	    inline void remove(int c)//ɾ����c�� 
	    {
	        right[left[c]]=right[c];
	        left[right[c]]=left[c];
	        //��ɾ����ڵ� 
	        display(i,down,c)//������c�е�down�б�
	            display(j,right,i)//������c��ÿ���ڵ�
	                {
						down[up[j]]=down[j];
						up[down[j]]=up[j];
						size[col[j]]--;
					}//ɾ���������������нڵ� 
	    }
	    inline void restore(int c)//�ָ� = ɾ��������������� 
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
	    inline bool dance(int step=0)//stepΪ�ݹ���� 
	    {
	        if(right[head]==head)//�ҵ��� 
	        {
	            ansd=step;
	            return 1;
	        }
	        int c=right[head];//��һ��û��ɾ������ 
	        display(i,right,head)
	            if(size[i]<size[c])
	                c=i;
	        //̰���ҽڵ����ٵ�һ�У�����������ö���������
	        remove(c);//ɾ�� 
	        display(i,down,c)//c�б��µ�ÿһ���ڵ� 
	        {
	            //Ŀǰѡȡ��row[i]��������
	            //��ô��Ӧ���ѵ�row[i]�������ǵ�������Ҳ��ɾ��
	            ans[step]=row[i];
	            display(j,right,i)
	                remove(col[j]);
	            if(dance(step+1))
	                return 1;//����ҵ����ˣ�ֱ�ӷ���
	            //Ҫ��Ȼ��Ҫ�ָ����ҳ�����һ��i
	            display(j,left,i)
	                restore(col[j]); 
	        }
	        restore(c);
	        //�ָ�
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
