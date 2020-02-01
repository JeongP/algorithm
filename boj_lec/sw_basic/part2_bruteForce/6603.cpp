#include <iostream>
#include <vector>

using namespace std;
const int MAX = 50;
int n;
vector<int> v;
vector<int> answer_vec;
bool isVisit[MAX];

void input() {
    cin >> n;
    if(n==0) return;
    int x;
    for(int i=0;i<n;i++) {
        cin >> x;
        v.push_back(x);
    }
}

void prt() {
    for(int i=0;i<6;i++) {
        cout << answer_vec[i] << " ";
    }
    cout << endl;
}

void dfs(int now, int cnt) {
    if(cnt == 6) {
        // 스택 역출력
        prt();
    }
    for(int i=now;i<n;i++) {
        if(!isVisit[i]) {
            isVisit[i] = true;
            answer_vec.push_back(v[i]);
            dfs(i,cnt+1);
            answer_vec.pop_back();
            isVisit[i] = false;
        }
    }
}
void solution() {
    for(int i=0;i<n-5;i++) {
        isVisit[i] = true;
        answer_vec.push_back(v[i]);
        dfs(i,1);
        answer_vec.pop_back();
        isVisit[i] = false;
    }
}

void clear_vector() {
    v.clear();
    answer_vec.clear();
}

int main () {
    
    while(1) {
        input();
        if(n==0) return 0;
        solution();
        cout << endl;
        clear_vector();
    }
    return 0;
}