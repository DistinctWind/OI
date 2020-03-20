#include <cstdio>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#define MAXN 101
using namespace std;
int n,cnt_rent,cnt_edge,ans,head[MAXN],degree[MAXN];
int memory[MAXN];
struct Rent{
	int x,y;
}rent[MAXN];
struct EDGE{
	int next,to;
}edge[MAXN*100+1];
inline void add(int from,int to)
{
	cnt_edge++;
	edge[cnt_edge].next=head[from];
	head[from]=cnt_edge;
	edge[cnt_edge].to=to;
}
bool judge(int i,int j)
{
	if (rent[i].x==rent[j].x&&rent[i].y==rent[j].y)
		return false;
	if (rent[i].x>rent[j].x&&rent[i].y>=rent[j].y)
		return true;
	if (rent[i].x==rent[j].x&&rent[i].y>rent[j].y)
		return true;
	return false;
}
int solve(int x)
{
	int temp=0;
	if (memory[x]>0)
		return memory[x];
	for (int i=head[x];i!=0;i=edge[i].next)
	{
		int son=edge[i].to;
		temp=max(temp,solve(son));
	}
	return memory[x]=temp+1;
}
void path(int x)
{
	printf("%d-",x);
	for (int i=head[x];i!=0;i=edge[i].next)
		path(edge[i].to);
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if (b>a)
			swap(a,b);
		cnt_rent++;
		rent[cnt_rent].x=a;
		rent[cnt_rent].y=b;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
		{
			if (judge(i,j))
			{
				add(i,j);
				degree[j]++;
			}
		}
	//path(1);
	for (int i=1;i<=n;i++)
		if (degree[i]==0)
			ans=max(ans,solve(i));
	printf("%d",ans);
}
//DHOJ http://47.104.154.247/problem.php?cid=1093&pid=0
