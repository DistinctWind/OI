#include <cstdio>
using namespace std;
int n,sum;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		sum+=(tmp%2);
	}
	if (sum%2==1) printf("Alice");
	else printf("Bob");
}
