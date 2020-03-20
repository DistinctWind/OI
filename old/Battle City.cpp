#include <cstdio>
#include <queue>
#include <limits.h>
using namespace std;
const int MAXN=301;
const int mov_x[5]={0,0,1,0,-1};
const int mov_y[5]={0,-1,0,1,0};
char map[MAXN][MAXN];
int mx,my,ex,ey,sx,sy,ans;
int used_step[MAXN][MAXN];
bool go[MAXN][MAXN];
struct poi{
	int x,y,step;
	bool operator < (const poi &a) const{
		return a.step<step;
	}
};
void setup()
{
	ans=INT_MAX;
	for (int i=1;i<MAXN;i++)
		for (int j=1;j<MAXN;j++)
			go[i][j]=false,map[i][j]='\000';
}
void bfs()
{
	priority_queue <poi> q;
	poi start;
	start.x=sx;start.y=sy;start.step=0;
	q.push(start);
	while (!q.empty())
	{
		poi head;
		head=q.top();
		q.pop();
		if (head.x==ex&&head.y==ey)
		{
			ans=head.step;
			return;
		}
		for (int i=1;i<=4;i++)
		{
			poi temp;
			int now_x=mov_x[i]+head.x;
			int now_y=mov_y[i]+head.y;
			if ((now_x==sx&&now_y==sy)||(go[now_x][now_y]==true))
				continue;
			switch(map[now_x][now_y])
			{
				case 'E':
					temp.x=now_x;temp.y=now_y;temp.step=head.step+1;
					go[now_x][now_y]=true;
					q.push(temp);
					break;
				case 'B':
					temp.x=now_x;temp.y=now_y;temp.step=head.step+2;
					go[now_x][now_y]=true;
					q.push(temp);
					break;
				case 'T':
					temp.x=now_x;temp.y=now_y;temp.step=head.step+1;
					q.push(temp);
					break;
				default:
					continue;
			}
		}
	}
}
int main()
{
	//freopen("tank.in","r",stdin);
	//freopen("out.txt","w",stdout); 
	while (true)
	{
		scanf("%d%d",&my,&mx);
		setup();
		if (mx==0&&my==0)
			break;
		for (int y=1;y<=my;y++)
			for (int x=1;x<=mx;x++)
			{
				char temp;
				scanf(" %c",&temp);
				switch(temp)
				{
					case 'Y':sx=x;sy=y;break;
					case 'T':ex=x;ey=y;break;
				}
				map[x][y]=temp;
			}
		bfs();
		if (ans==INT_MAX)
			printf("-1\n");
		else
			printf("%d\n",ans);
	}
}
