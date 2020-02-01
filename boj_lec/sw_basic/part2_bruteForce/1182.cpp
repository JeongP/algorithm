#include <iostream>
#include <vector>

using namespace std;

int N, S;
int result_cnt = 0;
vector<int> v;
bool isVisited[20];
bool breaker;

void input() {
    cin >> N >> S;
    
    int x;
    for(int i=0;i<N;i++) {
        cin >> x;
        v.push_back(i);
    }
}

void dfs(int index, int sum) {

    // 부분합이 입력 값 S와 같다면 출력값 ++;
    if(sum == S) result_cnt+=1;

    // 다음 부분에 대해서 탐색.
    for(int i=index+1; i<N;i++) {
        if(!isVisited[i]) {
            isVisited[i] = true;
            dfs(i,sum+v[i]);
            isVisited[i] = false;
        }

    }

    
}

void solution() {
    for(int i=0;i<N;i++) {
        isVisited[i] = true;
        // depth가 최대일 때는 한 번만 체크하는 조건을 넣어줘야함.(모든 결과 같기에)
        dfs(i, v[i]);
        isVisited[i] = false;
        breaker = false;
    }
}

void prt() {
    cout << result_cnt;
}

int main () {
    input();
    solution();
    prt();
}


/*

0. 모든 수 체크 -> DFS
1. [ 7 3 2 5 ] 나 [ 3 7 5 2] 나 같은 결과 (순서 x) -> for( now ~)
2. 방문체크 필요
3. cnt를 담을 result 필요.
4. 매 단계에서 입력 값 S와 비교 필요.
5. dfs의 마지막 조건 굳이 필요 x

 */