#include <cstdio>
#include <cstring>
#define int long long
#define MAXN 155
using namespace std;
int state[MAXN],num[MAXN],n,K,f[12][MAXN][MAXN],s0;
inline void setup()
{
	memset(f,0,sizeof(f));
	for (int i=0;i<(1<<n);i++)
	{
		if (i&(i<<1)) continue;
		int cnt=0;
		for (int j=0;j<n;j++)
			if (i&(1<<j))
				cnt++;
		s0++;
		state[s0]=i;
		num[s0]=cnt;
	}
}
inline void dp()
{
	f[0][1][0]=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=s0;j++)
			for (int k=num[j];k<=K;k++)
				for (int l=1;l<=s0;l++)
					if (!(state[j]&state[l])&&!(state[j]&(state[l]<<1))&&!(state[j]&(state[l]>>1)))
						f[i][j][k]+=f[i-1][l][k-num[j]];
	int ans=0;
	for (int i=1;i<=s0;i++)
		ans+=f[n][i][K];
	printf("%lld",ans);
}
main()
{
	//freopen("in.txt","r",stdin);
	scanf("%lld%lld",&n,&K);
	setup();
	dp();
}
//LOJ https://loj.ac/problem/10170
