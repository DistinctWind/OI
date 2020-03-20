#include <cstdio>
#include <cstring>
using namespace std;
const int MAXP=11;
int n,m;
int num[MAXP],f[MAXP][MAXP];
int dfs(int pos,int last,bool limit)
{
	if (pos==-1) return 1;
	if (!limit&&f[pos][last]!=-1) return f[pos][last];
	int up=limit?num[pos]:9;
	int res=0;
	for (int i=0;i<=up;i++)
	{
		if (i==4) continue;
		if (last==6&&i==2) continue;
		res+=dfs(pos-1,i,limit&&i==up);
	}
	if (!limit) f[pos][last]=res;
	return res;
}
inline int solve (int temp)
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
	while (scanf("%d%d",&n,&m),n!=0&&m!=0)
		printf("%d\n",solve(m)-solve(n-1));
}
//LOJ https://loj.ac/problem/10167
