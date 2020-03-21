#include <iostream>

using namespace std;

const int MAX = 9;
int map[MAX][MAX];
bool col[MAX][MAX]; // col[i][j]: i번째 행에 j라는 수가 들어있는지..
bool row[MAX][MAX];
bool square[MAX][MAX];

void input() {
    for(int i=0;i<MAX;i++) {
        for(int j=0;j<MAX;j++) {
            cin >> map[i][j];
            if(map[i][j]) {
                col[i][map[i][j]] = true;
                row[j][map[i][j]] = true;
                square[(i/3)*3 + (j/3)][map[i][j]] = true;
            }

        }
    }
}

void prt() {
    for(int i=0;i<MAX;i++) {
        for(int j=0;j<MAX;j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

void dfs(int depth) {

    if(depth == 81) {
        prt();
        exit(0);
    }

    int x = depth % 9;
    int y = depth / 9;
    
    if(!map[y][x]) {
        for(int k=1;k<=9;k++) {
            if(!col[y][k] && !row[x][k] && !square[(y/3)*3 + (x/3)][k]) {
                col[y][k] = true;
                row[x][k] = true;
                square[(y/3)*3 + (x/3)][k]= true;
                map[y][x] = k;
                dfs(depth+1);
                map[y][x] = 0;
                col[y][k] = false;
                row[x][k] = false;
                square[(y/3)*3 + (x/3)][k] = false;
            }
        }
        
    }else {
        dfs(depth+1);
    }

}


void sol() {
    dfs(0);
}

int main () {
    input();
    sol();
}