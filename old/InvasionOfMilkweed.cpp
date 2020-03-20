#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;
const int MAXX=101;
const int MAXY=101;
const int mov_x[8]={0,1,1,1,0,-1,-1,-1};
const int mov_y[8]={1,1,0,-1,-1,-1,0,1};
int mx,my,sx,sy;
bool map[MAXX][MAXY];
struct state{
	int step,x,y;
};
bool end()
{
	bool ans=true;
	for (int i=1;i<=my&&ans;i++)
		for (int j=1;j<=mx&&ans;j++)
			if (!map[i][j])
				ans=false;
	return ans;
}
inline void bfs()
{
	queue <state> q;
	state start;
	start.step=0,start.x=sx,start.y=sy;
	map[sy][sx]=true;
	q.push(start);
	while (!q.empty())
	{
		state f=q.front();
		q.pop();
		for (int i=0;i<8;i++)
		{
			int now_x=f.x+mov_x[i];
			int now_y=f.y+mov_y[i];
			if (!map[now_y][now_x]&&(1<=now_x&&now_x<=mx)&&(1<=now_y&&now_y<=my))
			{
				state tmp;
				tmp.step=f.step+1,tmp.x=now_x,tmp.y=now_y;
				map[now_y][now_x]=true;
				if (end())
				{
					printf("%d",tmp.step);
					exit(0);
				}
				q.push(tmp);
			}
		}
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d%d%d",&mx,&my,&sx,&sy);
	for (int i=my;i>=1;i--)
		for (int j=1;j<=mx;j++)
		{
			char tmp;
			scanf(" %c",&tmp);
			if (tmp=='*') map[i][j]=true;
		}
	bfs();
}
