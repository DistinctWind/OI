#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN=30;
bool d[MAXN][MAXN],e[MAXN][MAXN];
int n,m;
struct Line{
	int pos,cnt;
	bool operator < (const Line &a) const{
		return cnt>a.cnt;
	}
}lin[MAXN];
int floyd()
{
	memcpy(e,d,sizeof(d));
	for (int k=0;k<n;k++)
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
			{
				e[i][j]|=e[i][k]&e[k][j];
				if (e[i][j]==e[j][i]&&e[i][j]&&i!=j) return -1;
				//if (e[i][j]==e[j][i]&&!e[i][j]&&i!=j) return 0;
			}
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
		{
			if (e[i][j]==e[j][i]&&!e[i][j]&&i!=j) return 0;
			//if (e[i][j]==e[j][i]&&e[i][j]&&i!=j) return -1;
		}
	return 1;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while (scanf("%d%d",&n,&m),n!=0&&m!=0)
	{
		bool flag=true;
		memset(d,0,sizeof(d));
		memset(lin,0,sizeof(lin));
		for (int i=1;i<=m;i++)
		{
			char a[7];
			scanf(" %s",a);
			int x=a[0]-'A',y=a[2]-'A';
			d[x][y]=1;
			if (flag)
			{
				int now=floyd();
				if (now==-1)
				{
					printf("Inconsistency found after %d relations.\n",i);
					flag=false;
				}
				if (now==1)
				{
					printf("Sorted sequence determined after %d relations: ",i);
					for (int x=0;x<n;x++)
					{
						lin[x].pos=x,lin[x].cnt=0;
						for (int y=0;y<n;y++)
							if (e[x][y]==1)
								lin[x].cnt++;
					}
					sort(lin,lin+n);
					for (int x=0;x<n;x++)
						putchar(lin[x].pos+'A');
					putchar('.'); putchar('\n');
					flag=false;
				}
			}
		}
		if (flag) printf("Sorted sequence cannot be determined.\n");
	}
}
