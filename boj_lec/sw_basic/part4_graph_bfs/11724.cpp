#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1001;
int N, M;
int parent[MAX];
int cnt = 0;

int getParent(int p[], int x) {
    if(p[x]==x) return x;
    return getParent(p, p[x]);
}

void unionParent(int p[], int a, int b) {
    a = getParent(p, a);
    b = getParent(p, b);
    if(a < b) p[b] = a;
    else p[a] = b;
}



void input() {
    cin >> N >> M;

    for(int i=0;i<=N;i++) {
        parent[i] = i;
    }

    int u,v;
    for(int i=0;i<M;i++) {
        cin >> u >> v;
        unionParent(parent,u,v);
    }
}

void sol() {
    
    for(int i=1;i<=N;i++) {
        if(parent[i] == i) {
            cnt++;
        }
    }
    cout << cnt << endl;

}

int main () {
    input();
    sol();
}