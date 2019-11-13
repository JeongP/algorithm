#include <iostream>
#include <vector>

using namespace std;

bool check[8];
vector<int> v[8];

void dfs (int start) {
    if(check[start]) return;
    check[start] = true;
    cout << start << " ";
    // printf("%d", start);
    for (int i=0; i<v[start].size();i++) {
        int x = v[start][i];
        dfs(x);
    }
}

bool c[8];

void dfs2 (int x)  {
    if(c[x]) return;
    c[x] = true;
    cout << x << ' ';

    for(int i=0; i<v[x].size();i++) {
        int y = v[x][i];
        dfs2(y);
    }
}
int main () {
    
}