#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int MAXL=3001;
int t;
char str[MAXL];
string dfs(int pos)
{
	vector <string> vec;
	while (str[pos]=='0')
	{
		vec.push_back('0'+dfs(pos+1));
		pos+=vec.back().size();
	}
	sort(vec.begin(),vec.end());
	string tmp;
	int m=vec.size();
	for (int i=0;i<m;i++)
		tmp+=vec[i];
	return tmp+'1';
}
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d",&t);
	while (t--)
	{
		scanf(" %s",str);
		string a=dfs(0);
		scanf(" %s",str);
		string b=dfs(0);
		if (a==b)
			printf("same\n");
		else
			printf("different\n");
	}
}
//DHOJ http://47.104.154.247/problem.php?cid=1124&pid=3
