#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int f[9][9]=
{{6,6,6,6,6,6,6,6,6},
 {6,7,7,7,7,7,7,7,6},
 {6,7,8,8,8,8,8,7,6},
 {6,7,8,9,9,9,8,7,6},
 {6,7,8,9,10,9,8,7,6},
 {6,7,8,9,9,9,8,7,6},
 {6,7,8,8,8,8,8,7,6},
 {6,7,7,7,7,7,7,7,6},
 {6,6,6,6,6,6,6,6,6}
};
const int r[9][9]=
{
 {0,0,0,1,1,1,2,2,2},
 {0,0,0,1,1,1,2,2,2},
 {0,0,0,1,1,1,2,2,2},
 {3,3,3,4,4,4,5,5,5},
 {3,3,3,4,4,4,5,5,5},
 {3,3,3,4,4,4,5,5,5},
 {6,6,6,7,7,7,8,8,8},
 {6,6,6,7,7,7,8,8,8},
 {6,6,6,7,7,7,8,8,8}
};
const int MAXN=9;
int clin[9],clis[9],croom[9];
struct POI{
	int x,y,sp;//x=lin,y=lis,sp=space=room;
	friend bool operator < (POI a,POI b)
	{
		if (clin[a.x]==clin[b.x])
		{
			if (clis[a.y]==clis[b.y])
			{
				return croom[a.sp]<croom[b.sp];
			}
			else return clis[a.y]<clis[b.y];
		}
		else return clin[a.x]<clin[b.x];
	}
}poi[MAXN*MAXN+10];
int map[MAXN][MAXN],cnt,ans;
bool lin[9][10],lis[9][10],room[9][10];
inline void setup()
{
	cnt=0; ans=-1;
	memset(lin,0,sizeof(lin));
	memset(lis,0,sizeof(lis));
	memset(room,0,sizeof(room));
	memset(poi,0,sizeof(poi));
	memset(clin,0,sizeof(clin));
	memset(clis,0,sizeof(clis));
	memset(croom,0,sizeof(croom));
}
void dfs(int pos,int sum)
{
	if (pos==cnt+1)
	{
		ans=max(ans,sum);
		return;
	}
	for (int i=1;i<=9;i++)
	{
		if (!lin[poi[pos].x][i]&&!lis[poi[pos].y][i]&&!room[poi[pos].sp][i])
		{
			lin[poi[pos].x][i]=true;
			lis[poi[pos].y][i]=true;
			room[poi[pos].sp][i]=true;
			dfs(pos+1,sum+i*f[poi[pos].x][poi[pos].y]);
			lin[poi[pos].x][i]=false;
			lis[poi[pos].y][i]=false;
			room[poi[pos].sp][i]=false;
		}
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	while (true)
	{
		setup();
		int tmp=0;
		for (int i=0;i<9;i++)
			for (int j=0;j<9;j++)
			{
				if (scanf("%d",&map[i][j])==EOF) return 0;
				lin[i][map[i][j]]=true;
				lis[j][map[i][j]]=true;
				room[r[i][j]][map[i][j]]=true;
				tmp+=map[i][j]*f[i][j];
				if (map[i][j]==0)
				{
					poi[++cnt].x=i,poi[cnt].y=j,poi[cnt].sp=r[i][j];
					clin[i]++,clis[j]++,croom[r[i][j]]++;
				}
			}
		sort(poi+1,poi+1+cnt);
		dfs(1,tmp);
		printf("%d\n",ans);
	}
}
