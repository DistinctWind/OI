#include <cstdio>
#include <cstring>
#include <cmath>
#define MAXN 12
using namespace std;
int a,b,num[MAXN],f[MAXN][MAXN];
int dfs(int pos,int last,bool limit)
{
	if (pos==-1) return 1;
	if (!limit&&f[pos][last]!=0) return f[pos][last];
	int up=limit?num[pos]:9;
	int res=0;
	for (int i=0;i<=up;i++)
		if (abs(i-last)>=2)
			res+=dfs(pos-1,i==0&&last==11?11:i,limit&&i==up);
	if (!limit) f[pos][last]=res;
	return res;
}
int solve(int temp)
{
	int pos=0;
	memset(num,0,sizeof(num));
	memset(f,0,sizeof(f));
	while (temp!=0)
		num[pos++]=temp%10,temp/=10;
	return dfs(pos-1,11,true);
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&a,&b);
	printf("%d\n",solve(b)-solve(a-1));
}
//LOJ https://loj.ac/problem/10165
