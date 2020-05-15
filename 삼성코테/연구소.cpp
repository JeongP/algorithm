#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
int map[9][9] = {0,};
queue<pair<int,int>> virus;
int safetyArea = 0;
int dirX[4] = {0,0,1,-1};
int dirY[4] = {1,-1,0,0};
int copy_map[9][9] = {0,};

void input() {
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            int x; cin >> x;
            map[i][j] = x;
            if(x == 2) virus.push(make_pair(i,j));
        }
    }
}


void virusMove() {
    while(!virus.empty()) {
        int cur_qsize = virus.size();
        for(int i=0;i<cur_qsize;i++) {
            int y = virus.front().first;
            int x = virus.front().second;
            virus.pop();
            
            // 네 방향으로 이동
            for(int i=0;i<4;i++) {
                int ny = y + dirY[i];
                int nx = x + dirX[i];
                if(nx >=0 && nx < M && ny >= 0 && ny < N) {
                    if(map[ny][nx] == 0) {
                        map[ny][nx] = 2;
                        virus.push(make_pair(ny,nx));
                    }
                }
            }
        }
    }
    
}

int areaCount() {
    int cnt = 0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(map[i][j] == 0) cnt++;
        }
    }
    return cnt;
}

void prt() {
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

void copyMap() {
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            copy_map[i][j] = map[i][j];
        }
    }
}

void init() {
    // 맵초기화, 바이러스 push
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            map[i][j] = copy_map[i][j];
            if(map[i][j] == 2) {
                virus.push(make_pair(i,j));
            }
        }
    }
}

int c = 0;
void dfs(int cnt) {
    
    if(cnt == 3) {
        copyMap();
        virusMove();

        safetyArea = max(areaCount(), safetyArea);
        init();
        return;
    }
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(map[i][j] == 0) {
                map[i][j] = 1;
                dfs(cnt+1);
                map[i][j] = 0;
            }
        }
    }
}



int main () {
    input();
    dfs(0);
    cout << safetyArea << endl;
}
