#include <cstdio>
#include <cstring>
using namespace std;
const int MAXL=1e6+10;
char a[MAXL],b[MAXL];
int la,lb,p[MAXL],f[MAXL],s[MAXL];
int top;
inline void setup()
{
	int j=0;
	for (int i=2;i<=lb;i++)
	{
		while (j>0&&b[i]!=b[j+1]) j=p[j];
		if (b[i]==b[j+1]) j++;
		p[i]=j;
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf(" %s",a+1); scanf(" %s",b+1);
	la=strlen(a+1); lb=strlen(b+1);
	setup();
	for (int i=1,j=0;i<=la;i++)
	{
		while (j>0&&a[i]!=b[j+1]) j=p[j];
		if (a[i]==b[j+1]) j++;
		f[i]=j;
		s[++top]=i;
		if (j==lb)
		{
			int tmp=lb;
			while (tmp)
				tmp--,top--;
			j=f[s[top]];
		}
	}
	for (int i=1;i<=top;i++)
		putchar(a[s[i]]);
}
//LOJ https://loj.ac/problem/10048
//LGOJ https://www.luogu.org/problemnew/show/P4824
