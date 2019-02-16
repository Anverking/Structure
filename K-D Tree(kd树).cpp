#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
const int maxn=1e4;
const double INF=0x3f3f3f3f;
template<unsigned int dem>
class kdtree{
	private:
		class data
		{
			public:
			    double pos[dem];
			    int id;
		}tree[maxn],op,point;
		int split[maxn],now;		 
		bool use[maxn];
		double ans;
		int id;
		double var[dem];
		class cmp
		{
			public:
				inline bool operator()(const data a,const data b)
				{
				    return a.pos[split[now]]<b.pos[split[now]];
				}
		};
		inline void _build(int L,int R)
		{
		    if(L>R)
				return;
		    int mid=(L+R)>>1;
		    for(int pos=0;pos<dem;pos++)
		    {
		        double ave=var[pos]=0.0;
		        for(int i=L;i<=R;i++)
		            ave+=tree[i].pos[pos];
		        ave/=(R-L+1);
		        for(int i=L;i<=R;i++)
		            var[pos]+=(tree[i].pos[pos]-ave)*
					(tree[i].pos[pos]-ave);
		        var[pos]/=(R-L+1);
		    }
		    split[now=mid]=0;
		    for(int i=1;i<dem;i++)
		        if(var[split[mid]]<var[i])
					split[mid]=i;
		    nth_element(tree+L,tree+mid,tree+R+1,cmp());
		    _build(L,mid-1);
		    _build(mid+1,R);
		}
		inline void query(int L,int R)
		{
		    if(L>R)
				return;
		    int mid=(L+R)>>1;
		    double dis=0;
		    for(int i=0;i<dem;i++)
		        dis+=(op.pos[i]-tree[mid].pos[i])*(op.pos[i]-tree[mid].pos[i]);
		    if(!use[tree[mid].id] && dis<ans)
		    {
		        ans=dis; 
		        point=tree[mid]; 
		        id=tree[mid].id;
		    }
		    double radius=(op.pos[split[mid]]-tree[mid].pos[split[mid]])*
			(op.pos[split[mid]]-tree[mid].pos[split[mid]]);
		    if(op.pos[split[mid]]<tree[mid].pos[split[mid]])
		    {
		        query(L,mid-1);
		        if(radius<=ans)
					query(mid+1,R);
		    }
		    else
		    {
		        query(mid+1,R);
		        if(radius<=ans)
					query(L,mid-1);
		    }
		}
	public:
		inline kdtree():ans(0),id(0),now(0){
			memset(split,0,sizeof(split));
			memset(use,0,sizeof(use));
			memset(var,0,sizeof(var));
		}
		inline void build(double a[][dem],int n)
		{
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<dem;j++)
					tree[i+1].pos[j]=a[i][j];
				tree[i+1].id=i+1;
			}
			_build(1,n);
		}
		inline std::vector<double>query_min(double q[dem],
		int m,int n)
		{
			std::vector<double>Ans;
			memset(use,0,sizeof(use)); 
            for(int i=0;i<dem;i++)
                op.pos[i]=q[i];
            while(m--)
            {
                ans=(INF*INF);
                query(1,n);
                for(int i=0;i<dem;i++)
                    Ans.push_back(point.pos[i]);
                use[id]=1;
            }
            return Ans;
		}
};
int main()
{
	
}
