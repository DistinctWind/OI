#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAXN 51
using namespace std;
struct POI{
	int x,y,num;
	friend bool operator < (POI a,POI b)
	{
		return a.x<b.x;
	}
}poi[MAXN];
int n,m;
int dis_x[MAXN][MAXN];
int dis_y[MAXN][MAXN];
int max(int a,int b)
{
	return a>b?a:b;
}
bool check(int mid)
{
	bool ok=true;
	bool vis[MAXN];
	memset(vis,0,sizeof(vis));
	queue <POI> q;
	POI start=poi[1];
	q.push(start),vis[1]=true;
	while (!q.empty())
	{
		POI front=q.front();
		q.pop();
		for (int i=1;i<=n;i++)
		{
			//if (i==front.num) continue;
			int dis=dis_x[i][front.num]+dis_y[i][front.num];
			if (!vis[i]&&(dis<=mid*2))
			{
				vis[i]=true;
				q.push(poi[i]);
			}
		}
	}
	for (int i=1;i<=n&&ok;i++)
		if (!vis[i])
			ok=false;
	return ok;
}
inline void setup()
{
	sort(poi+1,poi+1+n);
	for (int i=1;i<=n;i++)
	{
		poi[i].num=i;
		for (int j=i+1;j<=n;j++)
		{
			dis_x[i][j]=dis_x[j][i]=abs(poi[i].x-poi[j].x);
			dis_y[i][j]=dis_y[j][i]=abs(poi[i].y-poi[j].y);
		}
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&poi[i].x,&poi[i].y);
	int l=0,r=1e9,mid;
	setup();
	while (r-l>1)
	{
		mid=(l+r)/2;
		if (check(mid)) r=mid;
		else l=mid;
	}
	printf("%d",r);
}
//LGOJ https://www.luogu.org/problemnew/show/P1661
//LOJ https://loj.ac/problem/10015
