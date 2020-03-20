#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <ctime>
using namespace std;
int rand_between(int l,int r)
{
	return (long long)rand()*rand()%(r-l+1)+l;
}
int n;
int main()
{
	freopen("in.txt","w",stdout);
	srand((unsigned int)time(0));
	n=rand_between(1,100000);
	printf("%d\n",n);
	for (int i=1;i<=n;i++)
		printf("%d ",rand_between(1,10000));
}
