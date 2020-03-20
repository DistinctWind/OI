#include <cstdio>
#include <limits.h>
const int MAXN=21;
const int mov_x[5]={0,0,0,-1,1};
const int mov_y[5]={0,-1,1,0,0};
int mx,my;
int map[MAXN][MAXN];
int sx,sy,ex,ey;
int min_step=INT_MAX;
void dfs(int x,int y,int step)
{
	if (step>10)
		return;
	for (int i=1;i<=4;i++)
	{
		bool must_break=false;
		int now_x=x,now_y=y;
		if (map[now_x+mov_x[i]][now_y+mov_y[i]]==1)
			continue;
		while (map[now_x+mov_x[i]][now_y+mov_y[i]]!=1&&must_break==false)
		{
			if (now_x+mov_x[i]<1||now_x+mov_x[i]>mx)
				must_break=true;
			if (now_y+mov_y[i]<1||now_y+mov_y[i]>my)
				must_break=true;
			if (must_break==false)
			{
				now_x+=mov_x[i];
				now_y+=mov_y[i];
			}
			if (now_x==ex&&now_y==ey)
				if (step+1<min_step&&step+1<=10)
				{
					min_step=step+1;
					return;
				}
		}
		if (must_break==true)
			continue;
		map[now_x+mov_x[i]][now_y+mov_y[i]]=0;
		dfs(now_x,now_y,step+1);
		map[now_x+mov_x[i]][now_y+mov_y[i]]=1;
	}
}
int main()
{
	while (true)
	{
		scanf("%d%d",&mx,&my);
		if (mx==0&&my==0)
			break;
		min_step=INT_MAX;
		for (int y=1;y<MAXN;y++)
			for (int x=1;x<MAXN;x++)
				map[x][y]=0;
		for (int y=1;y<=my;y++)
			for (int x=1;x<=mx;x++)
			{
				scanf("%d",&map[x][y]);
				switch (map[x][y])
				{
					case 2 : map[x][y]=0;sx=x;sy=y;
							 break;
					case 3 : map[x][y]=0;ex=x;ey=y;
							 break;
				}
			}
		dfs(sx,sy,0);
		if (min_step!=INT_MAX)
			printf("%d\n",min_step);
		else
			printf("-1\n");
	}
} 
//http://47.104.154.247/problem.php?cid=1080&pid=3
