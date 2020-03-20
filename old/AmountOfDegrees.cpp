#include <cstdio>
#include <cstring>
#define MAXN 32
using namespace std;
int x,y,k,b,res1,res2;
int f[MAXN][MAXN];
inline void setup()
{
	f[0][0]=1;
	for (int i=1;i<=31;i++)
	{
		f[i][0]=f[i-1][0];
		for (int j=1;j<=i;j++)
			f[i][j]=f[i-1][j]+f[i-1][j-1];
	}
}
inline int change_sys(int target)
{
	if (b==2) return target;
	int num[MAXN],i=0,n=0;
	memset(num,0,sizeof(num));
	while (target!=0)
	{
		num[i++]=target%b;
		target/=b;
	}
	for (int j=i-1;j>=0;j--)
	{
		if (num[j]==0||num[j]==1)
		{
			n=n<<1;
			n+=num[j];
		}
		else
		{
			for (int k=j;k>=0;k--)
				n=n<<1,n+=1;
			break;
		}
	}
	return n;
}
inline int cal(int x)
{
	int tot=0,ans=0;
	for (int i=31;i>0;i--)
	{
		if (x&(1<<i))
		{
			tot++;
			if (tot>k) break;
			x=x^(1<<i);
		}
		if ((1<<(i-1))<=x) ans+=f[i-1][k-tot];
	}
	if (tot+x==k) ans++;
	return ans;
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d%d%d%d",&x,&y,&k,&b);
	setup();	
	res1=cal(change_sys(x));
	res2=cal(change_sys(y));
	printf("%d",res2-res1);
}
//LOJ https://loj.ac/problem/10163
