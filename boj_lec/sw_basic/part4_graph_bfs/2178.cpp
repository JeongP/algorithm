#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 100;
int n,m;
string s[MAX];
bool isVisited[MAX][MAX];
int result = 10000;

typedef struct {
    int y,x;
}Dir;

Dir makeDir[4] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

void input() {
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        cin >> s[i];
    }

}

void dfs(int y,int x, int sum) {
    
    if(y==n-1 && x == m-1) {
        result = min(sum, result);
        
    }

    for(int i=0;i<4;i++) {
        int nx = x + makeDir[i].x;
        int ny = y + makeDir[i].y;
        if(0 <= nx && nx < m && 0 <= ny && ny < n) {
            if(!isVisited[ny][nx] && s[ny][nx] == '1') {
                isVisited[ny][nx] = true;
                dfs(ny,nx,sum+1);
                isVisited[ny][nx] = false;
            }
        }
    }

}

int main () {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    
    input();
    isVisited[0][0] = true;
    dfs(0,0,1);
    cout << result << endl;
}