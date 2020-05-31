#include <iostream>
#include <vector>
using namespace std;

int N,M;
int map[9][9] = {0,};
int copyMap[9][9] = {0,};
int dirX[4] = {0,1,0,-1};
int dirY[4] = {-1,0,1,0};
vector<pair<int,int>> cctv;
int cdir[9] = {0,};
int area = 0;
int result = 65;
int gameCnt = 1;

void prt() {
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;

    }
}


void input() {
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> map[i][j];
            copyMap[i][j] = map[i][j];
            // cctv 좌표 넣어두기.
            if(map[i][j] == 1 || map[i][j] == 2 || map[i][j] == 3 || map[i][j] == 4 || map[i][j] == 5) {
                cctv.push_back(make_pair(i,j));
            }
        }
    }
}

void gamsi(int idx, int dir) {
    // cctv 번호, 방향 파악
    int y = cctv[idx].first;
    int x = cctv[idx].second;
    int cctvNum = map[y][x];

    
    if(cctvNum == 1) {
        int ny = y + dirY[dir];
        int nx = x + dirX[dir];
        while(1) {
            // 담 방향 벽이면 못감
            if(map[ny][nx] == 6 || ny < 0 || ny >= N || nx < 0 || nx >= M) break;
            // 갈 곳이 cctv 인 경우.
            else if (map[ny][nx] == 1 || map[ny][nx] == 2 || map[ny][nx] == 3 || map[ny][nx] == 4 || map[ny][nx] == 5) {
                ny += dirY[dir];
                nx += dirX[dir];
            }
            // 범위내에 있고 벽이 아니라면
            else {
                map[ny][nx] =7;
                ny += dirY[dir];
                nx += dirX[dir];
            }
        }
        
    } 

    else if (cctvNum == 2) {
        
        int ny = y + dirY[dir];
        int nx = x + dirX[dir];
        while(1) {
            
            if(map[ny][nx] == 6 || ny < 0 || ny >= N || nx < 0 || nx >= M) break;
            else if (map[ny][nx] == 1 || map[ny][nx] == 2 || map[ny][nx] == 3 || map[ny][nx] == 4 || map[ny][nx] == 5) {
                ny += dirY[dir];
                nx += dirX[dir];
            }
            else {
                map[ny][nx] = 7;
                ny += dirY[dir];
                nx += dirX[dir];
            }
        }

        ny = y - dirY[dir];
        nx = x - dirX[dir];

        while(1) {
            if(map[ny][nx] == 6 || ny < 0 || ny >= N || nx < 0 || nx >= M) break;
            else if (map[ny][nx] == 1 || map[ny][nx] == 2 || map[ny][nx] == 3 || map[ny][nx] == 4 || map[ny][nx] == 5) {
                ny -= dirY[dir];
                nx -= dirX[dir];
            }
            else {
                map[ny][nx] = 7;
                ny -=dirY[dir];
                nx -=dirX[dir];
            }
        }
    }

    else if (cctvNum == 3) {
        int ny = y + dirY[dir];
        int nx = x + dirX[dir];

        
        while(1) {
            if(map[ny][nx] == 6 || ny < 0 || ny >= N || nx < 0 || nx >= M) break;
            else if (map[ny][nx] == 1 || map[ny][nx] == 2 || map[ny][nx] == 3 || map[ny][nx] == 4 || map[ny][nx] == 5) {
                ny += dirY[dir];
                nx += dirX[dir];
            }
            else {
                map[ny][nx] = 7;
                ny += dirY[dir];
                nx += dirX[dir];
            }
        }
        
        if(dir == 3) dir = 0;
        else dir+=1;

        ny = y + dirY[dir];
        nx = x + dirX[dir];

        while(1) {
            if(map[ny][nx] == 6 || ny < 0 || ny >= N || nx < 0 || nx >= M) break;
            else if (map[ny][nx] == 1 || map[ny][nx] == 2 || map[ny][nx] == 3 || map[ny][nx] == 4 || map[ny][nx] == 5) {
                ny += dirY[dir];
                nx += dirX[dir];
            }
            else {
                map[ny][nx] = 7;
                ny += dirY[dir];
                nx += dirX[dir];
            }
        }
    } 
    
    else if (cctvNum == 4) {
        for(int i=0;i<4;i++) {
            if(i == (dir+2)%4) continue;
            int ny = y + dirY[i];
            int nx = x + dirX[i];
            while(1) {
                if(map[ny][nx] == 6 || ny < 0 || ny >= N || nx < 0 || nx >= M) break;
                else if (map[ny][nx] == 1 || map[ny][nx] == 2 || map[ny][nx] == 3 || map[ny][nx] == 4 || map[ny][nx] == 5) {
                    ny += dirY[i];
                    nx += dirX[i];
                }
                else {
                    map[ny][nx] = 7;
                    ny += dirY[i];
                    nx += dirX[i];
                }
            }
        }
    } 
    
    else {
        for(int i=0;i<4;i++) {
            int ny = y + dirY[i];
            int nx = x + dirX[i];
            while(1) {
                if(map[ny][nx] == 6 || ny < 0 || ny >= N || nx < 0 || nx >= M) break;
                else if (map[ny][nx] == 1 || map[ny][nx] == 2 || map[ny][nx] == 3 || map[ny][nx] == 4 || map[ny][nx] == 5) {
                    ny += dirY[i];
                    nx += dirX[i];
                }
                else {
                    map[ny][nx] = 7;
                    ny += dirY[i];
                    nx += dirX[i];
                }
            }
        }
    }

}

void goGame() {
    // 각 방향들을 돌면서 감시할 수 있는 곳들 check
    for(int i=0;i<cctv.size();i++) {
        gamsi(i,cdir[i]);
    }
}


void checkAnswer() {
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(map[i][j] == 0) area++;
        }
    }

    if(result > area) result = area;
}


void map_init () {
    // map init
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            map[i][j] = copyMap[i][j];
        }
    }

    // area init
    area = 0;
}

// 각 cctv의 방향 정하기
void setting(int idx) {
    if(idx == cctv.size()) {
        goGame();
        checkAnswer();
        // cout << "Game Cnt : " << gameCnt++ << endl;
        // cout << endl;
        // prt();
        // cout << endl << result;
        map_init();
        return;
    }

    for(int i=0;i<4;i++) {
        cdir[idx] = i;
        setting(idx+1);
    }
}


int main () {
    /* 
    cctv가 바라볼 방향을 정하고
    각 방향을 비교하고
    사각지대의 최소값 구하기.
    */
    input();
    // cctv 없다면.
    if(cctv.size() == 0) { 
        checkAnswer();
    } 
    else {
        setting(0);
    }
    cout << result << endl;

    // map[1][3] = -1;
}