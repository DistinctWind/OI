#include <cstdio>
#include <queue>
#include <cstring>
#define MAXN 31
using namespace std;
int n,cnt_cube,cnt_edge,degree[MAXN*3],dist[MAXN*3],head[MAXN*3];
bool vis[MAXN*3];
struct Cube{
	int x,y,z,num;
	void clear(){
		x=y=z=num=0;
	}
}cube[MAXN*3];
struct Edge{
	int next,to,dis;
	void clear(){
		next=to=dis=0;
	}
}edge[MAXN*MAXN*MAXN];
struct state{
	int x,h;
};
void add(int from,int to,int dis)
{
	cnt_edge++;
	edge[cnt_edge].next=head[from];
	head[from]=cnt_edge;
	edge[cnt_edge].to=to;
	edge[cnt_edge].dis=dis;
}
void judge(Cube a,Cube b)
{
	if (a.x<b.x&&a.y<b.y)
	{
		add(a.num,b.num,b.z);
		degree[b.num]++;
	}
	else if (a.y<b.x&&a.x<b.y)
	{
		add(a.num,b.num,b.z);
		degree[b.num]++;
	}
}
void fspfa()
{
	queue <state> q;
	state start;
	start.x=0; start.h=0;
	q.push(start);
	while (!q.empty())
	{
		state front=q.front();
		q.pop();
		vis[front.x]=false;
		for (int i=head[front.x];i!=0;i=edge[i].next)
		{
			int son=edge[i].to;
			if (dist[son]<dist[front.x]+edge[i].dis)
			{
				dist[son]=dist[front.x]+edge[i].dis;
				if (vis[son]==false)
				{
					state temp;
					temp.x=son; temp.h=front.h+edge[i].dis;
					q.push(temp);
					vis[temp.x]=true;
				}
			}
		}
	}
}
int max(int a,int b)
{
	return a>b?a:b;
}
void setup()
{
	for (int i=1;i<=cnt_cube;i++)
		cube[i].clear();
	for (int i=1;i<=cnt_edge;i++)
		edge[i].clear();
	cnt_cube=cnt_edge=0;
	memset(degree,0,sizeof(degree));
	memset(dist,0,sizeof(dist));
	memset(head,0,sizeof(head));
}
int main()
{
	scanf("%d",&n);
	int times=1;
	while (n!=0)
	{
		setup();
		for (int i=1;i<=n;i++)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			cnt_cube++;
			cube[cnt_cube].x=a,cube[cnt_cube].y=b,cube[cnt_cube].z=c,cube[cnt_cube].num=cnt_cube;
			cnt_cube++;
			cube[cnt_cube].x=b,cube[cnt_cube].y=c,cube[cnt_cube].z=a,cube[cnt_cube].num=cnt_cube;
			cnt_cube++;
			cube[cnt_cube].x=c,cube[cnt_cube].y=a,cube[cnt_cube].z=b,cube[cnt_cube].num=cnt_cube;
		}
		for (int i=1;i<=cnt_cube;i++)
			for (int j=1;j<=cnt_cube;j++)
				judge(cube[i],cube[j]);
		for (int i=1;i<=cnt_cube;i++)
			if (degree[i]==0)
				judge(cube[0],cube[i]);
		fspfa();
		int temp=-1;
		for (int i=1;i<=cnt_cube;i++)
			temp=max(temp,dist[i]);
		printf("Case %d: maximum height = %d\n",times,temp);
		times++;
		scanf("%d",&n);
	}
}
//LGOJ https://www.luogu.org/problemnew/show/UVA437
//VJ https://vjudge.net/contest/288229 Password:dhsty
