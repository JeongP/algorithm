/*
    
    1. 0이라고 적힌 모든 자리에 대해서 왼쪽,오른쪽에 대해 가장 가까운 사람의 거리를 구합니다.
    2. 그 중 작은 값을 배열에 넣고
    3. 마지막에 모든 배열을 확인하여 가장 큰 값을 출력합니다.

 */

#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 987654321;
int n;
int chair[20010];
int dist[20010];

int lCheck(int idx) {
    if(idx > 0) {
        int cnt = 1;
        int i = idx-1;
        while(chair[i] != 1 && i >= 0) {
            cnt++;
            i--;
        }
        return cnt;
    } else {
        return MAX;
    }
    
}

int rCheck(int idx) {
    if(idx < n-1) {
        int cnt = 1;
        int i = idx+1;
        while(chair[i] != 1 && i <= n-1) {
            cnt++;
            i++;
        }
        return cnt;
    } else {
        return MAX;
    }
    
}

int main () {
    
    cin >> n;
    for(int i=0;i<n;i++) {
        cin >> chair[i];
    }

    for(int i=0;i<n;i++) {
        if(chair[i] == 0) {
            int x = min(lCheck(i), rCheck(i));
            dist[i] = x;
        }
    }

    int maxV = dist[0];
    for(int i=1;i<n;i++) {
        if(maxV < dist[i]) maxV = dist[i];
    }

    // for(int i=0;i<n;i++) {
    //     cout << dist[i] << " ";
    // }

    cout << maxV << endl;

    return 0;
}