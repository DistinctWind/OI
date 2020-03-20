#include <cstdio>
#include <vector>
#include <cstring>
#define MAXN 12
using namespace std;
int a,b,f[MAXN][MAXN];
int num[MAXN];
int dfs(int pos,int state,bool limit)
{
	if (pos==-1) return 1;
	if (!limit&&f[pos][state]!=0) return f[pos][state];
	int res=0;
	int up=limit?num[pos]:9;
	for (int i=state;i<=up;i++)
		res+=dfs(pos-1,i,limit&&i==up);
	if (!limit) f[pos][state]=res;
	return res;
}
int solve(int now)
{
	int pos=0;
	memset(f,0,sizeof(f));
	memset(num,0,sizeof(num));
	while (now!=0)
		num[pos++]=now%10,now/=10;
	return dfs(pos-1,0,true);
} 
int main()
{
	//freopen("in.txt","r",stdin);
	while (scanf("%d%d",&a,&b)!=EOF)
		printf("%d\n",solve(b)-solve(a-1));
}
//LOJ https://loj.ac/problem/10164
