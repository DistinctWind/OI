#include <cstdio>
using namespace std;
const int score[5][5]=
{
	{0,0,1,1,0},
	{1,0,0,1,0},
	{0,1,0,0,1},
	{0,0,1,0,1},
	{1,1,0,0,0},
};
const int MAXN=210;
int n,na,nb;
int amark,bmark;
int a[MAXN],b[MAXN];
int astate(int x)
{
	return a[(x-1)%na];
}
int bstate(int x)
{
	return b[(x-1)%nb];
}
int main()
{
	//freopen("rps.in","r",stdin);
	//freopen("rps.out","w",stdout);
	scanf("%d%d%d",&n,&na,&nb);
	for (int i=0;i<na;i++)
		scanf("%d",&a[i]);
	for (int i=0;i<nb;i++)
		scanf("%d",&b[i]);
	for (int i=1;i<=n;i++)
	{
		amark+=score[astate(i)][bstate(i)];
		bmark+=score[bstate(i)][astate(i)];
	}
	printf("%d %d",amark,bmark);
}
