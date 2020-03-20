#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 310;
int a[MAXN],f[MAXN][MAXN];
inline void solve(){
	memset(f,0x3f,sizeof(f));
	for (int i=1;i<=n;i++)
		f[i][i]=a[i];
	for (int len=2;len<=n;len++){
		for (int i=1,j;i<=n&&i+k-1<=n;i++){
			j=i+k-1;
			for (int k=i;k<j;k++){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	printf("%d\n",f[1][n]);
}
int main(){
	solve();
}
//NOI1995
