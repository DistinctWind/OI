#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
string a[7];
string t[26]={"one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty","a","both","another","first","second","third"};
int map[26]={1,4,9,16,25,36,49,64,81,00,21,44,69,96,25,56,89,24,61,0,1,4,1,1,4,9};
int f[10],c;
bool flag;
int main()
{
	for (int i=1;i<=6;i++)
	{
		cin>>a[i];
		for (int j=0;j<=25;j++)
		{
			if (t[j]==a[i])
			{
				c++;
				f[c]=map[j];
				break;
			}
		}
	}
	sort(f+1,f+c+1);
	for (int i=1;i<=c;i++)
	{
		if (flag)
			printf("%.2d",f[i]);
		else
			if (f[i])
			{
				printf("%d",f[i]);
				flag=true;
			}
	}
	if (!flag)
		printf("0");
}
