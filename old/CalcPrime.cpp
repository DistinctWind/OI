#include <cstdio>
#include <cmath>
using namespace std;
const int MAXN=100001;
bool isPrime[MAXN];
int main()
{
	freopen("Prime.txt","w",stdout);
	for (int i=2;i<MAXN;i++)
		isPrime[i]=true;
	for (int i=2;i<=sqrt(MAXN);i++)
	{
		for (int j=2;i*j<=MAXN;j++)
			isPrime[i*j]=false;
	}
	for (int i=1;i<MAXN;i++)
		if (isPrime[i])
			printf("%d,",i);
}
