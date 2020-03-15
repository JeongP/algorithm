#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100+1;
int n;
int map[MAX][MAX];
int result[MAX][MAX];
queue<pair<int,int>> q;

void input () {
    cin >> n;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            cin >> map[i][j];
        }
    }
}

void sol() {
    q.push(make_pair(1,1));
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        int move = map[y][x];
        // cout << y << " " << x << endl;
        // cout << move << endl;
        q.pop();

        if(x==n && y==n) {
            continue;
        }
        
        // 오른쪽으로 이동
        if(x+move <= n) {
            result[y][x+move]++;
            q.push(make_pair(y,x+move));
        }

        // 아래로 이동
        if(y+move <= n) {
            result[y+move][x]++;
            q.push(make_pair(y+move,x));
        }

        

    }
    cout << result[n][n] << endl;
}

int main () {
    input();
    sol();
}