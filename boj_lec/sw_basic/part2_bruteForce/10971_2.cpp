#include <iostream>
using namespace std;

const int MAX = 11;
int map[MAX][MAX];
bool isVisit[MAX];
int n;
int minSum = 987654321;

void input() {
    cin >> n;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin >> map[i][j];
        }
    }
}

void dfs (int start, int dest, int sum, int cnt) {
    if(cnt == n && dest == start) {
        if(sum < minSum) minSum = sum;
        return;
    }

    for(int i=0;i<n;i++) {
        if(map[dest][i] == 0) continue;

        if(!isVisit[i]) {
            isVisit[i] = true;
            sum += map[dest][i];
            // minSum > sum인 경우만 실행
            if(minSum > sum) dfs(start, i, sum, cnt+1);
            isVisit[i] = false;
            sum -= map[dest][i];
        }
    }
}
void solution () {
    for(int i=0;i<n;i++) {
        dfs(i,i,0,0);
    }
}

void output() {
    cout << minSum << endl;
}

int main () {

    input();
    solution();
    output();
    return 0;
}