#include <iostream>
#include <algorithm>
#define MAXSG 501
using namespace std;
int m,n,punishment;
bool used[MAXSG];
struct SMALLGAME{
	int t,w;
}sg[MAXSG];
bool operator < (SMALLGAME a,SMALLGAME b)
{
	return a.w>b.w;
}
int main()
{
	cin>>m>>n;
	for (int i=1;i<=n;i++)
		cin>>sg[i].t;
	for (int i=1;i<=n;i++)
		cin>>sg[i].w;
	sort(sg+1,sg+1+n);
	for (int i=1;i<=n;i++)
	{
		bool p=true;
		for (int j=sg[i].t;j>=1;j--)
			if (used[j]==false)
			{
				p=false;
				used[j]=true;
				break;
			}
		if (p==true)
			punishment+=sg[i].w;
	}
	cout<<m-punishment<<endl;
}
//DHOJ http://47.104.154.247/problem.php?cid=1095&pid=2
//LGOJ https://www.luogu.org/problemnew/show/P1230
//LOJ https://loj.ac/problem/10004
