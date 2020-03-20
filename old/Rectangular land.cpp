#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;
const int MAXN=31;
const int mov_x[5]={0,0,1,0,-1};
const int mov_y[5]={0,-1,0,1,0};
int n,m,t;
int map[MAXN][MAXN];
bool go[MAXN][MAXN];
double ans[MAXN][MAXN];
struct poi{
	int x,y,broken;
	double len;
};
void setup()
{
	for (int i=1;i<MAXN;i++)
		for (int j=1;j<MAXN;j++)
			go[i][j]=true;
}
double bfs(int x,int y)
{
	poi start;
	start.x=x;
	start.y=y;
	if (map[x][y]==0)
		start.broken=0;
	else
		start.broken=1;
	start.len=1;
	double max=1;
	if (start.broken>t)
		return -1;
	queue <poi> q;
	q.push(start);
	while (!q.empty())
	{
		poi head;
		head=q.front();
		q.pop();
		for (int i=1;i<=4;i++)
		{
			int now_x=head.x+mov_x[i];
			int now_y=head.y+mov_y[i];
			if (1<=now_x&&now_x<=m&&1<=now_y&&now_y<=n&&go[now_x][now_y]==true)
				if (map[now_x][now_y]==0)
				{
					poi temp;
					temp.x=now_x;
					temp.y=now_y;
					temp.broken=head.broken;
					temp.len=sqrt((now_x-x)*(now_x-x)+(now_y-y)*(now_y-y));
					go[now_x][now_y]=false;
					if (temp.len>max)
					max=temp.len;
					q.push(temp);
				}
				else
					if (head.broken+1<=t)
					{
						poi temp;
						temp.x=now_x;
						temp.y=now_y;
						temp.broken=head.broken+1;
						temp.len=sqrt((now_x-x)*(now_x-x)+(now_y-y)*(now_y-y));
						go[now_x][now_y]=false;
						if (temp.len>max)
							max=temp.len;
						q.push(temp);
					}
		}
	}
	return max;
}
int main()
{
	scanf("%d%d%d",&n,&m,&t);
	for (int y=1;y<=n;y++)
		for (int x=1;x<=m;x++)
		{
			char temp;
			scanf(" %c",&temp);
			map[x][y]=temp-'0';
		}
	setup();
	for (int y=1;y<=n;y++)
		for (int x=1;x<=m;x++)
			ans[x][y]=bfs(x,y);
	double max=-1;
	for (int y=1;y<=n;y++)
		for (int x=1;x<=m;x++)
			if (ans[x][y]>max)
				max=ans[x][y];
	printf("%llf",max);			
}
