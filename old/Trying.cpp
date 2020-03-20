#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
struct Num{
	char num[10];
	void print(){
		for (int i=1;i<=5;i++)
			printf("%c ",num[i]);
		putchar('\n');
	}
};
int num[7]={0,1,1,2,3,3,4};
int main()
{
	int len=unique(num+1,num+1+6)-num;
	cout<<len-1;
}
