#include <iostream>
using namespace std;

int main () {
    
    // 1082
    int n;
    scanf("%x", &n);

    for (int i=1;i<=15;i++) {
        printf("%X*%X=%X\n", n,i,n*i);
    }


    // 1085
    int h, b, c, s; 
    double result;
    scanf("%d %d %d %d", &h, &b, &c, &s);
    result = h * b * c * s / 8;
    result = result / 1024;
    result = result / 1024;

    printf("%.1f MB", result);
    return 0;

    // 1086
    int w, h, b;
    double result;
    scanf("%d %d %d", &w, &h, &b);
    result = w * h * b / 8;
    result = result / 1024;
    result = result / 1024;
    printf("%.2f MB", result);


    // 1090
    int a, b, c, i;
    scanf("%d%d%d", &a, &b, &c);
    for (i = 1; i < c; i++)
    {
        a *= b;
    }
    printf("%d", a);


    // 1094
    int n;
    int a[10000] = {};
    scanf("%d", &n);
    
    for (int i=0; i<n;i++) {
        scanf("%d", &a[i]);
    }
    
    for(int j=n-1;j>=0;n--) {
        printf("%d ", a[j]);
    }
    
    // 1095
    int n, min=24;
    int a[10000];
    scanf("%d", &n);

    for (int i=0;i<n;i++){
        scanf("%d ", &a[i]);
        if(min > a[i]) min = a[i];
    }
    
    cout << min << endl;

    // 1096 바둑

    // 1098: 설탕과자 뽑기
    int w,h;
    int a[101][101] = {0,};
    scanf("%d %d", &h, &w);

    int n;
    scanf("%d", &n);

    int x,y,l,d;

    for (int i=0;i<n;i++) {
        scanf("%d %d %d %d", &l, &d, &x, &y);
        if(d == 0) {
            // 길이만큼 가로로 1채우기
            for(int i=1;i<=l;i++) {
                a[x][y] = 1;
                y+=1;
            }
        } else {
            // 길이만큼 세로로 1채우기
            for(int i=1;i<=l;i++) {
                a[x][y] = 1;
                x+=1;
            }
        }
    }

    for (int i=1; i<=h; i++) {
        for (int j=1; j<=w;j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    // 1099
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
}
