#include <cstdio>
#include <limits.h>
#define MAX_REC 160
#define MAX_POI	1000
using namespace std;
int n,cnt_rec,map[MAX_POI][MAX_POI],ans=INT_MAX;
struct REC{
	int x1,y1,x2,y2,col;
	bool vis;
}rec[MAX_REC];
void add(int n)
{
	for (int y=rec[n].y1+1;y<=rec[n].y2;y++)
		for (int x=rec[n].x1+1;x<=rec[n].x2;x++)
			map[x][y]=0;
}
void del(int n)
{
	for (int y=rec[n].y1+1;y<=rec[n].y2;y++)
		for (int x=rec[n].x1+1;x<=rec[n].x2;x++)
			map[x][y]=rec[n].col;
}
bool judge(int n)
{
	for (int i=rec[n].x1+1;i<=rec[n].x2;i++)
		if (map[i][rec[n].y1]!=0)
			return false;
	return true;
}
void dfs(int now,int sum,int cnt)//cnt==Ready rec,sum=times;
{
	//printf("Now in Rec.%d, sum=%d cnt=%d\n",now,sum,cnt);
	if (sum>ans) return;
	if (cnt==n)
	{
		ans=sum; return;
	}
	for (int i=1;i<=n;i++)
	{
		if (rec[i].vis==false&&judge(i)==true)
		{
			if (rec[i].col==rec[now].col)
			{
				rec[i].vis=true;
				add(i);
				dfs(i,sum,cnt+1);
				del(i);
				rec[i].vis=false;
			}
			if (rec[i].col!=rec[now].col)
			{
				rec[i].vis=true;
				add(i);
				dfs(i,sum+1,cnt+1);
				del(i);
				rec[i].vis=false;
			}
		}
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int x1,y1,x2,y2,col;
		scanf("%d%d%d%d%d",&y1,&x1,&y2,&x2,&col);
		cnt_rec++;
		rec[cnt_rec].x1=x1; rec[cnt_rec].y1=y1; rec[cnt_rec].x2=x2; rec[cnt_rec].y2=y2; rec[cnt_rec].col=col;
		for (int y=y1+1;y<=y2;y++)
			for (int x=x1+1;x<=x2;x++)
				map[x][y]=rec[cnt_rec].col;
	}
	for (int i=1;i<=n;i++)
		if (rec[i].y1==0&&rec[i].vis==false)
		{
			//printf("Begin in Rec.%d\n",i);
			rec[i].vis=true;
			add(i);
			dfs(i,1,1);
			del(i);
			rec[i].vis=false;
		}
	printf("%d",ans);
}
