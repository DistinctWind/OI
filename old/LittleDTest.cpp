#include <cstdio>
#include <cstring>
#include <iostream>
#include <string.h>
#include <map>
using namespace std;
int n,q;
map<string,string> ans;
string question,a,b,c,d;
int main()
{
	scanf("%d%d%d",&n,&q);
	for (int i=1;i<=n;i++)
	{
		string t,a;
		cin>>t>>a;
		ans[t]=a;
	}
	for (int i=1;i<=q;i++)
	{
		cin>>question>>a>>b>>c>>d;
		string x=ans[question];
		if (x==a) printf("A\n");
		else if (x==b) printf("B\n");
		else if (x==c) printf("C\n");
		else printf("D\n");
	}
}
