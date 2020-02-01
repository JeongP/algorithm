#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 500;

typedef struct {
    int y,x;
}Dir;

Dir moveDir[4] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

int N,M;
int map[MAX][MAX];
bool visit[MAX][MAX];

int dfs(int y,int x, int depth) {
    if(depth == 3) return map[y][x];

    int sum = 0;

    for(int i=0;i<4;i++) {
        int nextX = x + moveDir[i].x;
        int nextY = y + moveDir[i].y;

        if(0 <= nextX && nextX < M && 0 <= nextY && nextY < N && !visit[nextY][nextX]) {
            visit[nextY][nextX] = true;
            sum = max(sum, map[y][x] + dfs(nextY, nextX, depth+1));
            visit[nextY][nextX] = false;
        }
    }

    return sum;
    
}

int middleFinger(int y, int x) {
    int result = 0;
    // 'ㅗ'
    if(0 <= y-1 && 0 <= x-1 && x+1 < M) {
        result = max(result, map[y][x] + map[y][x-1] + map[y-1][x] + map[y][x+1]);
    }
    // 'ㅏ'
    if(0 <= y-1 && y+1 < N && x+1 < M) {
        result = max(result, map[y][x] + map[y-1][x] + map[y+1][x] + map[y][x+1]);
    }
    // 'ㅓ'
    if(0 <= y-1 && y+1 < N && x-1 >= 0) {
        result = max(result, map[y][x] + map[y][x-1] + map[y-1][x] + map[y+1][x]);
    }
    // 'ㅜ'
    if(N > y+1 && 0 <= x-1 && x+1 < M) {
        result = max(result, map[y][x] + map[y][x-1] + map[y+1][x] + map[y][x+1]);
    }

    return result;
}


int main () {

    cin >> N >> M;

    // 맵 세팅
    for (int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> map[i][j];
        }
    }

    int result;
    // 모든점에서 깊이 3만큼 진행하고 합 구하기 by DFS
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            visit[i][j] = true;
            result = max(result,dfs(i,j,0));
            result = max(result, middleFinger(i,j));
            visit[i][j] = false;
        }
    }

    cout << result << endl;
}