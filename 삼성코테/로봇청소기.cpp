#include <iostream>

using namespace std;

int dirX[4] = {0,1,0,-1};
int dirY[4] = {-1,0,1,0};

int N,M,x,y,d;
int map[51][51];
int result = 0;

void input() {
    cin >> N >> M;
    cin >> y >> x >> d;

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            int a;
            cin >> a;
            map[i][j] = a;
            
        }
    }
}


void working() {
    // 현재 위치 청소
    map[y][x] = 2;
    result++;
    int cur_dir = d;

    int cnt = 0; // 네 방향 청소 여부.

    // 동작 안 할때까지
    while(1) {
        int movingDir;

        // 왼쪽 방향 정하기
        if(cur_dir == 0) {
            movingDir = cur_dir + 3;
        }else {
            movingDir = cur_dir - 1;
        }

        int nx = x + dirX[movingDir];
        int ny = y + dirY[movingDir];
        // 네 방향 청소 여부 변수
        
        // 청소 가능.
        if(map[ny][nx] == 0) {
            cur_dir = movingDir;
            y = ny; x = nx; 
            map[ny][nx] = 2;
            cnt = 0;
            result++;
        } else if(map[ny][nx] != 0 && cnt != 4) {
            cur_dir = movingDir;
            cnt++;
        } else if(map[ny][nx] != 0 && cnt == 4) {
            movingDir = (cur_dir < 2) ? cur_dir+2 : cur_dir-2;
            
            nx = x + dirX[movingDir];
            ny = y + dirY[movingDir];
            // 후진 가능
            if(map[ny][nx] == 2) {
                x = nx; y = ny;
                cnt = 0;
            }
            // 불가능
            else {
                return;
            }
        }
    }
}

int main () {
    input();
    working();
    cout << result << endl;
}