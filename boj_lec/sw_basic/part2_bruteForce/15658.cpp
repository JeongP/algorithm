#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> v;
int op[4];
int resultMax = -1000000000;
int resultMin = 1000000000;

void input() {
    cin >> N;
    v.resize(N);
    for(int i=0;i<N;i++) {
        cin >> v[i];
    }
    
    for(int i=0;i<4;i++) {
        cin >> op[i];
    }
}

void dfs(int plus, int minus, int multi, int div, int depth, int result) {

    

    if(depth == N) {
        resultMax = max(resultMax, result);
        resultMin = min(resultMin, result);
        return;
    }

    if(plus > 0) dfs(plus-1, minus, multi, div, depth+1, result+v[depth]);
    if(minus > 0) dfs(plus, minus-1, multi, div, depth+1, result-v[depth]);
    if(multi > 0) dfs(plus, minus, multi-1, div, depth+1, result*v[depth]);
    if(div > 0) dfs(plus, minus, multi, div-1, depth+1, result/v[depth]);
}

void sol() {
    dfs(op[0],op[1],op[2],op[3],1,v[0]);
}

void prt() {
    cout << resultMax << endl << resultMin;
}

int main() {
    input();
    sol();
    prt();
}