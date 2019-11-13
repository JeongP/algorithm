#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool c[8];
vector<int> vec[8];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    c[start] = true;

    while(!q.empty()) {
        int x = q.front();
        q.pop();
        cout << x << " "; 
        for(int i=0;i<vec[x].size();i++) {
            int y = vec[x][i];
            if(!c[y]) {
                q.push(y);
                c[y] = true;
            }
        }    
    }
}

int main () {

}