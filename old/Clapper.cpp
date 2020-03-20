#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;
int t;
double ave;
int main()
{
	freopen("Log1.txt","w",stdout);
	t=30;
	for (int i=1;i<=t;i++)
	{
		clock_t start,end;
		system("MakerI.exe");
		start=clock();
		system("road.exe");
		end=clock();
		double t=(double)(end-start)/CLOCKS_PER_SEC;
		printf("%.3lf s\n",t);
		ave+=t;
		//if (t>1) return 0;
	}
	printf("Ave=%lf s\n",ave/t);
}
