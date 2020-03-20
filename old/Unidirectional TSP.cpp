#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXM 11
#define MAXN 101
using namespace std;
int m,n,ans,first,map[MAXM][MAXN],f[MAXM][MAXN],p[MAXM][MAXN];
inline void dp()
{
	memset(f,0x3f,sizeof(f));
	for (int j=n;j>=1;j--)
		for (int i=1;i<=m;i++)
		{
			if (j==n)
				f[i][n]=map[i][n];
			else
			{
				int row[3]={i-1,i,i+1};
				if (row[0]==0) row[0]=m;
				if (row[2]==m+1) row[2]=1;
				sort(row,row+3);
				for (int k=0;k<3;k++)
				{
					if (f[i][j]>f[row[k]][j+1]+map[i][j])
					{
						f[i][j]=f[row[k]][j+1]+map[i][j];
						p[i][j]=row[k];
					}
				}
			}
			if (j==1)
			{
				if (ans>f[i][j])
				{
					ans=f[i][j]; first=i;
				}
			}
		}
	
}
inline void setup()
{
	memset(map,0,sizeof(map));
	memset(f,0,sizeof(f));
	memset(p,0,sizeof(p));
	ans=0x3f3f3f3,first=0;
}
inline void print()
{
	printf("%d",first);
	for (int i=p[first][1],j=2;j<=n;i=p[i][j],j++)
		printf(" %d",i);
	printf("\n%d\n",ans);
}
int main()
{
	//freopen("out.txt","w",stdout);
	while (scanf("%d%d",&m,&n)!=EOF)
	{
		setup();
		for (int i=1;i<=m;i++)
			for (int j=1;j<=n;j++)
				scanf("%d",&map[i][j]);
		dp();
		print();
	}
}
//LGOJ https://www.luogu.org/problemnew/show/UVA116
