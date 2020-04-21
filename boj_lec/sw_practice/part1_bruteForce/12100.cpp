#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
    int y,x;
}Dir;

int n;
int map[21][21];
int copyMap[21][21];
int answer = 0;
Dir moveDir[4] = {{0,-1}, {0,1}, {1,0}, {-1,0}};

void input() {
    cin >> n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> map[i][j];
        }
    }
}


int sol() {

    for(int i=0;i<4;i++) {
        int nx = moveDir[i].x;
        int ny = moveDir[i].y;
        move(nx,ny);
    }
}

int main () {
    input();
    cout << sol() << endl;
}