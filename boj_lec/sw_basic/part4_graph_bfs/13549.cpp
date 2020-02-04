#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100001;
bool v[MAX];

int BFS(queue<pair<int,int>> q, int k) {
    
    while(!q.empty()) {
        
        int loc = q.front().first;
        int sec = q.front().second;
        q.pop();

        if(k==loc) return sec;

        if(loc*2 <= MAX && !v[2*loc]) {
            v[2*loc] = true;
            q.push(make_pair(2*loc, sec));
        }

        if(loc-1>=0 && !v[loc-1]) {
            v[loc-1] = true;
            q.push(make_pair(loc-1,sec+1));
        }

        if(loc+1<=MAX && !v[loc+1]) {
            v[loc+1] = true;
            q.push(make_pair(loc+1,sec+1));
        }

        
        
    }
    return 0;
}

int main () {
    int n, k;
    cin >> n >> k;
    queue<pair<int,int>> q;
    q.push(make_pair(n,0));
    int answer = BFS(q,k);
    cout << answer << endl;
}   


/*
    1. 최소시간 탐색 -> BFS
    2. 위치와 시간이 분기의 기준이 되므로, 방문여부를 체크해주어 분기 제한을 둔다. ( v[x][t] )
    3. 각 조건별로 진행하여 (다음스탭이 범위내에 있고, 방문가능한 경우), 결과를 도출한다. 

    위 풀이의 문제.
    배열[100000][100000] => 엄청나게 큰 용량 차지.

    -----

    1차원 배열로 해서 진행했으나, 테스트케이스에는 문제 없으나 결과는 틀렸습니다.
    아마 좌,우, 점프 순서로 하다보니 더 긴 시간에 결과 출력되는 경우 있을 것이라고 예상.
    => 시간경과가 없는 곱사건을 가장 우선 조건으로 배치 시켜줌으로써 해결 (내풀이에서)
    => priority queue를 사용하여 짧은 시간 우선으로 해서 결과를 출력해주는 방식으로 해결 (13549_2)
    => 혹은 1차원 배열을 bool 자료형이 아닌 int 자료형으로 해서 그 위치에 있을 때 경과 시간을 담아준 후에 그걸로 뽑아준다? (13549_3)


 */