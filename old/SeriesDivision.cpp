#include <iostream>
#define MAXN 1000002
using namespace std;
int m,n,num[MAXN],ans;
inline void read()
{
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>num[i];
}
inline void solve()
{
	int s=1;
	while (s<=n)
	{
		int temp=0,i;
		for (i=s;i<=n;i++)
		{
			if (temp+num[i]<=m)
				temp+=num[i];
			else break;
		}
		s=i;
		ans++;
	}
}
inline void out()
{
	cout<<ans<<endl;
}
int main()
{
	read();
	solve();
	out();
}
//LOJ https://loj.ac/problem/10006
//LGOJ https://www.luogu.org/problemnew/show/P1181
//DHOJ http://47.104.154.247/problem.php?cid=1095&pid=5
