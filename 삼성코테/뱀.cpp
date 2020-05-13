#include <iostream>
#include <queue>
using namespace std;

int N,K,L;
int map[101][101];
queue<pair<int, char>> moveInfo;
int sec = 0;
bool firstFlag = true;
int startX = 1;
int startY = 1;
int directions[4][2] = {{-1,0}, {1,0}, {0,1}, {0,-1}}; // 상 하 좌 우
int nextDirIdx;

void input () {
    cin >> N;
    // map setting
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            // 땅은 0
            map[i][j] = 0;
        }
    }
    cin >> K;
    int x,y;
    for(int i=0; i<K; i++) {
        cin >> y >> x;
        // 사과는 1
        map[y][x] = 1;
    }

    // 뱀은 2
    map[1][1] = 2;

    cin >> L;
    int a; char b;
    for(int i=0;i<L;i++) {
        cin >> a >> b;
        moveInfo.push(make_pair(a,b));
    }
}

void move(int cnt, char dir) {
    // 처음의 경우
    if(firstFlag) {
        int dirX = directions[2][1];
        int dirY = directions[2][0];
        int nx = startX;
        int ny = startY;

        // cnt 만큼 move
        while(cnt--) {
            nx += dirX;
            ny += dirY;
            if(nx>=1 && nx <=N) {
                if(map[ny][nx] == 1) {
                    sec++;
                    map[ny][nx] = 2;
                } else if(map[ny][nx] == 0) {
                    sec++;
                    map[ny][nx] = 2;
                    map[ny][startX] = 0;
                    startX++;
                }
            }
        }

        // 방향정하기
        if(dir == 'L') {
            sec++;
            cout << sec << endl;
            exit(0);
        }else {
            nextDirIdx = 1;
        }
        firstFlag = false;
        
    } 
    else 
    {
        int dirX = directions[nextDirIdx][1];
        int dirY = directions[nextDirIdx][0];
        int nx = startX;
        int ny = startY;
        while(cnt--) {
            nx += dirX;
            ny += dirY;
            if(nx>=1 && nx <=N && ny >= 1 && ny <= N) {
                if(map[ny][nx] == 0) {
                    sec++;
                    map[ny][nx] = 2;
                    map[startY][startX] = 0;
                    startX += dirX;
                    startY += dirY;
                }else if(map[ny][nx] == 1) {
                    sec++;
                    map[ny][nx] = 2;
                }else if(map[ny][nx] == 2) {
                    sec++;
                    cout << sec << endl;
                    exit(0);
                }
            } else {
                // 해당범위 밖, 즉 벽 만났을때 시간 더해주고 끝내기.
                sec++;
                cout << sec << endl;
                exit(0);
            }
        }

        // 방향정하기
        if(dir == 'L') {
            if(nextDirIdx == 0) {
                nextDirIdx = 3;
            } else if(nextDirIdx == 1) {
                nextDirIdx = 2;
            }else if(nextDirIdx == 2) {
                nextDirIdx = 1;
            }else if(nextDirIdx == 3) {
                nextDirIdx = 0;
            }
        }else {
            if(nextDirIdx == 0) {
                nextDirIdx = 2;
            } else if(nextDirIdx == 1) {
                nextDirIdx = 3;
            }else if(nextDirIdx == 2) {
                nextDirIdx = 0;
            }else if(nextDirIdx == 3) {
                nextDirIdx = 1;
            }
        }
    }
    

}

void playGame() {

    while(!moveInfo.empty()) {
        int moveCnt = moveInfo.front().first;
        char dir = moveInfo.front().second;
        moveInfo.pop();
        move(moveCnt,dir);
    }
}

int main () {
    input();
    playGame();
    // cout << sec << endl;
}