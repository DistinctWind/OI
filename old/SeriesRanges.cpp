#include <iostream>
#include <queue>
#define MAXN 50001
using namespace std;
int n;
int num[MAXN];
inline void setup()
{
	
}
inline int max()
{
	priority_queue <int,vector<int>,greater<int> > q;
	for (int i=1;i<=n;i++)
		q.push(num[i]);
	while (q.size()>1)
	{
		int a,b;
		a=q.top(); q.pop();
		b=q.top(); q.pop();
		q.push(a*b+1);
	}
	return q.top();
}
inline int min()
{
	priority_queue <int,vector<int>,less<int> > q;
	for (int i=1;i<=n;i++)
		q.push(num[i]);
	while (q.size()>1)
	{
		int a,b;
		a=q.top(); q.pop();
		b=q.top(); q.pop();
		q.push(a*b+1);
	}
	return q.top();
}
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>num[i];
	cout<<max()-min();
}
//LOJ https://loj.ac/problem/10005
//DHOJ http://47.104.154.247/problem.php?cid=1095&pid=4
