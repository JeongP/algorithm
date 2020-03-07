/*
   #SOL#
    1. DP 이용.
    2. maxCandy[i][j] = map[i][j]에서 얻을 수 있는 가장 많은 캔디 수.
    3. 구해야 하는 것은 maxCandy[N][M];
    4. 가장 윗벽은 좌측에 있는 값에 영향을 받고, 가장 왼쪽벽은 바로 위의 값으로 부터 영향을 받기때문에, 미리 채워준다.
    5. maxCandy[i][j] 는 (i-1,j), (i,j-1), (i-1,j-1) 중 큰 값으로..
 */

#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1000 + 1;
int N,M;
int map[MAX][MAX];
int maxCandy[MAX][MAX];

void input () {
    cin >> N >> M;
    
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            cin >> map[i][j];
        }
    }
}

void fillTop() {
    maxCandy[1][1] = map[1][1];
    for(int i=2;i<=M;i++) {
        maxCandy[1][i] = maxCandy[1][i-1] + map[1][i];
    }
}

void fillLeft() {
    for(int i=2;i<=N;i++) {
        maxCandy[i][1] = maxCandy[i-1][1] + map[i][1];
    }
}


void prt() {
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            cout << maxCandy[i][j] << " ";
        }
        cout << endl;
    } 
}

void dp() {
    for(int i=2;i<=N;i++) {
        for(int j=2;j<=M;j++) {
            maxCandy[i][j] = max(maxCandy[i-1][j], max(maxCandy[i][j-1], maxCandy[i-1][j-1])) + map[i][j];
        }
    } 
    // maxCandy 전체 출력.
    // prt();
    cout << maxCandy[N][M] << endl;
}

void solution() {
    fillTop();
    fillLeft();
    dp();
}

int main () {
    
    input();
    solution();
    return 0;
}