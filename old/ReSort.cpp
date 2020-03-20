#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN=1010;
const int MAXM=11;
const int MOD=1e8+7;
string s;
int len,tm,sum,sum1,sum2,pos;
int f[MAXN][MAXM],cnt[MAXM];
inline void add(int u)
{
	for (int i=tm;i>=0;i--)
		for (int j=0;j<11;j++)
			f[i+1][(j+u)%11]=(f[i+1][(j+u)%11]+f[i][j])%MOD;
	tm++; cnt[u]++;
}
inline void del(int u)
{
	for (int i=0;i<=tm;i++)
		for (int j=0;j<11;j++)
			f[i+1][(j+u)%11]=((f[i+1][(j+u)%11]-f[i][j])%MOD+MOD)%MOD;
	tm--; cnt[u]--;
}
void print()
{
	for (int i=0;i<=tm;i++)
	{
		for (int j=0;j<11;j++)
			printf("%d ",f[i][j]);
		putchar('\n');
	}
	putchar('\n');
}
int main()
{
	//freopen("in.txt","r",stdin);
	cin>>s;
	f[0][0]=1;
	len=s.length();
	for (int i=0,j;i<len;i++)
	{
		//print();
		j=s[i]-'0';
		add(j);
		sum=(sum+j)%11;
	}
	sum1=sum2=sum*6%11;
	for (int i=1,j;i<=len;i++)
	{
		if (i&1)
		{
			pos=len/2-i/2;
			sum=sum1;
		}
		else
		{
			pos=(len+1)/2-(i+1)/2;
			sum=sum2;
		}
		for (j=9;j>=0;j--)
		{
			if (cnt[j])
			{
				del(j);
				if (f[pos][sum]>0) break;
				add(j);
			}
		}
		if (i&1) sum2=(sum2-j+11)%11;
		else sum1=(sum1-j+11)%11;
		cout<<j;
	}
}
