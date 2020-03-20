#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#define MAXN 6001
using namespace std;
int n;
int happy[MAXN],father[MAXN],f[MAXN][2];
bool map[MAXN][MAXN];
vector <int> son[MAXN];
void dp(int s)
{
	if (son[s].size()==0)
	{
		f[s][1]+=happy[s];
		return;
	}
	for (int i=0;i<son[s].size();i++)
	{
		dp(son[s][i]);
		f[s][0]+=max(f[son[s][i]][0],f[son[s][i]][1]);
		f[s][1]+=f[son[s][i]][0];
	}
	f[s][1]+=happy[s];
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		father[i]=i,scanf("%d",&happy[i]);
	int a,b;
	while(scanf("%d%d",&a,&b),(a!=0&&b!=0))
	{
		father[a]=b;
		son[b].push_back(a);
	}
	int start=n;
	while (father[start]!=start)
		start=father[start];
	dp(start);
	printf("%d",max(f[start][0],f[start][1]));
}
//DHOJ http://47.104.154.247/problem.php?cid=1091&pid=0
//LGOJ https://www.luogu.org/problemnew/show/P1352
