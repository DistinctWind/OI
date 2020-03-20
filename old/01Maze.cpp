#include <cstdio>
#include <queue>
#include <cstring>
#include <time.h>
#define MAXN 1001
using namespace std;
const int mov_i[5]={0,-1,0,1,0};
const int mov_j[5]={0,0,1,0,-1};
int n,m,res[1000001],flag[MAXN][MAXN];
bool map[MAXN][MAXN],vis[MAXN][MAXN];
struct state{
	int i,j;
};
int max(int a,int b)
{
	return a>b?a:b;
}
/*inline void bfs(int a,int b)
{
	if (res[a][b]>0)
	{
		printf("%d\n",res[a][b]);
		return;
	}
	queue <state> q;
	state start;
	start.i=a,start.j=b;
	vis[a][b]=true;
	int ans=1;
	q.push(start);
	while (!q.empty())
	{
		state front=q.front();
		q.pop();
		for (int i=1;i<=4;i++)
		{
			int now_i=front.i+mov_i[i];
			int now_j=front.j+mov_j[i];
			if (1<=now_i&&now_i<=n&&1<=now_j&&now_j<=n&&!vis[now_i][now_j]&&(map[now_i][now_j]==!map[front.i][front.j]))
			{
				state temp;
				temp.i=now_i,temp.j=now_j;
				ans++;
				q.push(temp);
				vis[now_i][now_j]=true;
			}
		}
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (vis[i][j])
				res[i][j]=ans;
	printf("%d\n",ans);
}*/
int main()
{
	//clock_t start,end;
	//start=clock();
	//freopen("testdata.in","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		{
			char temp;
			scanf(" %c",&temp);
			if (temp=='1')
				map[i][j]=true;
		}
	int d=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (!vis[i][j])
			{
				d++;
				state start;
				start.i=i,start.j=j;
				vis[i][j]=true;
				flag[i][j]=d;
				queue <state> q;
				q.push(start);
				int ans=1;
				while (!q.empty())
				{
					state front=q.front();
					q.pop();
					for (int i=1;i<=4;i++)
					{
						int now_i=front.i+mov_i[i];
						int now_j=front.j+mov_j[i];
						if (1<=now_i&&now_i<=n&&1<=now_j&&now_j<=n&&!vis[now_i][now_j]&&(map[now_i][now_j]==!map[front.i][front.j]))
						{
							state temp;
							temp.i=now_i,temp.j=now_j;
							ans++;
							q.push(temp);
							vis[now_i][now_j]=true;
							flag[now_i][now_j]=d;
						}
					}
				}
				res[d]=ans;
			}
	for (int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",res[flag[a][b]]);
	}
	//end=clock();
	//printf("%lf",(double)(end-start)/CLOCKS_PER_SEC);
}
