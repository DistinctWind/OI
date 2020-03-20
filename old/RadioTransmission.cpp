#include <cstdio>
#include <cstring>
using namespace std;
const int MAXL=1e6+1;
int len,p[MAXL];
char a[MAXL];
inline void setup()
{
	int j=0;
	p[1]=0;
	for (int i=1;i<len;i++)
	{
		while (j>0&&a[i+1]!=a[j+1]) j=p[j];
		if (a[i+1]==a[j+1]) j++;
		p[i+1]=j;
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&len);
	scanf(" %s",a+1);
	setup();
	printf("%d\n",len-p[len]);
}
//LOJ https://loj.ac/problem/10045
