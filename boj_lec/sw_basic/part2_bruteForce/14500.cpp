// 테트로미노

#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 500;

int N, M;
int map[MAX][MAX];
bool v[MAX][MAX];

typedef struct {
    int x,y;
}Dot;

Dot moveDir[4] = {{0,-1}, {0,1}, {-1,0}, {1,0}};

int dfs(int x,int y, int depth) {
    if(depth == 3) return map[y][x];
    int sum = 0;

    for(int i=0; i<4;i ++) {
        int nx = x + moveDir[i].x;
        int ny = y + moveDir[i].y;

        if(0 <= nx && nx < M && 0 <= ny && ny < N && !v[ny][nx]) {
            v[ny][nx] = true;
            sum = max(sum, map[y][x] + dfs(nx,ny,depth+1));
            v[ny][nx] = false;
        }
    }
    return sum;
}

int main () {
    
    cin >> N >> M;
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> map[i][j];
        }
    }

    int result = 0;

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            v[i][j] = true;
            result = max(result, dfs(j,i,0));
            v[i][j] = false;
        }
    }

    cout << result << endl;    
}