#include <cstdio>
#include <iostream>
#include <queue>
#include <set>
using namespace std;
const int ans[3][3]={{1,2,3},{8,0,4},{7,6,5}};
const int mov_x[4]={-1,0,1,0};
const int mov_y[4]={0,1,0,-1};
struct state{
	int num,zx,zy,step,close,a_star;
	friend bool operator < (state a,state b)
	{
		return a.a_star>b.a_star;
	}
}start;
int tmp[3][3],x;
set <int> s;
void divide(int num)
{
	for (int i=2;i>=0;i--)
		for (int j=2;j>=0;j--)
		{
			tmp[i][j]=num%10;
			num/=10;
		}
}
int restart()
{
	int ans=0;
	for (int i=0;i<3;i++)
		for (int j=0;j<3;j++)
			ans=ans*10+tmp[i][j];
	return ans;
}
int judge()
{
	int res=0;
	for (int i=0;i<3;i++)
		for (int j=0;j<3;j++)
			if (tmp[i][j]!=ans[i][j])
				res++;
	return res;
}
inline void bfs()
{
	priority_queue <state> q;
	divide(start.num);
	for (int i=0;i<=2;i++)
		for (int j=0;j<=2;j++)
			if (tmp[i][j]==0)
			{
				start.zx=i,start.zy=j;
				break;
			}
	start.step=0;
	start.close=judge();
	start.a_star=start.step+start.close;
	q.push(start); s.insert(start.num);
	while (!q.empty())
	{
		state h=q.top(); q.pop();
		divide(h.num);
		if (h.close==0)
		{
			x=h.step;
			return;
		}
		for (int i=0;i<4;i++)
		{
			int now_x=h.zx+mov_x[i];
			int now_y=h.zy+mov_y[i];
			if (!(0<=now_x&&now_x<=2&&0<=now_y&&now_y<=2))
				continue;
			swap(tmp[now_x][now_y],tmp[h.zx][h.zy]);
			int now=restart();
			if (s.count(now)==0)
			{
				s.insert(now);
				state t;
				t.num=now;
				t.zx=now_x,t.zy=now_y;
				t.step=h.step+1;
				t.close=judge();
				t.a_star=t.step+t.close;
				q.push(t);
			}
			swap(tmp[now_x][now_y],tmp[h.zx][h.zy]);
		}
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&start.num);
	bfs();
	printf("%d",x);
}
