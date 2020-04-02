/*

    1. 잘린 부분을 찾고
    2. 가로로 자를 수 있는 최대치부터 최소치까지 돌면서 DFS
    3. 세로 또한 마찬가지

 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, M;
int map[5][5];
bool visit[5][5];
int sum = 0;

void input() {
    cin >> N >> M;
    string s;
    for(int i=1;i<=N;i++) {
        cin >> s;
        for(int j=1;j<=s.length();j++) {
            map[i][j] = s[j-1] - '0';   
        }
    }
}


pair<int,int> findPoint() {
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            if(!visit[i][j]) return {i,j};
        }
    }
    return {-1,-1};
}

int makeSize(int y, int x, char c) {
    int val = 0;
    if(c == 'G') {
        for(int i=x;i<=M;i++) {
            if(!visit[y][i]) val++;
            else break;
        }
    } else {
        for(int i=y;i<=N;i++) {
            if(!visit[i][x]) val++;
            else break;
        }
    }
    // cout << val << endl;
    return val;
}

int make_subSum(int y,int x, char c, int siz) {
    int total = 0;
    if(c == 'G') {
        for(int i=x;i<x+siz;i++) {
            total += map[y][i];
            total = total*10;
        }
    }else {
        for(int i=y;i<y+siz;i++) {
            total += map[i][x];
            total = total * 10;
        }
    }
    total /= 10;
    return total;
}

void dfs(int total) {
    
    // 어디서부터 잘라야되는지 시작점 잡고
    pair<int,int> startPoint = findPoint();
    int y = startPoint.first;
    int x = startPoint.second;

    // 더 이상 절단할 부분이 없다면
    if(x==-1 && y==-1) {
        // cout << total << endl;
        sum = max(total, sum);
        return;
    }

    // 가로로 최대한 갈 수 있는 부분 찾기.
    int size = makeSize(y,x,'G');
    for(int i=size;i>0;i--) {
        // 방문처리하고
        for(int j=x;j<x+i;j++) {
            visit[y][j] = true;
        }
        // 해당 범위의 합 구하고
        int subsum = make_subSum(y,x,'G',i);
        // cout << subsum << endl;
        // DFS
        dfs(total + subsum);
        // 방문처리 해제
        for(int j=x;j<x+i;j++) {
            visit[y][j] = false;
        }
    }

    size = makeSize(y,x,'S');
    for(int i=size;i>0;i--) {
        for(int j=y;j<y+i;j++) {
            visit[j][x] = true;
        }

        int subsum = make_subSum(y,x,'S',i);
        dfs(total+subsum);

        for(int j=y;j<y+i;j++) {
            visit[j][x] = false;
        }
    }

}

void sol() {
    dfs(0);
}

int main () {
    input();
    sol();
    cout << sum << endl;
}