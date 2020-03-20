#include <cstdio>
#include <set>
#include <queue>
#include <cstring>
using namespace std;
const int MAXN=50010;
const int MAXM=50010;
multiset<int> s[MAXN];
multiset<int>::iterator it;
int n,m,sum,ans,res;
int cntEdge,head[MAXN],nxt[MAXM<<1],ver[MAXM<<1],dis[MAXM<<1];
inline void add(int from,int to,int dist)
{
	cntEdge++;
	nxt[cntEdge]=head[from];
	head[from]=cntEdge;
	ver[cntEdge]=to;
	dis[cntEdge]=dist;
}
int read()
{
	int x=0; char a=getchar();
	while (a<'0'||a>'9') a=getchar();
	while ('0'<=a&&a<='9') x=x*10+a-'0',a=getchar();
	return x;
}
/*int dfs(int x,int fa,int k)
{
	s[x].clear();
	int val;
	for (int i=head[x],y;i;i=nxt[i])
	{
		y=ver[i];
		if (y==fa) continue;
		val=dfs(y,x,k)+dis[i];
		if (val>=k) res++;
		else s[x].insert(val);
	}
	int Max=0;
	while (!s[x].empty())
	{
		if (s[x].size()==1)
			return max(Max,*s[x].begin());
		it=s[x].lower_bound(k-*s[x].begin());
		if (it==s[x].begin()&&s[x].count(*it)==1) it++;
		if (it==s[x].end())
		{
			Max=max(Max,*s[x].begin());
			s[x].erase(s[x].begin());
		}
		else
		{
			res++;
			s[x].erase(s[x].begin());
			s[x].erase(it);
		}
	}
	return Max;
}*/
int dfs(int x,int fa,int k){
    s[x].clear();
    int val;
    for(int i=head[x],y;i;i=nxt[i]){
        y=ver[i];
        if(y==fa) continue;
        val=dfs(y,x,k)+dis[i];
        if(val>=k) res++;
        else {
            s[x].insert(val);
        }
    }
    int Max=0;
    while(!s[x].empty()){
        if(s[x].size()==1){
            return max(Max,*s[x].begin());
        }
        it=s[x].lower_bound(k-*s[x].begin());
        if(it==s[x].begin()&&s[x].count(*it)==1) it++;
        if(it==s[x].end()){
            Max=max(Max,*s[x].begin());
            s[x].erase(s[x].find(*s[x].begin()));
        }
        else {
            res++;
            s[x].erase(s[x].find(*it));
            s[x].erase(s[x].find(*s[x].begin()));
        }
    }
    return Max;
}
bool check(int x)
{
	res=0;
	dfs(1,0,x);
	return res>=m;
}
int main()
{
	//freopen("in.txt","r",stdin);
	n=read(); m=read();
	for (int i=1,x,y,dist;i<n;i++)
	{
		x=read(); y=read(); dist=read();
		add(x,y,dist); add(y,x,dist);
		sum+=dist;
	}
	int l=0,r=sum/m;
	while (l<=r)
	{
		int mid=(l+r)>>1;
		if (check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d",ans);
}
