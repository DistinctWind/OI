#include <cstdio>
#include <cmath>
using namespace std;
int s,t;
int ans;
int prime[10000001],cnt;
bool isPrime[10000001];
int getPrime(int max)
{
	for (int i=2;i<=max;i++)
		isPrime[i]=true;
	for (int i=2;i<=sqrt(max);i++)
		if (isPrime[i]==true)
			for (int j=2;j<=max/i;j++)
				isPrime[i*j]=false;
	for (int i=2;i<=max;i++)
		if (isPrime[i]==true)
			prime[++cnt]=i;
}
int divide(int num)
{
	int ans=1;
	for (int i=1;i<=cnt&&prime[i]<=num;i++)
	{
		int times=0;
		while (num%prime[i]==0)
		{
			num/=prime[i];
			times++;
		}
		if (times!=0)
			ans*=times+1; 
	}
	return ans;
}
int main()
{
	scanf("%d%d",&s,&t);
	getPrime(t);
	for (int i=s;i<=t;i++)
		ans+=divide(i);
	printf("%d",ans);
}
