#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
const int MAXN=16;
struct POI{
    double x,y;
}p[MAXN];
int n;
bool vis[MAXN];
double dis[MAXN][MAXN],ans=10000000;
void dfs(int now,int step,double len)
{
    if (len>=ans) return;
    if (step==n) ans=min(ans,len);
    for (int i=1;i<=n;i++)
    {
        if (!vis[i])
        {
            vis[i]=true;
            dfs(i,step+1,len+dis[i][now]);
            vis[i]=false;
        }
    }
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%lf%lf",&p[i].x,&p[i].y);
    }
    p[0].x=0,p[0].y=0;
    for (int i=0;i<=n;i++)
    {
        for (int j=0;j<=n;j++)
        {
            dis[i][j]=sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y));
        }
    }
    dfs(0,0,0);
    printf("%.2lf",ans);
}
//LGOJ https://www.luogu.org/problemnew/show/P1433
