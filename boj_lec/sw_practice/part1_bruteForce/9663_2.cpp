#include <iostream>
using namespace std;

int N;
int answer;
int map[15][15];

void dfs(int n) {
    if(n == N) {
        answer++;
        return;
    }
    
}

int main () {
    cin >> N;
    dfs(0);
}