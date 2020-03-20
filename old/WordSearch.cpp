#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
string aim,s;
int cnt,f;
bool flag;
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	cin>>aim; getchar();
	getline(cin,s);
	transform(aim.begin(),aim.end(),aim.begin(),::tolower);
	transform(s.begin(),s.end(),s.begin(),::tolower);
	int u=0;
	aim=' '+aim+' ';
	s=' '+s+' ';
	while (u=s.find(aim,u),u!=-1)
	{
		cnt++;
		if (!flag)
		{
			f=u;
			flag=true;
		}
		u++;
	}
	if (cnt==0) printf("-1");
	else printf("%d %d",cnt,f);
}
