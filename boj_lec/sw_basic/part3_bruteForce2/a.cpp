#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define MAX 9

using namespace std;

int N,M;
int arr[MAX];
bool visit[MAX];
vector<int> v;
void input() {
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        cin >> arr[i];
    }
    sort(arr, arr+N);
}

void sol() {
    for(int i=0;i<N;i++) {
        visit[i] = true;
        v.push_back(arr[i]);
        dfs(i,1);
        v.pop_back();
        visit[i] = false;
    }
}


int main () {

    input();
    sol();

}