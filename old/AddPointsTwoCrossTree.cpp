#include <cstdio>
#define MAXN 300
using namespace std;
int n,root[MAXN][MAXN];
long long f[MAXN][MAXN];
long long dp(int l,int r)
{
	if (l>r) return 1;
	if (f[l][r]!=0) return f[l][r];
	long long now;
	for (int next=l;next<=r;next++)
	{
		now=dp(l,next-1)*dp(next+1,r)+f[next][next];
		if (now>f[l][r])
		{
			f[l][r]=now;
			root[l][r]=next;
		}
	}
	return f[l][r];
}
void print(int l,int r)
{
	if (l>r) return;
	printf("%d ",root[l][r]);
	print(l,root[l][r]-1);
	print(root[l][r]+1,r);
}
int main()
{
	//freopen("out.txt","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%ld",&f[i][i]),root[i][i]=i;
	dp(1,n);
	printf("%ld\n",f[1][n]);
	print(1,n);
}
