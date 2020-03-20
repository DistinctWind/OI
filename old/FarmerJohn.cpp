#include <cstdio>
using namespace std;
const int mod=1e8;
struct line{
	int num,state[4097];
}l[13];
int m,n;
long long f[13][4097];
inline void setup(int i,int s)
{
	l[i].num=0;
	for (int j=0;j<(1<<n);j++)
	{
		if ((j&(j<<1))||(j&(j>>1))||(j&s)) continue;
		l[i].state[++l[i].num]=j;
	}
}
inline void dp()
{
	for (int i=1;i<=l[1].num;i++)
		f[1][i]=1;
	for (int i=2;i<=m;i++)
		for (int j=1;j<=l[i].num;j++)
			for (int k=1;k<=l[i-1].num;k++)
			{
				if (l[i].state[j]&l[i-1].state[k]) continue;
				f[i][j]=(f[i][j]+f[i-1][k])%mod;
			}
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&m,&n);
	for (int i=1;i<=m;i++)
	{
		int temp=0;
		for (int j=1;j<=n;j++)
		{
			int state=0;
			scanf("%d",&state);
			temp=(temp<<1)+1-state;
		}
		setup(i,temp);
	}
	dp();
	int ans=0;
	for (int i=1;i<=l[m].num;i++)
		ans=(ans+f[m][i])%mod;
	printf("%d",ans);
}
/*inline void print()
{
	for (int i=0;i<=m;i++)
	{
		for (int j=0;j<=state[0];j++)
		{
			for (int k=0;k<=m*n/2;k++)
				printf("%d ",f[i][j]);
			putchar('\n');
		}
		putchar('\n');
	}
	putchar('\n');
}
inline void dp()
{
	for (int i=1;i<=state[0];i++)
	{
		if ((state[i]|line[1])>line[1]) continue;
		f[0][i][0]=1;
	}
	for (int i=1;i<=m;i++)
		for (int j=1;j<=state[0];j++)
		{
			if ((state[j]|line[i])>line[i]) continue;
			for (int k=num[j];k<=(n+1)/2;k++)
				for (int l=1;l<=state[0];l++)
					if (!(state[j]&state[l])&&!(state[l]&line[i-1]))
					{
						f[i][j][k]+=f[i-1][l][k-num[j]]%mod;
						print();
					}
		}
	int ans=0;
	for (int t=0;t<=m*n/2;t++)
		for (int i=1;i<=state[0];i++)
			ans+=f[m][i][t]%mod;
	printf("%d",ans);
}*/
/*inline void setup()
{
	for (int i=0;i<(1<<n);i++)
	{
		if (i&(i<<1)) continue;
		state[0]++;
		state[state[0]]=i;
		int cnt=0;
		for (int j=0;j<=n;j++)
			if (i&(1<<j))
				cnt++;
		num[state[0]]=cnt;
	}
}
inline void dp()
{
	for (int i=1;i<=state[0];i++)
	{
		if ((state[i]|line[1])>line[1])
			continue;
		f[1][i]=1;
	}
	for (int i=2;i<=m;i++)
		for (int j=1;j<=state[0];j++)
		{
			if ((state[j]|line[i])>line[i]) continue;
			for (int k=1;k<=state[0];k++)
			{
				if ((state[k]|line[i-1])>line[i-1]||state[j]&state[k]) continue;
				f[i][j]+=f[i-1][k]%mod;
			}
		}
	int ans=0;
	for (int i=1;i<=state[0];i++)
		ans+=f[m][i]%mod;
	printf("%d",ans);
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d%d",&m,&n);
	for (int i=1;i<=m;i++)
	{
		int temp=0;
		for (int j=1;j<=n;j++)
		{
			int now;
			scanf("%d",&now);
			temp=(temp<<1)+now;
		}
		line[i]=temp;
	}
	setup();
	dp();
}*/
//LOJ https://loj.ac/problem/10171
