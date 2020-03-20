#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MAXN=101;
int n,m,ans,a[MAXN][MAXN],d[MAXN][MAXN],pos[MAXN][MAXN];
vector <int> p;
void getpath(int x,int y)
{
	if (pos[x][y]==0) return;
	getpath(x,pos[x][y]);
	p.push_back(pos[x][y]);
	getpath(pos[x][y],y);
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	memset(a,0x3f,sizeof(a));
	for (int i=1;i<=n;i++)
		a[i][i]=0;
	for (int i=1;i<=m;i++)
	{
		int x,y,dis;
		scanf("%d%d%d",&x,&y,&dis);
		a[x][y]=a[y][x]=dis;
	}
	memcpy(d,a,sizeof(a));
	ans=0x3f3f3f3f;
	for (int k=1;k<=n;k++)
	{
		for (int i=1;i<k;i++)
			for (int j=i+1;j<k;j++)
			{
				if (ans>(long long)d[i][j]+a[i][k]+a[k][j])
				{
					ans=d[i][j]+a[i][k]+a[k][j];
					p.clear();
					p.push_back(i);
					getpath(i,j);
					p.push_back(j);
					p.push_back(k);
				}
			}
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				if (d[i][j]>d[i][k]+d[k][j])
				{
					pos[i][j]=k;
					d[i][j]=d[i][k]+d[k][j];
				}
	}
	if (ans==0x3f3f3f3f) printf("No solution.\n");
	else 
		for (int i=0;i<p.size();i++)
			printf("%d ",p[i]);
}
