#include <cstdio>
#define MAXN 100001
using namespace std;
struct PERSON{
	int x;
	PERSON *l;
	PERSON(){
		x=0;
		l=NULL;
	}
}p[MAXN];
int n,m;
void add(int aim,int k,PERSON &now)
{
	switch (k)
	{
		case 0:
			now.l=&p[aim-1];
			p[aim].l=&now;
			break;
		case 1:
			now.l=&p[aim];
			p[aim+1].l=&now;
			break;
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		p[i].x=i;
		int k,p;
		scanf("%d%d",&k,&p);
		add(i,k,p[i]);
	}
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
	{
		
	}
}
