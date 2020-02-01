#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> numberVector;
vector<int> operatorVector;

int maxResult = -1000000000;
int minResult = 1000000000;

void input() {
    
    cin >> N;

    int x;
    for(int i=0;i<N;i++) {
        cin >> x;
        numberVector.push_back(x);
    }
    
    for(int i=0;i<4;i++) {
        cin >> x;
        operatorVector.push_back(x);
    }
}

void dfs(int plus, int minus, int multi, int div, int cnt, int result) {
    if(cnt == N) {
        maxResult = max(maxResult,result);
        minResult = min(minResult, result);
    }

    if(plus > 0)
    dfs(plus-1,minus,multi,div,cnt+1,result+numberVector[cnt]);
    if(minus > 0)
    dfs(plus,minus-1,multi,div,cnt+1,result-numberVector[cnt]);
    if(multi > 0) 
    dfs(plus,minus,multi-1,div,cnt+1,result*numberVector[cnt]);
    if(div > 0) 
    dfs(plus,minus,multi,div-1,cnt+1,result/numberVector[cnt]);
}

void solution() {
    dfs(operatorVector[0],operatorVector[1],operatorVector[2],operatorVector[3],1,numberVector[0]);
}

void prt() {
    cout << maxResult << endl << minResult;
}

int main () {
    
    input();
    solution();
    prt();
}