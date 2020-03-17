/*

    1. 첫 번째 점 벡터에 넣고, 갈 수 있는 모든 곳 방문처리.
    2. 방문하지 않은 부분을 돌면서 DFS처리.
    3. 더 이상 갈 수 있는 곳이 없으면 cnt++

 */

#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 15+1;
int N;
int map[MAX][MAX];
bool visit[MAX][MAX];
int answer = 0;

void move(int y,int x) {
    // 상하좌우 방문처리.
    for(int i=1;i<=N;i++) {
        if(!visit[y][i]) {
            visit[y][i] = true;
        }
        if(!visit[i][x]) {
            visit[i][x] = true;
        }
    }

    int nx = x; int ny = y;
    // 오른쪽 위
    while(1) {
        nx = nx+1; ny = ny-1;
        if(nx > N || ny < 1) break;
        if(!visit[ny][nx]) {
            visit[ny][nx] = true;
        }
    }
    nx = x; ny = y;
    // 오른쪽 아래.
    while(1) {
        nx = nx+1; ny = ny+1;
        if(nx > N || ny > N) break;
        if(!visit[ny][nx]) {
            visit[ny][nx] = true;
        }
    }

    nx = x; ny = y;
    // 왼쪽 위
    while(1) {
        nx = nx-1; ny = ny-1;
        if(nx < 1 || ny < 1) break;
        if(!visit[ny][nx]) {
            visit[ny][nx] = true;
        }
    }

    nx = x; ny = y;
    // 왼쪽 아래
    while(1) {
        nx = nx-1; ny = ny+1;
        if(ny > N || nx < 1) break;
        if(!visit[ny][nx]) {
            visit[ny][nx] = true;
        }
    }

}

bool endCheck() {
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            if(!visit[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void dfs() {

    if(endCheck()) {
       answer++; 
       return;
    }

    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            if(!visit[i][j]) {
                visit[i][j] = true;
                move(i,j);
                dfs();
                visit[i][j] = false;
            }
        }
    }
}

void sol () {
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            visit[i][j] = true;
            move(i,j);
            dfs();
            memset(visit,false,sizeof(visit));
        }
    }
    cout << answer << endl;
}

int main () {
    cin >> N;
    sol();    
}