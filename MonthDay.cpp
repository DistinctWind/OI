/*from
LGOJ https://www.luogu.com.cn/problem/P5716
*/
#include <cstdio>
using namespace std;
int y, m;
bool judge(int);
int main(){
    scanf("%d%d", &y, &m);
    if (m==2){
        if (judge(y)){
            printf("29");
        } else {
            printf("28");
        }
    } else {
        switch (m) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                printf("31");
                break;
            case 4: case 6: case 9: case 11:
                printf("30");
                break;
        }
    }
    return 0;
}
bool judge(int x){
    if (((x%100==0)&&(x%400==0))||((x%100!=0)&&(x%4==0))){
        return true;
    } else {
        return false;
    }
}