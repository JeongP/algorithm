#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int MAX = 1000;

typedef struct {
    int y,x;
}Dir;

Dir moveDir[4] =  { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int N,M;
int map[MAX][MAX];
int cache[MAX][MAX][2]; // 뒤의 2는 벽 뚫기 가능 여부 1(가능) 0(불가능).


int BFS() {
    queue<pair<pair<int,int>,int>> q;
    q.push(make_pair(make_pair(0,0),1));
    cache[0][0][1] = 1;

    while(!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int block = q.front().second;
        q.pop();

        if(y==N-1 && x == M-1) {
            return cache[y][x][block];
        }

        for(int i=0;i<4;i++) {
            int ny = y + moveDir[i].y;
            int nx = x + moveDir[i].x;

            if(0<=ny && ny < N && 0<=nx && nx < M) {
                // 벽이 있고 아직 한 번도 안 뚫었다면
                if(map[ny][nx] == 1 && block) {
                    cache[ny][nx][block-1] = cache[y][x][block]+1;
                    q.push(make_pair(make_pair(ny,nx),block-1));
                }
                // 벽이 없고 방문하지 않았던 곳이라면
                else if(map[ny][nx] == 0 && cache[ny][nx][block]==0) {
                    cache[ny][nx][block] = cache[y][x][block]+1;
                    q.push(make_pair(make_pair(ny,nx),block));
                }
            
            }
        }
    }
    return -1;
}


int main () {
    
    cin >> N >> M;
    
    for(int i =0; i<N;i++) {
        string s;
        cin >> s;

        for(int j=0;j<M;j++) {
            map[i][j] = s[j] - '0';
        }
    }

    cout << BFS() << endl;
    return 0;
}