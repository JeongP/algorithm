#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 20001;
int k;
vector<int> vec[MAX];
int nodeColor[MAX];
int v,e;
bool c = false;


void dfs (int idx, int color) {
    nodeColor[idx] = color;
    
    for(int i=0;i<vec[idx].size();i++) {
        int n_idx = vec[idx][i];
        if(nodeColor[n_idx] == 0) {
            dfs(n_idx, 3-color);
        }
    }
}

void check() {
    for(int i=1;i<=v;i++) {
        for(int j=0;j<vec[i].size();j++) {
            int next_node = vec[i][j];
            if(nodeColor[i] == nodeColor[next_node]) {
                c = true;
                return;
            }
        }
    }
}

void initialize() {
    c = false;
    memset(vec, 0, sizeof(vec));
    memset(nodeColor, 0, sizeof(nodeColor));
}


void func() {
    cin >> k;

    while(k--) {
        
        cin >> v >> e;
        for(int i=0;i<e;i++) {
            int a,b;
            cin >> a >> b;
            vec[a].push_back(b);
            vec[b].push_back(a);
        }

        for(int i=1;i<=v;i++) {
            if(nodeColor[i] == 0) dfs(i,1);
        }
        
        check();
        if(c) cout << "NO" << endl;
        else cout << "YES" << endl;

        initialize();
    }
}




int main () {
    func();
    
}