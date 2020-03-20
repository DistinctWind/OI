#include <cstdio>
#include <cstring>
#define MAXN 14
#define MAXS 100
using namespace std;
int a,b,n;
int num[MAXN],f[MAXN][MAXS];
int dfs(int pos,int sum,bool limit)
{
	if (pos==-1&&sum%n==0) return 1;
	else if (pos==-1) return 0;
	if (!limit&&f[pos][sum]!=-1) return f[pos][sum];
	int res=0,up=limit?num[pos]:9;
	for (int i=0;i<=up;i++)
		res+=dfs(pos-1,sum+i,limit&&i==up);
	if (!limit) f[pos][sum]=res;
	return res;
}
int solve(int temp)
{
	int pos=0;
	memset(num,0,sizeof(num));
	memset(f,-1,sizeof(f));
	while (temp!=0)
		num[pos++]=temp%10,temp/=10;
	return dfs(pos-1,0,true);
}
int main()
{
	while (scanf("%d%d%d",&a,&b,&n)!=EOF)
		printf("%d\n",solve(b)-solve(a-1));
}
//LOJ https://loj.ac/problem/10166
