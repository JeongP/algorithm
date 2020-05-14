#include <iostream>
using namespace std;
int N, M, x,y,K;
int dice[7] = {0,}; // 앞 뒤 좌 우 상 하
int map[21][21] = {0,};
int orders[1001] = {0,};
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
int cnt = 1;
void input() {
    cin >> N >> M >> x >> y >> K;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            int x;
            cin >> x;
            map[i][j] = x;
        }
    }

    for(int i=0;i<K;i++) {
        int x;
        cin >> x;
        orders[i] = x;
    }
}

void move(int dir) {
    x = x + dx[dir-1];
    y = y + dy[dir-1];

    // 해당 명령이 바깥으로 이동하게 되면
    if(x < 0 || x >= N || y < 0 || y >= M) {
        x -= dx[dir-1];
        y -= dy[dir-1];
        return;
    }
    
    // 이동할 칸에 쓰여있는 수가 0인지
    if(map[x][y] == 0 ) {
        int tmp;
        switch(dir) {
            case 1:
                map[x][y] = dice[4];
                tmp = dice[4];
                dice[4] = dice[5];
                dice[5] = dice[3];
                dice[3] = dice[6];
                dice[6] = tmp;
                break;
            case 2:
                map[x][y] = dice[3];
                tmp = dice[3];
                dice[3] = dice[5];
                dice[5] = dice[4];
                dice[4] = dice[6];
                dice[6] = tmp;
                break;
            case 3:
                map[x][y] = dice[2];
                tmp = dice[2];
                dice[2] = dice[5];
                dice[5] = dice[1];
                dice[1] = dice[6];
                dice[6] = tmp;
                break;
            case 4:
                map[x][y] = dice[1];
                tmp = dice[1];
                dice[1] = dice[5];
                dice[5] = dice[2];
                dice[2] = dice[6];
                dice[6] = tmp;
                break;
        }
    } else {
        int tmp;
        switch(dir) {
            case 1:
                dice[4] = map[x][y];
                map[x][y] = 0;
                tmp = dice[4];
                dice[4] = dice[5];
                dice[5] = dice[3];
                dice[3] = dice[6];
                dice[6] = tmp;
                break;
            case 2:
                dice[3] = map[x][y];
                map[x][y] = 0;
                tmp = dice[3];
                dice[3] = dice[5];
                dice[5] = dice[4];
                dice[4] = dice[6];
                dice[6] = tmp;
                break;
            case 3:
                dice[2] = map[x][y];
                map[x][y] = 0;
                tmp = dice[2];
                dice[2] = dice[5];
                dice[5] = dice[1];
                dice[1] = dice[6];
                dice[6] = tmp;
                break;
            case 4:
                dice[1] = map[x][y];
                map[x][y] = 0;
                tmp = dice[1];
                dice[1] = dice[5];
                dice[5] = dice[2];
                dice[2] = dice[6];
                dice[6] = tmp;
                break;
        }
    }
    cout << dice[5] << endl;
}

void sol() {
    for(int i=0;i<K;i++) {
        int dir = orders[i];
        move(dir);
    }
}

int main () {
    input();
    sol();
}
