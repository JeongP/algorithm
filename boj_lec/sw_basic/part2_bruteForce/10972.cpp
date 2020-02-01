// 다음순열
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int MAX = 10001;
bool visit[MAX];
vector<int> v;
stack<int> s;
stack<int> s2;
int N;
bool vFind;

void prt(stack<int> s) {
    for(int i=0;i<s.size();i++) {
        int x = s.top();
        s.pop();
        s2.push(x);
    }

    for(int i=0;i<s2.size();i++) {
        int x = s2.top();
        s2.pop();
        cout << x << " ";
    }
}

void dfs(int n, int depth) {
    if(vFind) {
        if(depth==N-1) {
            prt(s);
        } else {
            for(int i=1;i<=N;i++) {
                if(!visit[i]) {
                    visit[i] = true;
                    s.push(i);
                    dfs(i,depth+1);
                    s.pop();
                    visit[i] = false;
                }
            }
        }

    }
    
    if(depth == N-1) {
        vFind = true;
        return;
    }

    for(int i=1;i<=N;i++) {
        if(!visit[i] && v[i]==i) {
            visit[i] = true;
            s.push(i);
            dfs(i,depth+1);
            s.pop();
            visit[i] = false;
        }
    }
}

int main () {

    cin >> N;
    
    int a;
    for(int i=1;i<=N;i++) {
        cin >> a;
        v.push_back(a);
    }

    for(int i=1;i<=N;i++) {
        visit[i] = true;
        s.push(i);
        dfs(i, 0);
        s.pop();
        visit[i] = false;
    }

}