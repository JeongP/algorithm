#include <iostream>
#include <string>
#include <queue>
#include <cmath>

using namespace std;

string tobni[4] = {"",};
bool eq[3] = {0,};
bool rot[4] = {0,};
int k;
queue<pair<int,int>> q;
int total = 0;

void input() {
    for(int i=0;i<4;i++) {
        cin >> tobni[i];
    }

    cin >> k;
    for(int i=0;i<k;i++) {
        int a, b;
        cin >> a >> b;
        q.push(make_pair(a,b));
    }
}

void check() {
    if(tobni[0][2] != tobni[1][6]) eq[0] = true;
    if(tobni[1][2] != tobni[2][6]) eq[1] = true;
    if(tobni[2][2] != tobni[3][6]) eq[2] = true;
}

void move(int idx, int dir) {
    if(dir == 1) {
        char tmp = tobni[idx][7];
        tobni[idx][7] = tobni[idx][6];
        tobni[idx][6] = tobni[idx][5];
        tobni[idx][5] = tobni[idx][4];
        tobni[idx][4] = tobni[idx][3];
        tobni[idx][3] = tobni[idx][2];
        tobni[idx][2] = tobni[idx][1];
        tobni[idx][1] = tobni[idx][0];
        tobni[idx][0] = tmp;
    } else {
        char tmp = tobni[idx][0];
        tobni[idx][0] = tobni[idx][1];
        tobni[idx][1] = tobni[idx][2];
        tobni[idx][2] = tobni[idx][3];
        tobni[idx][3] = tobni[idx][4];
        tobni[idx][4] = tobni[idx][5];
        tobni[idx][5] = tobni[idx][6];
        tobni[idx][6] = tobni[idx][7];
        tobni[idx][7] = tmp;
    }
}

void rotation(int idx, int dir) {
    
    move(idx, dir);

    // 범위 안에 있는경우 좌우로 가면서 조건에 맞으면 다들 회전.
    int left = idx-1;
    int left_dir = dir;
    int right = idx + 1;
    int right_dir = dir;
    while(left>=0) {
        // idx = 2;
        // 오른쪽 것이 회전했고, 맞닿은 부분이 다르다면.
        if(rot[left+1] && eq[left]) {
            rot[left] = true;
            left_dir = -left_dir;
            move(left,left_dir);
            left--;
        } else {
            break;
        }
    }
    
    while(right<4) {
        //right = 3; idx = 2;
        if(rot[right-1] && eq[right-1]) {
            rot[right] = true;
            right_dir = -right_dir;
            move(right, right_dir);
            right++;
        } else{
            break;
        }
    }
}

void initialize() {
    for(int i=0;i<4;i++) {
        rot[i] = false;
    }
    for(int i=0;i<3;i++) {
        eq[i] = false;
    }
}

void prt() {
    for(int i=0;i<4;i++) {
        cout << tobni[i] << endl;
    }
}

void sol() {
    while(!q.empty()) {
        // 큐에 있는 거 꺼내서 세팅
        int idx = q.front().first -1;
        int dir = q.front().second;
        q.pop();

        // 맞닿아 있는 부분 같은지 체크
        check();
        // 회전하기
        rot[idx] = true;
        rotation(idx, dir);
        // prt();
        // rot 값 초기화
        initialize();
       
    }

    // total 구하기
    for(int i=0;i<4;i++) {
        int top = tobni[i][0] -'0';
        // s극
        if(top == 1) {
            // cout << pow(2,i) << " ";
            total += pow(2,i);
        }
    }
}

int main () {
    input();
    sol();    
    cout << total << endl;
}