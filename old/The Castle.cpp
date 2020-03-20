#include <cstdio>
#include <queue>
using namespace std;
const int MAXN=51;
const int mov_x[5]={0,0,0,-1,1};
const int mov_y[5]={0,-1,1,0,0};
//north,south,west,east
int m,n;
int map[MAXN][MAXN];
int max_area,num_room;
bool go[MAXN][MAXN],wall[MAXN][MAXN][5];
struct poi{
	int x,y;
};
void getReady()
{
	for (int y=1;y<=m;y++)
		for (int x=1;x<=n;x++)
		{
			int now=map[x][y];
			bool state[5];
			for (int i=1;i<=4;i++)
				state[i]=false;
			if (now>=8)
			{
				now-=8;
				state[2]=true;//south wall;
			}
			if (now>=4)
			{
				now-=4;
				state[4]=true;//east wall;
			}
			if (now>=2)
			{
				now-=2;
				state[1]=true;//north wall;
			}
			if (now>=1)
			{
				now-=1;
				state[3]=true;//west wall;
			}
			for (int i=1;i<=4;i++)
				wall[x][y][i]=state[i];
		}
}
void bfs(int x,int y)
{
	int now_area=0;
	queue <poi> q;
	poi start;
	start.x=x;
	start.y=y;
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
			if (1<=now_x&&now_x<=n&&1<=now_y&&now_y<=m&&go[now_x][now_y]==true&&wall[head.x][head.y][i]==false)
			{
				poi temp;
				temp.x=now_x;
				temp.y=now_y;
				q.push(temp);
				go[now_x][now_y]=false;
				now_area++;
			}
		}
	}
	num_room++;
	if (now_area>max_area)
		max_area=now_area;
}
int main()
{
	scanf("%d%d",&m,&n);
	for (int y=1;y<=m;y++)
		for (int x=1;x<=n;x++)
			scanf("%d",&map[x][y]);
	for (int i=1;i<MAXN;i++)
		for (int j=1;j<MAXN;j++)
			go[i][j]=true;
	getReady();
	for (int y=1;y<=m;y++)
		for (int x=1;x<=n;x++)
			if (go[x][y]==true)
				bfs(x,y);
	printf("%d\n%d",num_room,max_area);
}
//http://47.104.154.247/problem.php?cid=1080&pid=1
