#include <cstdio>
#define MAXR 101
#define MAXC 101
using namespace std;
const int mov_i[5]={0,-1,0,1,0};
const int mov_j[5]={0,0,1,0,-1};
int r,c,ans,map[MAXR][MAXC],f[MAXR][MAXC];
int max(int a,int b)
{
	return a>b?a:b;
}
int dfs(int ni,int nj)
{
	if (f[ni][nj]>0)
		return f[ni][nj];
	int temp=0;
	for (int i=1;i<=4;i++)
	{
		int now_i=ni+mov_i[i];
		int now_j=nj+mov_j[i];
		if (1<=now_i&&now_i<=r&&1<=now_j&&now_j<=c&&map[ni][nj]<map[now_i][now_j])
			temp=max(dfs(now_i,now_j)+1,temp);
	}
	return f[ni][nj]=temp;
}
int main()
{
	scanf("%d%d",&r,&c);
	for (int i=1;i<=r;i++)
		for (int j=1;j<=c;j++)
			scanf("%d",&map[i][j]);
	for (int i=1;i<=r;i++)
		for (int j=1;j<=c;j++)
		{
			ans=max(dfs(i,j)+1,ans);
		}
	printf("%d",ans);
}
