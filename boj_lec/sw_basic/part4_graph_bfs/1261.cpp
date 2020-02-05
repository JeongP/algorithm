#include <iostream>
#include <vector>

using namespace std;

#define MAX 100
#define INF 987654321

int n,m;
int map[MAX][MAX];
int map_crush_cnt[MAX][MAX];
int isVisited[MAX][MAX] = {0,};

int side[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

void dfs(int depth, int row, int col, int crashed_num) {

    if(map_crush_cnt[row][col] <= crashed_num) return;
    else map_crush_cnt[row][col] = crashed_num;

    if(row == n-1 && col == m-1) return;

    for(int i=0;i<4;i++) {
        int nrow = row + side[i][0];
        int ncol = col + side[i][1];
        if(0<=nrow && nrow < n && 0<= ncol && ncol < m && !isVisited[nrow][ncol]) {
            isVisited[nrow][ncol] = 1;
            dfs(depth+1, nrow, ncol, crashed_num + (map[nrow][ncol] ? 1:0));
            isVisited[nrow][ncol] = 0;
        }
    }
}


int main () {
    cin >> n >> m;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> map[i][j];
            map_crush_cnt[i][j] = INF;
        }
    }

    isVisited[0][0] = 1;
    dfs(0,0,0,0);

    cout << map_crush_cnt[n-1][m-1];
    return 0;
}