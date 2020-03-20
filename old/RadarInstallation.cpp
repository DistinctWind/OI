#include <cstdio>
#include <iostream>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;
const int MAXN=1001;
int n,d,cnt,ans;
double pos;
bool noAns;
struct Island{
	int x,y;
	double l,r;
	inline void get(){
		scanf("%d%d",&x,&y);
	}
	inline void calc(){
		double delta=d*d-y*y;
		if (delta<0)
		{
			noAns=true;
			return;
		}
		delta=sqrt(delta);
		l=x-delta; r=x+delta;
	}
	friend bool operator < (Island a,Island b)
	{
		if (a.r==b.r) return a.l>b.l;
		else return a.r<b.r;
	}
}isl[MAXN];
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while (scanf("%d%d",&n,&d),n!=0&&d!=0)
	{
		cnt++; noAns=false; ans=0; pos=-1e10;
		for (int i=1;i<=n;i++)
		{
			isl[i].get();
			isl[i].calc();
		}
		printf("Case %d: ",cnt);
		if (noAns||d<=0)
		{
			printf("-1\n");
			continue;
		}
		sort(isl+1,isl+1+n);
		for (int i=1;i<=n;i++)
		{
			if (isl[i].l>pos)
			{
				pos=isl[i].r;
				ans++;
			}
		}
		printf("%d\n",ans);
	}
}
