#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 50;
int w,h;
int map[MAX][MAX];
bool isVisited[MAX][MAX];
int result = 0;


typedef struct {
    int y,x;
}Dir;

Dir makeDir[8] = {{1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {-1,-1}, {1,-1}, {-1,1}};

void dfs(int y, int x) {

    isVisited[y][x] = true;
    for(int i=0;i<8;i++) {
        int next_x = x + makeDir[i].x;
        int next_y = y + makeDir[i].y;
        // 다음 갈 곳 방문하지 않았고 값이 1이라면 가자.
        if(0 <= next_x && next_x < w && 0 <= next_y && next_y < h) {
            if(!isVisited[next_y][next_x] && map[next_y][next_x] == 1) {
                dfs(next_y, next_x);
            }
        }
        
    }
}

int main () {
    while(1) {
        cin >> w >> h;
        if(w==0 && h==0) break;

        // 결과변수 초기화
        result = 0;
        // 맵초기화
        memset(map, 0, sizeof(map));
        // 방문초기화
        memset(isVisited, false, sizeof(isVisited));
        

        for(int i=0;i<h;i++) {
            for(int j=0;j<w;j++) {
                cin >> map[i][j];
            }
        }

        for(int i=0;i<h;i++) {
            for(int j=0;j<w;j++) {
                if(!isVisited[i][j] && map[i][j] == 1) {
                    
                    dfs(i,j);
                    result++;
                }
            }
        }

        cout << result << endl;

        
    }

    return 0;
}