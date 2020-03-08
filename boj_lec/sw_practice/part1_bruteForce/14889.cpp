/*

    1. 팀을 나누고
    2. 팀의 능력치 계산하고 
    3. min값 찾기

 */

#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

const int MAX =20+1;
int N;
int map[MAX][MAX];
bool visit[MAX];
int answer = 987654321;


void input() {
    cin >> N;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            cin >> map[i][j];
        }
    }
}

int findMinus() {
    int tSum = 0;
    int fSum = 0;
    // map에서 true, false로 구분된 팀원들의 능력치 합 구하기.
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=N;j++) {
            if(visit[i] && visit[j]) {
                tSum += map[i][j];
            }
            if(!visit[i] && !visit[j]) {
                fSum += map[i][j];
            }
        }
    }

    return abs(tSum - fSum);
}


void dfs(int idx, int depth) {
    
    if(depth == N/2) {
        // 각 팀의 합을 구해, 차를 구한다.
        int a = findMinus();
        // find min value
        answer = min(a, answer);
        return;
    }

    for(int i=idx;i<=N;i++) {
        if(!visit[i]) {
            visit[i] = true;
            dfs(i,depth+1);
            visit[i] = false;
        }
    }
}

void sol() {
    // divide team
    for(int i=1;i<=N/2;i++) {
        if(!visit[i]) {
            visit[i] = true;
            dfs(i,1);
            visit[i] = false;
        }
    }
    
}

int main() {
    input();
    sol();
    cout << answer << endl;
}