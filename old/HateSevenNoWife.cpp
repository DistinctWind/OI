#include <cstdio>
#include <cstring>
#define MAXP 30
#define MAXS 10
using namespace std;
const long long Mod=1e9+7;
struct data{
	long long cnt,sum,qsum;
	data():cnt(0),sum(0),qsum(0){}
	data(long long c,long long s,long long q):cnt(c),sum(s),qsum(q){}
};
int t;
long long l,r;
long long num[MAXP];
long long ten[MAXP];
data dp[MAXP][MAXS][MAXS];
inline void setup()
{
	ten[0]=1;
	for (int i=1;i<=19;i++)
		ten[i]=ten[i-1]*10;
}
data dfs(int pos,int s,int m,bool limit)
{
	if (pos==-1)
	{
		if (s!=0&&m!=0)
			return data(1,0,0);
		else
			return data(0,0,0);
	}
	if (!limit&&dp[pos][s][m].sum!=0) return dp[pos][s][m];
	data ans;
	int up=limit?num[pos]:9;
	for (int i=0;i<=up;i++)
	{
		if (i==7) continue;
		int temp_s=(s%7+i%7)%7;
		int temp_m=(m*10%7+i%7)%7;
		data temp=dfs(pos-1,temp_s,temp_m,limit&&i==up);
		long long res=(i*ten[pos])%Mod;
		ans.cnt=(ans.cnt+temp.cnt%Mod)%Mod;
		ans.sum=(ans.sum+(temp.sum%Mod+(res*temp.cnt)%Mod)%Mod)%Mod;
		long long k1=((res*res)*temp.cnt)%Mod;
		long long k2=((2*res)*temp.sum)%Mod;
		ans.qsum=(ans.qsum+(k1+k2)%Mod+temp.qsum%Mod)%Mod;
	}
	if (!limit) dp[pos][s][m]=ans;
	return ans;
}
long long solve(long long temp)
{
	data x;
	int pos=0;
	while (temp!=0)
		num[pos++]=temp%10,temp/=10;
	x=dfs(pos-1,0,0,true);
	return x.qsum%Mod;
}
int main()
{
	freopen("in.txt","r",stdin);
	setup();
	scanf("%d",&t);
	for (int i=1;i<=t;i++)
	{
		scanf("%lld%lld",&l,&r);
		printf("%lld\n",(solve(r)-solve(l-1)+Mod)%Mod);
	}
}
//LOJ https://loj.ac/problem/10168
