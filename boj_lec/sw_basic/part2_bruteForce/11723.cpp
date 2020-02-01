// 있고 없고를 boolean으로 표시하는.

#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 20 + 1;
bool visited[MAX];
int N;

void input() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
}

void sol() {
    string s;
    for(int i=0;i<N;i++) {
        int x;
        cin >> s;
        if(s == "add") {
            cin >> x;
            visited[x] = true;
        }else if( s == "remove") {
            cin >> x;
            visited[x] = false;
        }else if(s=="check") {
            cin >> x;
            if(visited[x]) cout << 1 << endl;
            else cout << 0 << endl;
        }else if(s=="toggle") {
            cin >> x;
            if(visited[x]) visited[x] = false;
            else visited[x] = true;
        }else if(s=="all") {
            memset(visited, true, sizeof(visited));
        }else if(s=="empty") {
            memset(visited, false, sizeof(visited));
        }
    }
}

int main () {
    input();
    sol();
    return 0;
}