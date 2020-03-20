#include <cstdio>
#include <vector>
#include <limits.h>
#define MAXN 1501
using namespace std;
int n,funds[MAXN],father[MAXN],f[MAXN][3];
vector <int> son[MAXN];
int min(int a,int b)
{
	return a>b?b:a;
}
void dp(int s)
{
	int d=INT_MAX;
	for (int i=0;i<son[s].size();i++)
	{
		int j=son[s][i];
		if (son[s].size()==0)
			continue;
		dp(j);
		f[s][0]+=min(f[j][1],f[j][2]);
		f[s][1]+=min(f[j][1],f[j][2]);
		f[s][2]+=min(f[j][0],min(f[j][1],f[j][2]));
		d=min(d,f[j][2]-min(f[j][1],f[j][2]));
	}
	f[s][1]+=d;
	f[s][2]+=funds[s];
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		father[i]=i;
	for (int i=1;i<=n;i++)
	{
		int num,s;
		scanf("%d",&num);
		scanf("%d",&funds[num]);
		scanf("%d",&s); 
		for (int i=1;i<=s;i++)
		{
			int temp;
			scanf("%d",&temp);
			son[num].push_back(temp);
			father[temp]=num;
		}
	}
	int start=1;
	while (father[start]!=start)
		start=father[start];
	dp(start);
	printf("%d",min(f[start][1],f[start][2]));
}
