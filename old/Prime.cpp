#include <cmath>
#include <cstdio>
#define MAXN 10000001
using namespace std;
int cnt;
bool isPrime[MAXN];
int main()
{
	freopen("out.txt","w",stdout);
	for (int i=2;i<=MAXN;i++)
		isPrime[i]=true;
	for (int i=2;i<=sqrt(MAXN);i++)
		if (isPrime[i]==true)
			for (int j=2;j<=MAXN/i;i++)
				isPrime[i*j]=false;
	for (int i=10000;i<=100000;i++)
		if (isPrime[i]==true)
			cnt++,printf("%d,",i);
	printf("%d",cnt);
}
