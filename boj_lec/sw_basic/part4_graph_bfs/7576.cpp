#include <iostream>
#include <queue>

using namespace std;

const int MAX = 1001;
int m,n;
int map[MAX][MAX];
int result = 0;
bool isVisited[MAX][MAX];
queue<pair<int, int>> q;
int noTomato = 0;


typedef struct {
    int x, y;
}Dir;

Dir moveDir[4] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

void input() {
    cin >> m >> n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin >> map[i][j];
            if(map[i][j] == -1) noTomato++;
            if(map[i][j] == 1) q.push(pair<int,int>(i,j));
        }
    }

}

bool check() {
    if(m*n - q.size() == noTomato) return 1;
    else return 0;
}

bool theEnd() {
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(map[i][j] == 0) return 0;
        }
    }
    return 1;
}

void sol() {
    
    while(!q.empty()) {

        int current_q_size = q.size();

        for(int x=0;x<current_q_size;x++) {
            pair<int,int> a = q.front();
            q.pop();
            
            for(int i=0;i<4;i++) {
                int ny = a.first + moveDir[i].y;
                int nx = a.second + moveDir[i].x;

                if(0 <= nx && nx < m && 0 <= ny && ny < n) {
                    if(map[ny][nx] == 0) {
                        q.push(pair<int,int>(ny,nx));
                        map[ny][nx] = 1;
                    }
                }
            }
        }

        result++;
        // 다 익었는지 체크.
        if(theEnd()) {
            cout << result << endl;
           return; 
        }
    }

    // 모두 익지 못한 경우
    cout << -1 << endl;
    return;
}

int main () {
    
    input();
    // initial finishing conditon.
    if(check()) {
        cout << 0 << endl;
    } else {
        sol();
    }
    
}