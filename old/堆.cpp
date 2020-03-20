#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN=1000010;
int n,t;
int data[MAXN<<2];
inline void up(int p)
{
	while (p>1)
	{
		if (data[p]<data[p>>1])
		{
			swap(data[p],data[p>>1]);
			p>>=1;
		}
		else break;
	}
}
inline void down(int p)
{
	int s=p<<1;
	while (s<=n)
	{
		if (s<n&&data[s]>data[s|1]) s|=1;
		if (data[s]<data[p])
		{
			swap(data[s],data[p]);
			p=s,s=p<<1;
		}
		else break;
	}
}
inline int gettop()
{
	return data[1];
}
inline void insert(int x)
{
	data[++n]=x;
	up(n);
}
inline void extract()
{
	data[1]=data[n--];
	down(1);
}
int read()
{
	int x=0; char a=getchar();
	while (a<'0'||a>'9') a=getchar();
	while ('0'<=a&&a<='9') x=x*10+a-'0',a=getchar();
	return x;
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	t=read();
	for (int i=1,a,b;i<=t;i++)
	{
		a=read();
		if (a==1)
		{
			b=read();
			insert(b);
		}
		else if (a==2)
		{
			printf("%d\n",gettop());
		}
		else
		{
			extract();
		}
	}
}
