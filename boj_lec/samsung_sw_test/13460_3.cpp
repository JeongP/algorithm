#include <iostream>
#include <string>
#include <queue>
using namespace std;

typedef struct {
    int y,x;
}Dir;

typedef struct {
    int rx, ry, bx, by, sec;
}Ing;

int N, M;
string map[11];
int startRX,startRY,startBX,startBY;
queue<Ing> q;
Dir moveDir[4] = {{1,0}, {-1,0}, {0,1}, {0,-1}}; // 하, 상, 우, 좌

void input() {
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        cin >> map[i];
    }
}

void initialize() {
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(map[i][j] == 'R') 
            {
                startRX = j; startRY = i;
            }
            if(map[i][j] == 'B')
            {
                startBX = j; startBY = i;
            }
        }
    }
}

void move (int &xLoc,int &yLoc, int moveX, int moveY, int &cnt) {
    while(1) {
        int nx = xLoc + moveX;
        int ny = yLoc + moveY;
        // 다음 좌표가 갈 수 있는 곳이라면
        if(map[ny][nx] == '.' || map[ny][nx] == 'R' || map[ny][nx] == 'B') {
            xLoc += moveX;
            yLoc += moveY;
            cnt++;
        }else {
            return;
        }
    }
}



void sol () {
    q.push({startRX, startRY, startBX, startBY, 0});
    // int t = 1;
    while(1) {

        int cur_size = q.size();
        for(int i=0;i<cur_size;i++) {
            //
            int cur_rx = q.front().rx;
            int cur_ry = q.front().ry;
            int cur_bx = q.front().bx;
            int cur_by = q.front().by;
            int cur_sec = q.front().sec;
            q.pop();

            // cur_sec > 10 인 경우에 cout << -1 << endl;
            if(cur_sec > 10) {
                cout << -1 << endl;
                exit(0);
            }

            for(int i=0;i<4;i++) {
                // 이동할 방향 좌표
                int dirX = moveDir[i].x;
                int dirY = moveDir[i].y;

                int nextRX = cur_rx; int nextRY = cur_ry;
                int nextBX = cur_bx; int nextBY = cur_by;
                // 방향으로 이동한 칸수를 고려해줄 변수
                int rcnt = 0;
                int bcnt = 0;

                // red볼 이동 (.에 대해서만)
                move(nextRX,nextRY,dirX,dirY,rcnt);
                // cout << nextRY << " "  << nextRX << endl;
                
                // blue볼 이동 (.에 대해서만)
                move(nextBX,nextBY,dirX,dirY,bcnt);
                // cout << nextBY << " "  << nextBX << endl;

                // 다음 좌표가 구멍에 빠지는지 체크. 
                if(map[nextRY + dirY][nextRX + dirX] == 'O') {
                    // 블루볼도 같이 빠지면 -1
                    if(map[nextBY + dirY][nextBX + dirX] == 'O') {
                        cout << -1 << endl;
                        exit(0);
                    } else {
                        // 그렇지 않으면 걸린 시간 출력 후 종료.
                        cout << cur_sec+1 << endl;
                        exit(0);
                    }
                }
                // 겹치는 경우 체크
                if(nextRX == nextBX && nextRY == nextBY) {
                    if(rcnt>bcnt) {
                        nextRX -= dirX;
                        nextRY -= dirY;
                    } else {
                        nextBX -= dirX;
                        nextBY -= dirY;
                    }
                }
                // 이동한 점과 시간을 다시 큐에 넣기.
                q.push({nextRX,nextRY,nextBX,nextBY,cur_sec+1});
            }
        }
    }
}

int main () {
    input();
    initialize();
    sol();
}