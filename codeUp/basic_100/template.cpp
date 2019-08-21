#include <iostream>
using namespace std;

int main () {

    int a[11][11];
    
    // 맵 입력받고
    for (int i=1;i<=10;i++) {
        for ( int j=1;j<=10;j++) {
            scanf("%d ", &a[i][j]);
        }
    }
    // 이동 알고리즘 시작점에서 2인지 끝인지 확인하고 진행.
    int x=2, y=2;
    while(a[x][y]!=2) {
        // 이동한 곳을 표시
        a[x][y] = 9;

        if(a[x][y+1]==0) { // 오른쪽에 길이 있다면
            y+=1;
        } else {    // 오른쪽으로 갈 곳이 벽이라면 아래로
            if(a[x+1][y]==1) { // 아래도 벽이라면 끝
                break;
            }else if (a[x+1][y] == 2) {
                a[x+1][y] = 9;
                break;
            }
            else{
                x+=1;
            }
        }
    }
    
    // 결과 출력
    for (int i=1;i<=10;i++) {
        for (int j=1; j<=10;j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
