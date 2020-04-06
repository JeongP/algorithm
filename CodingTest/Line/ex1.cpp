/*
    1. 입력값 N,K를 입력받는다. N개의 group도 입력받음.
    2. 각 group을 돌면서 ticketOffice의 값중 최소의 값에 넣어주고 그 ticketOffice 값들을 더한다.
    3. 모든 그룹을 반복하고 최대로 걸린 시간 찾아서 리턴.
    
 */

#include <iostream>
using namespace std;

int n,k;
int group[1010];
int ticketOffice[20];

void input() {
    cin >> n >> k;
    for(int i=0;i<n;i++) {
        cin >> group[i];
    }
}

int find_to () {
    int idx = 1;
    int minvalue = ticketOffice[1];
    for(int i=1;i<=k;i++) {
        if(ticketOffice[i] < minvalue) {
            minvalue = ticketOffice[i];
            idx = i;
        }
    }
    return idx;
}

void solution() {
    for(int i=0;i<n;i++) {
        int idx = find_to();
        ticketOffice[idx] += group[i];
    }
    
    int maxValue = ticketOffice[0];
    for(int i=1;i<k;i++) {
        if(maxValue < ticketOffice[i]) {
            maxValue = ticketOffice[i];
        }
    }

    cout << maxValue << endl;
}

int main () {
    input();
    solution();
}