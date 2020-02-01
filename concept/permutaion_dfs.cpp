#include <iostream>
#include <vector>

using namespace std;

bool visited[3];
vector<int> v;
void dfs(int n) {
    // 배열 모든 원소에 대해 진행한다.
    // 방문하지 않았다면, 방문처리를 해주고 벡터에 담아준다.
    // v.size()가 n과 같다면 print를 해준다.
    // 모든 과정이 완료되면 v에서 제외해준다.

    if(v.size() == n) {
        for(int i=0;i<n;i++) {
            cout << v[i];
        }
        cout << endl;
        return;
    }

    for (int i=0; i<n; i++) {
        
        if(!visited[i]) {
            visited[i] = 1;
            v.push_back(i+1);
            dfs(n);
            visited[i] = 0;
            v.pop_back();
        }
    }
}


int main () {
    int arr[3] = {1,2,3};
    
    dfs(3);
    return 0;
}