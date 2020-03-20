#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int base=127,mod=100000007;
const int pos[10]={47,50,53,56,59,62,65,68,71,74};
const string final="Begin the Escape execution at the Break of Dawn";
string s;
set <int> judge;
int myHash(string s)
{
	int temp=0;
	for (int i=0;i<s.size();i++)
		temp=(temp*base+s[i])%mod;
	return temp;
}
//Refers "IN or OUT"
bool ioo(string now)
{
	int i;
	bool go=true;
	for (i=0;i<now.size();i++)
		if (now[i]=='C'||now[i]=='O'||now[i]=='W')
		{
			go=ioo(now.substr(i+1,now.size()-i-1));
			break;
		}
	if (go==false)
	{
		return false;
	}
	if (final.find(now.substr(0,i))==-1)
		return false;
	else
		return true;
}
bool prepos(string now)
{
	int first_c=now.find('C');
	int last_w=now.rfind('W');
	int last=now.size()-last_w-1;
	string prefix,postfix,rpre,rpos;
	prefix=now.substr(0,first_c);
	postfix=now.substr(last_w+1,last);
	rpre=final.substr(0,first_c);
	rpos=final.substr(final.size()-last,last);
	if ((prefix!=rpre)||(postfix!=rpos))
		return false;
	else
		return true;
}
void dfs(string now,int times)
{
	if (now==final)
	{
		printf("1 %d",times);
		exit(0);
	}
	if (ioo(now)==false) return;
	if (prepos(now)==false) return;
	for (int o=0;o<now.size();o++) if (now[o]=='O')
		for (int c=0;c<o;c++) if (now[c]=='C')
			for (int w=now.size()-1;w>o;w--) if (now[w]=='W')
			{
				int h;
				string t1,t2,t3,t4;
				t1=now.substr(0,c);
				t2=now.substr(c+1,o-c-1);
				t3=now.substr(o+1,w-o-1);
				t4=now.substr(w+1,now.size()-w);
				string temp=t1+t3+t2+t4;
				//cout<<temp<<endl;
				if (h=myHash(temp),judge.count(h)==1)
					continue;
				judge.insert(h);
				dfs(temp,times+1);
			}
						
}
int main()
{
	getline(cin,s);
	bool flag=false;
	for (int i=0;i<10;i++)
		if (s.size()==pos[i])
			flag=true;
	if (flag==false)
	{
		cout<<"0 0";
		return 0;
	}
	flag=prepos(s);
	if (flag==false)
	{
		cout<<"0 0";
		return 0;
	}
	flag=ioo(s);
	if (flag==false)
	{
		cout<<"0 0";
		return 0;
	}
	dfs(s,0);
	cout<<"0 0";
}
