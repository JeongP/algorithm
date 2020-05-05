#include <iostream>
#include <string>
#include <vector>
using namespace std;

int T;
int n;

vector<pair<char,char>> v;
vector<char> Cube[7];

void init() {
    v.clear();
    // 큐브 초기화
    for(int i=1;i<7;i++) {
        Cube[i].clear();
    }
    for(int i=0;i<9;i++) {
        // 1 = 윗면, 2 = 아랫면, 3 = 앞면, 4 = 뒷면, 5 = 왼쪽, 6 = 오른쪽
        Cube[1].push_back('w');
        Cube[2].push_back('y');
        Cube[3].push_back('r');
        Cube[4].push_back('o');
        Cube[5].push_back('g');
        Cube[6].push_back('b');
    }
}


void input() {
    cin >> n;
    for(int i=0;i<n;i++) {
        string s;
        cin >> s;
        v.push_back(make_pair(s[0],s[1]));
    }
    // for(int i=0;i<n;i++) {
    //     cout << v[i].first << " " << v[i].second;
    // }
}

int selectPhase(char where) {
    if(where == 'U') return 1;
    else if(where == 'D') return 2;
    else if(where == 'F') return 3;
    else if(where == 'B') return 4;
    else if(where == 'L') return 5;
    else if(where == 'R') return 6;
}

void moveMain(char where, char dir) {
    int phase = selectPhase(where);
    if(dir == '+') {
        char tmp = Cube[phase][0];
        Cube[phase][0] = Cube[phase][6];
        Cube[phase][6] = Cube[phase][8];
        Cube[phase][8] = Cube[phase][2];
        Cube[phase][2] = tmp;
        
        tmp = Cube[phase][1];
        Cube[phase][1] = Cube[phase][3];
        Cube[phase][3] = Cube[phase][7];
        Cube[phase][7] = Cube[phase][5];
        Cube[phase][5] = tmp;
    } else if (dir == '-') {
        char tmp = Cube[phase][0];
        Cube[phase][0] = Cube[phase][2];
        Cube[phase][2] = Cube[phase][8];
        Cube[phase][8] = Cube[phase][6];
        Cube[phase][6] = tmp;
        
        tmp = Cube[phase][1];
        Cube[phase][1] = Cube[phase][5];
        Cube[phase][5] = Cube[phase][7];
        Cube[phase][7] = Cube[phase][3];
        Cube[phase][3] = tmp;
    }
}

void sol() {
    for(int i=0;i<v.size();i++) {
        char where = v[i].first;
        char dir = v[i].second;
        // 1 = 윗면, 2 = 아랫면, 3 = 앞면, 4 = 뒷면, 5 = 왼쪽, 6 = 오른쪽
        if(where == 'U') {
            if(dir == '+') {
                // 붙어있는 4면 바꾸기
                char tmp1 = Cube[3][0];
                char tmp2 = Cube[3][1];
                char tmp3 = Cube[3][2];

                Cube[3][0] = Cube[6][0];
                Cube[3][1] = Cube[6][1];
                Cube[3][2] = Cube[6][2];

                Cube[6][0] = Cube[4][0];
                Cube[6][1] = Cube[4][1];
                Cube[6][2] = Cube[4][2];

                Cube[4][0] = Cube[5][0];
                Cube[4][1] = Cube[5][1];
                Cube[4][2] = Cube[5][2];

                Cube[5][0] = tmp1;
                Cube[5][1] = tmp2;
                Cube[5][2] = tmp3;

            } else if(dir == '-'){
                char tmp1 = Cube[3][0];
                char tmp2 = Cube[3][1];
                char tmp3 = Cube[3][2];

                Cube[3][0] = Cube[5][0];
                Cube[3][1] = Cube[5][1];
                Cube[3][2] = Cube[5][2];

                Cube[5][0] = Cube[4][0];
                Cube[5][1] = Cube[4][1];
                Cube[5][2] = Cube[4][2];

                Cube[4][0] = Cube[6][0];
                Cube[4][1] = Cube[6][1];
                Cube[4][2] = Cube[6][2];

                Cube[6][0] = tmp1;
                Cube[6][1] = tmp2;
                Cube[6][2] = tmp3;

            }
        }
        else if(where == 'D') {
            if(dir == '+') {
                // 붙어있는 4면 바꾸기
                char tmp1 = Cube[3][6];
                char tmp2 = Cube[3][7];
                char tmp3 = Cube[3][8];

                Cube[3][6] = Cube[5][6];
                Cube[3][7] = Cube[5][7];
                Cube[3][8] = Cube[5][8];

                Cube[5][6] = Cube[4][6];
                Cube[5][7] = Cube[4][7];
                Cube[5][8] = Cube[4][8];

                Cube[4][6] = Cube[6][6];
                Cube[4][7] = Cube[6][7];
                Cube[4][8] = Cube[6][8];

                Cube[6][6] = tmp1;
                Cube[6][7] = tmp2;
                Cube[6][8] = tmp3;

            } else if(dir == '-'){
                // 붙어있는 4면 바꾸기
                char tmp1 = Cube[3][6];
                char tmp2 = Cube[3][7];
                char tmp3 = Cube[3][8];

                Cube[3][6] = Cube[6][6];
                Cube[3][7] = Cube[6][7];
                Cube[3][8] = Cube[6][8];

                Cube[6][6] = Cube[4][6];
                Cube[6][7] = Cube[4][7];
                Cube[6][8] = Cube[4][8];

                Cube[4][6] = Cube[5][6];
                Cube[4][7] = Cube[5][7];
                Cube[4][8] = Cube[5][8];

                Cube[5][6] = tmp1;
                Cube[5][7] = tmp2;
                Cube[5][8] = tmp3;
            }
        }
        else if(where == 'F') {
            if(dir == '+') {
                // 붙어있는 4면 바꾸기
                char tmp1 = Cube[1][6];
                char tmp2 = Cube[1][7];
                char tmp3 = Cube[1][8];

                Cube[1][6] = Cube[5][8];
                Cube[1][7] = Cube[5][5];
                Cube[1][8] = Cube[5][2];

                Cube[5][2] = Cube[2][0];
                Cube[5][5] = Cube[2][1];
                Cube[5][8] = Cube[2][2];

                Cube[2][0] = Cube[4][6];
                Cube[2][1] = Cube[4][3];
                Cube[2][2] = Cube[4][0];

                Cube[4][0] = tmp1;
                Cube[4][3] = tmp2;
                Cube[4][6] = tmp3;

            } else if(dir == '-'){
                // 붙어있는 4면 바꾸기
                char tmp1 = Cube[1][6];
                char tmp2 = Cube[1][7];
                char tmp3 = Cube[1][8];

                Cube[1][6] = Cube[4][0];
                Cube[1][7] = Cube[4][3];
                Cube[1][8] = Cube[4][6];

                Cube[4][0] = Cube[2][2];
                Cube[4][3] = Cube[2][1];
                Cube[4][6] = Cube[2][0];

                Cube[2][0] = Cube[5][2];
                Cube[2][1] = Cube[5][5];
                Cube[2][2] = Cube[5][8];

                Cube[5][2] = tmp3;
                Cube[5][5] = tmp2;
                Cube[5][8] = tmp1;
            }
        }
        else if(where == 'B') {
            if(dir == '+') {
                // 붙어있는 4면 바꾸기
                char tmp1 = Cube[1][0];
                char tmp2 = Cube[1][1];
                char tmp3 = Cube[1][2];

                Cube[1][0] = Cube[6][2];
                Cube[1][1] = Cube[6][5];
                Cube[1][2] = Cube[6][8];

                Cube[6][2] = Cube[2][8];
                Cube[6][5] = Cube[2][7];
                Cube[6][8] = Cube[2][6];

                Cube[2][8] = Cube[5][6];
                Cube[2][7] = Cube[5][3];
                Cube[2][6] = Cube[5][0];

                Cube[5][6] = tmp1;
                Cube[5][3] = tmp2;
                Cube[5][0] = tmp3;

            } else if(dir == '-'){
                // 붙어있는 4면 바꾸기
                char tmp1 = Cube[1][0];
                char tmp2 = Cube[1][1];
                char tmp3 = Cube[1][2];

                Cube[1][0] = Cube[5][6];
                Cube[1][1] = Cube[5][3];
                Cube[1][2] = Cube[5][0];

                Cube[5][0] = Cube[2][6];
                Cube[5][3] = Cube[2][7];
                Cube[5][6] = Cube[2][8];

                Cube[2][6] = Cube[6][8];
                Cube[2][7] = Cube[6][5];
                Cube[2][8] = Cube[6][2];

                Cube[6][8] = tmp3;
                Cube[6][5] = tmp2;
                Cube[6][2] = tmp1;
            }
        }
        else if(where == 'L') {
            if(dir == '+') {
                // 붙어있는 4면 바꾸기
                char tmp1 = Cube[1][0];
                char tmp2 = Cube[1][3];
                char tmp3 = Cube[1][6];

                Cube[1][0] = Cube[4][8];
                Cube[1][3] = Cube[4][5];
                Cube[1][6] = Cube[4][2];

                Cube[4][2] = Cube[2][6];
                Cube[4][5] = Cube[2][3];
                Cube[4][8] = Cube[2][0];

                Cube[2][6] = Cube[3][6];
                Cube[2][3] = Cube[3][3];
                Cube[2][0] = Cube[3][0];

                Cube[3][0] = tmp1;
                Cube[3][3] = tmp2;
                Cube[3][6] = tmp3;

            } else if(dir == '-'){
                char tmp1 = Cube[1][0];
                char tmp2 = Cube[1][3];
                char tmp3 = Cube[1][6];

                Cube[1][0] = Cube[3][0];
                Cube[1][3] = Cube[3][3];
                Cube[1][6] = Cube[3][6];

                Cube[3][0] = Cube[2][0];
                Cube[3][3] = Cube[2][3];
                Cube[3][6] = Cube[2][6];

                Cube[2][0] = Cube[4][8];
                Cube[2][3] = Cube[4][5];
                Cube[2][6] = Cube[4][2];

                Cube[4][8] = tmp1;
                Cube[4][5] = tmp2;
                Cube[4][2] = tmp3;
            }
        }
        else if(where == 'R') {
            if(dir == '+') {
                // 붙어있는 4면 바꾸기
                char tmp1 = Cube[1][2];
                char tmp2 = Cube[1][5];
                char tmp3 = Cube[1][8];

                Cube[1][2] = Cube[3][2];
                Cube[1][5] = Cube[3][5];
                Cube[1][8] = Cube[3][8];

                Cube[3][2] = Cube[2][2];
                Cube[3][5] = Cube[2][5];
                Cube[3][8] = Cube[2][8];

                Cube[2][2] = Cube[4][6];
                Cube[2][5] = Cube[4][3];
                Cube[2][8] = Cube[4][0];

                Cube[4][6] = tmp1;
                Cube[4][3] = tmp2;
                Cube[4][3] = tmp3;

            } else if(dir == '-'){
                // 붙어있는 4면 바꾸기
                char tmp1 = Cube[1][2];
                char tmp2 = Cube[1][5];
                char tmp3 = Cube[1][8];

                Cube[1][2] = Cube[4][6];
                Cube[1][5] = Cube[4][3];
                Cube[1][8] = Cube[4][0];

                Cube[4][6] = Cube[2][2];
                Cube[4][3] = Cube[2][5];
                Cube[4][0] = Cube[2][8];

                Cube[2][2] = Cube[3][2];
                Cube[2][5] = Cube[3][5];
                Cube[2][8] = Cube[3][8];

                Cube[3][2] = tmp1;
                Cube[3][5] = tmp2;
                Cube[3][8] = tmp3;
            }
        }
        
        moveMain(where, dir);
    }
}

void prt() {
    int cnt = 1;
    for(int i=0;i<9;i++) {
        cout << Cube[1][i];
        if(cnt == 3) {
            cout << endl;
            cnt = 0;
        }
        cnt++;
    }
}

int main () {
    cin >> T;

    while(T--) {
        init();
        input();
        sol();
        prt();
        
    }
}
