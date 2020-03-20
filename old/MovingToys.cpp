#include <cstdio>
#include <queue>
#include <map>
using namespace std;
typedef unsigned short ushort;
const ushort f[4][4]={{15,14,13,12},{11,10,9,8},{7,6,5,4},{3,2,1,0}};
const int mov_x[4]={-1,0,1,0};
const int mov_y[4]={0,1,0,-1};
queue <ushort> q1,q2;
map <ushort,int> m1,m2;
ushort s,e;
int ans;
inline void bfs()
{
	q1.push(s); q2.push(e);
	m1[s]=0,m2[e]=0;
	while (!q1.empty()&&!q2.empty())
	{
		ushort now=q1.front(); q1.pop();
		if (m2.find(now)!=m2.end())
		{
			ans=m1[now]+m2[now];
			return;
		}
		for (int i=0;i<4;i++)
			for (int j=0;j<4;j++)
			{
				if (~now&(1<<f[i][j]))//i,j==0
				{
					for (int k=0;k<4;k++)
					{
						int now_x=i+mov_x[k];
						int now_y=j+mov_y[k];
						if (0<=now_x&&now_x<4&&0<=now_y&&now_y<4&&(now&(1<<f[now_x][now_y])))//now_x,now_y==1
						{
							ushort tmp=(now|(1<<f[i][j]));
							tmp=tmp&(~(1<<f[now_x][now_y]));
							if (m1.find(tmp)!=m1.end()) continue;
							m1[tmp]=m1[now]+1;
							q1.push(tmp);
						}
					}
				}
			}
		now=q2.front(); q2.pop();
		if (m1.find(now)!=m1.end())
		{
			ans=m1[now]+m2[now];
			return;
		}
		for (int i=0;i<4;i++)
			for (int j=0;j<4;j++)
			{
				if (~now&(1<<f[i][j]))//i,j==0
				{
					for (int k=0;k<4;k++)
					{
						int now_x=i+mov_x[k];
						int now_y=j+mov_y[k];
						if (0<=now_x&&now_x<4&&0<=now_y&&now_y<4&&(now&(1<<f[now_x][now_y])))//now_x,now_y==1
						{
							ushort tmp=(now|(1<<f[i][j]));
							tmp=tmp&(~(1<<f[now_x][now_y]));
							if (m2.find(tmp)!=m2.end()) continue;
							m2[tmp]=m2[now]+1;
							q2.push(tmp);
						}
					}
				}
			}
	}
}
int main()
{
	for (int i=1;i<=4;i++)
		for (int j=1;j<=4;j++)
		{
			char a; s<<=1;
			scanf(" %c",&a);
			if (a=='1') s|=1;
		}
	for (int i=1;i<=4;i++)
		for (int j=1;j<=4;j++)
		{
			char a; e<<=1;
			scanf(" %c",&a);
			if (a=='1') e|=1;
		}
	bfs();
	printf("%d",ans);
}
