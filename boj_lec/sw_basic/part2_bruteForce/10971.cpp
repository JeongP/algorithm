#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 11;
int map[MAX][MAX] = {0,};
bool isVisit[MAX];
int n;
int sum = 0;

void input(int n) {
    cin >> n;
}
int dfs(int depth, int start, int origin,int dest) {
    // 모든 도시를 거쳤고, 도착지가 출발지라면 그 맵의 값 리턴
    if(depth == n && start == dest) {
        return map[origin][dest];
    }
    
    for(int i=0;i<n;i++) {
        if(i==origin) continue;
        if(map[origin][dest]) continue;
        isVisit[i] = true;
        sum += max(sum, dfs(depth+1,start,dest,i));
        isVisit[i] = false;
    }
    return sum;
    
}


int main() {

    
    input(n);
    
    int result = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            
            // 같은곳에서 같은곳 or 길이 없는 케이스
            if(map[i][j] == 0) continue;
            // 그 외의 경우
            isVisit[i] = true;
            result = max(result,dfs(0,i,i,j));
            isVisit[i] = false;
        }
    }

    cout << result << endl;
}