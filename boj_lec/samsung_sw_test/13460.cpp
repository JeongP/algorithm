#include <iostream>
#include <string>
using namespace std;

const int MAX = 11;
int N,M;
string map[MAX];
int rx, ry, bx, by, gx, gy;
int rmoveCnt, bmoveCnt;

typedef struct {
    int y,x;
}Dir;

Dir moveDir[4] = {{0,-1}, {0,1}, {-1,0}, {1,0}};



void input() {
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        cin >> map[i];
    }
}

void initialize() {
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            if(map[i][j] == 'R') 
            {
                rx = j; ry = i;
            }
            if(map[i][j] == 'B')
            {
                bx = j; by = i;
            }
            if(map[i][j] == '0')
            {
                gx = j; gy = i;
            }
        }
    }
}

void move(int &nx, int &ny, int &moveCnt, int x, int y) {
    moveCnt = 0;
    while(1) {
        if(map[ny][nx] == '.') {
            nx += x;
            ny += y;
            moveCnt++;
        } else {
            return;
        }
    }
}


void dfs(int rx, int ry, int bx, int by, int cnt) {

    if(cnt>=10) cout << -1 << endl;
    if(rx == gx && ry == gy) {
        cout << cnt << endl;
    }
    
    for(int i=0;i<4;i++) {
        int nrx = rx + moveDir[i].x;
        int nry = ry + moveDir[i].y;
        int nbx = bx + moveDir[i].x;
        int nby = by + moveDir[i].y;

        // 갈 수 있는 만큼 계속 이동.
        move(nrx, nry, rmoveCnt, moveDir[i].x, moveDir[i].y);
        move(nbx, nby, bmoveCnt, moveDir[i].x, moveDir[i].y);
        
        
        // 겹치는 거 고려
        if(nrx == nbx && nry == nby) {
            if(bmoveCnt > rmoveCnt) {
                nbx -= moveDir[i].x;
                nby -= moveDir[i].y;
            }else {
                nrx -= moveDir[i].x;
                nry -= moveDir[i].y;
            }
        }
        dfs(nrx,nry,nbx,nby,cnt+1);
    }
}

void sol() {
    dfs(rx, ry, bx, by, 0);
}


void prt() {
    for(int i=0;i<N;i++) {
        cout << map[i][1] << endl;
    }
}

int main () {
    input();
    initialize();
    sol();
    // prt();

}