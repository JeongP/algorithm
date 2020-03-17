#include <iostream>

using namespace std;
int map[10][10];

void input() {
    for(int i=1;i<=9;i++) {
        for(int j=1;j<=9;j++) {
            cin >> map[i][j];
        }
    }
}

bool endCheck() {
    for(int i=1;i<=9;i++) {
        for(int j=1;j<=9;j++) {
            if(map[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

void prt() {
    for(int i=1;i<=9;i++) {
        for(int j=1;j<=9;j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}
void solution() {
    
    while(1) {

        // 종료 조건
        if(endCheck()) {
            prt();
            return;
        }
        // 가로 세로 채워 넣기
        for(int i=1;i<=9;i++) {
            int cnt = 0;
            int sum = 0;
            int idx;
            // 가로 채워넣기.
            for(int j=1;j<=9;j++) {
                if(map[i][j] == 0) {
                    idx = j;
                    cnt++;
                }
                sum += map[i][j];
            }
            if(cnt==1) {   
                int num = 45 - sum;
                map[i][idx] = num;
            }

            // 세로 채워넣기
            cnt = 0;
            sum = 0;
            for(int j=1;j<=9;j++) {
                if(map[j][i] == 0) {
                    idx = j;
                    cnt++;
                }
                sum+=map[j][i];
            }
            if(cnt==1) {
                int num = 45-sum;
                map[idx][i] = num;
            }
        }

        // 3 X 3 채워넣기
        for(int a=1;a<=3;a++) {
            for(int b=1;b<=3;b++) {
                int sum = 0;
                int cnt = 0;
                int idx,idy;
                for(int c=1;c<=3;c++) {
                    for(int d=1;d<=3;d++) {
                        sum += map[a*c][b*d];
                        if(map[a*c][b*d] == 0) {
                            cnt++;
                            idx = b*d;
                            idy = a*c;
                        }
                    }
                }
                if(cnt == 1) {
                    int num = 45 - sum;
                    map[idy][idx] = num;
                }
            }
        }
    }
    
    
}

int main () {
    input();
    solution();
}