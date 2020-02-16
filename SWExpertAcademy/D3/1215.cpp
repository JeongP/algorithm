/*

    1. 모든 점에서 체크한다.
    2. 시작점과 끝점이 같다면, 시작점은++, 끝점은--한다. 
    3. 시작점이 끝점보다 크게 되는 경우 flag 변수를 두어 true를 만들고, 반복문을 빠져나온다
    4. flag 변수가 true이면 answer++ 를 진행하고
    5. 마지막에 answer를 출력한다
    
 */

#include <iostream>
#include <cstring>

#define MAX 8
using namespace std;

int Len, Answer;
char map[MAX][MAX];

void initialize() {
    Answer = 0;
    Len = 0;
    memset(map,0,sizeof(map));
}

void input() {
    cin >> Len;
    for( int i=0;i<MAX;i++) {
        for(int j=0;j<MAX;j++) {
            cin >> map[i][j];
        }
    }
}

void check_garo(int x, int y) {
    int sx = x;
    int sy = y;
    int ex = x;
    int ey = y + Len -1;
    bool Flag = false;

    while(1) {
        if(sy > ey) {
            Flag = true;
            break;
        }

        if(map[sx][sy] == map[ex][ey]) {
            sy++;
            ey--;
        }else{
            break;
        }
    }
    if(Flag == true) Answer++;
}

void check_sero(int x,int y) {
    int sx = x;
    int sy = y;
    int ex = x + Len -1;
    int ey = y;
    bool flag = false;

    while(1) {
        if(sx > ex) {
            flag = true;
            break;
        }

        if(map[sx][sy] == map[ex][ey]) {
            sx++;
            ex--;
        }else {
            break;
        }
    }
    if(flag == true) Answer++;
}

void solution() {
    for(int i=0;i<MAX;i++) {
        for(int j=0;j<MAX;j++) {
            if(j+Len <= MAX) check_garo(i,j);
            if(i+Len <= MAX) check_sero(i,j);
        }
    }
}
void solve() {
    int tc = 10;
    for( int t=1; t<=tc; t++) {
        initialize();
        input();
        solution();

        cout << "#" << t << " " << Answer << endl;
    }
}
int main () {
    solve();
    return 0;
}

