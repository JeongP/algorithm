#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 25;
int n;
string map[MAX];
int house_cnt;
vector<int> residence;
bool isVisited[MAX][MAX];

typedef struct {
    int y,x;
}Dir;

Dir makeDir[4] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

void input() {
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> map[i];
    }
}


void dfs(int y, int x) {

    house_cnt++;
    isVisited[y][x] = true;
    for(int i=0;i<4;i++) {
        int next_x = x + makeDir[i].x;
        int next_y = y + makeDir[i].y;
        // 다음 갈 곳 방문하지 않았고 값이 1이라면 가자.
        if(0 <= next_x && next_x < n && 0 <= next_y && next_y < n) {
            if(!isVisited[next_y][next_x] && map[next_y][next_x] == '1') {
                dfs(next_y, next_x);
            }
        }
        
    }
}

void prt_result() {
    cout << residence.size() << endl;
    sort(residence.begin(),residence.end());
    for(int i=0;i<residence.size();i++) {
        cout << residence[i] << endl;
    }
}


int main () {
    input();
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(!isVisited[i][j] && map[i][j] == '1') {
                house_cnt = 0;
                dfs(i,j);
                residence.push_back(house_cnt);
            }
        }
    }
    prt_result();
}