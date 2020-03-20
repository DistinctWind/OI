#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#define MAXN 55
using namespace std;
int n;
double dp[MAXN][MAXN],dis[MAXN][MAXN];
struct POI{
	int x,y;
}poi[MAXN];
int main()
{
	while (scanf("%d",&n)==1)
	{
		for (int i=1;i<=n;i++)
		{
			scanf("%d%d",&poi[i].x,&poi[i].y);
		}
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				dis[i][j]=sqrt((poi[i].x-poi[j].x)*(poi[i].x-poi[j].x)+(poi[i].y-poi[j].y)*(poi[i].y-poi[j].y));
		for (int i=n-1;i>=2;i--)
			for (int j=1;j<i;j++)
				if (i==n-1) dp[i][j]=dis[i][n]+dis[j][n];
				else dp[i][j]=min(dis[i][i+1]+dp[i+1][j],dis[j][i+1]+dp[i+1][i]);
		printf("%.2f\n",dp[2][1]+dis[1][2]);
	}
}
