#include <cstdio>
using namespace std;
const int MAXN=5e5+10;
struct Rec{
	int x1,x2,y1,y2;
}rec[MAXN];
int n,m;
int read()
{
	int x=0;
	char tmp=getchar();
	while (tmp<'0'||tmp>'9') tmp=getchar();
	while ('0'<=tmp&&tmp<='9')
	{
		x=x*10+tmp-'0';
		tmp=getchar();
	}
	return x;
}
int main()
{
	n=read(); m=read();
	for (int i=1;i<=n;i++)
	{
		rec[i].x1=read(); rec[i].y1=
	}
}
