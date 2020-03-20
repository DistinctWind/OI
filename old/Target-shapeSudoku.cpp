#include <cstdio>
#include <iostream>
#define MAXN 10
using namespace std;
const int parameter[9][9]={
	{6,6,6,6,6,6,6,6,6},
	{6,7,7,7,7,7,7,7,6},
	{6,7,8,8,8,8,8,7,6},
	{6,7,8,9,9,9,8,7,6},
	{6,7,8,9,10,9,8,7,6},
	{6,7,8,9,9,9,8,7,6},
	{6,7,8,8,8,8,8,7,6},
	{6,7,7,7,7,7,7,7,6},
	{6,6,6,6,6,6,6,6,6},
};
int map[MAXN][MAXN],ans=-1;
bool vis1[MAXN][MAXN],vis2[MAXN][MAXN],vis3[MAXN][MAXN];
//vis1=line;vis2=list;vis3=room;
int judge_room(int x,int y)
{
	int temp_x=(x-1)/3,temp_y=(y-1)/3;
	switch(temp_x)
	{
		case 0:
			if (temp_y==0) return 1;
			if (temp_y==1) return 4;
			if (temp_y==2) return 7;
		case 1:
			if (temp_y==0) return 2;
			if (temp_y==1) return 5;
			if (temp_y==2) return 8;
		case 2:
			if (temp_y==0) return 3;
			if (temp_y==1) return 6;
			if (temp_y==2) return 9;
	}
}
void print_map(int x,int y,int k)
{
	printf("Focus on (%d,%d),val=%d\n",x,y,k);
	for (int i=1;i<=9;i++)
	{
		for (int j=1;j<=9;j++)
			printf("%d ",map[i][j]);
		putchar('\n');
	}
}
void dfs()
{
	int x,y,step=10;
	for (int i=1;i<=9;i++)
		for (int j=1;j<=9;j++)
			if (map[i][j]==0)
			{
				int now=0;
				for (int k=1;k<=9;k++)
					if (!vis1[i][k]&&!vis2[j][k]&&!vis3[judge_room(i,j)][k])
						now++;
				if (now<step)
					step=now,x=i,y=j;
			}
	if (step==10)
	{
		int temp=0;
		for (int i=1;i<=9;i++)
			for (int j=1;j<=9;j++)
				temp+=map[i][j]*parameter[i-1][j-1];
		//printf("Found ans=%d",temp);
		ans=max(temp,ans);
	}
	for (int k=1;k<=9;k++)
		if (!vis1[x][k]&&!vis2[y][k]&&!vis3[judge_room(x,y)][k])
		{
			vis1[x][k]=vis2[y][k]=vis3[judge_room(x,y)][k]=true;
			map[x][y]=k;
			//print_map(x,y,k);
			dfs();
			vis1[x][k]=vis2[y][k]=vis3[judge_room(x,y)][k]=false;
			//printf("Fail trying...Remove(%d,%d)\n",x,y);
			map[x][y]=0;
		}
}
int main()
{
	//freopen("out.txt","w",stdout);
	for (int i=1;i<=9;i++)
		for (int j=1;j<=9;j++)
		{
			scanf("%d",&map[i][j]);
			vis1[i][map[i][j]]=vis2[j][map[i][j]]=vis3[judge_room(i,j)][map[i][j]]=true;
		}
	dfs();
	printf("%d",ans);
}
