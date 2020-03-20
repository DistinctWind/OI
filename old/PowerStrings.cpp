#include <cstdio>
#include <cstring>
using namespace std;
const int MAXL=1e6+1;
char a[MAXL];
int len,p[MAXL];
inline void setup()
{
	p[1]=0;
	int j=0;
	for (int i=1;i<len;i++)
	{
		while (j>0&&a[j+1]!=a[i+1]) j=p[j];
		if (a[j+1]==a[i+1]) j++;
		p[i+1]=j;
	}
}
int main()
{
	while (scanf(" %s",a+1),a[1]!='.')
	{
		len=strlen(a+1);
		setup();
		if (len%(len-p[len])==0) printf("%d\n",len/(len-p[len]));
		else printf("1\n");
	}
}
