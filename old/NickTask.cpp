#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN=1e4+10;
const int MAXK=1e4+10;
int n,k,sum[MAXN],num;
int f[MAXN];
struct Task{
	int st,et;
}task[MAXK];
bool cmp(Task a,Task b)
{
	return a.st>b.st;
}
inline void print()
{
	for (int i=1;i<=n;i++)
		printf("%d ",f[i]);
	putchar('\n');
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&k);
	for (int i=1;i<=k;i++)
		scanf("%d%d",&task[i].st,&task[i].et),sum[task[i].st]++;
	sort(task+1,task+1+k,cmp);
 	for (int i=n;i>=1;i--)
	{
		//print();
		if (sum[i]==0) f[i]=f[i+1]+1;
		else
		{
			for (int j=1;j<=sum[i];j++)
				f[i]=max(f[i],f[i+task[++num].et]);
		}
	}
	printf("%d",f[1]);
}
