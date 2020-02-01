#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 15;
int L,C;
int ja_cnt = 0;
int mo_cnt = 0;
vector<char> v;
vector<char> answer_vec;
bool isVisited[MAX];

void input () {
    cin >> L >> C;
    char x;
    for(int i=0;i<C;i++) {
        cin >> x;
        v.push_back(x);
    }

}


int isJa (char x) {
    if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
        return 0;
    }else {
        return 1;
    }
}

int isMo (char x) {
    if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
        return 1;
    }else {
        return 0;
    }
}

void prt() {
    
    for(int i=0;i<L;i++) {
        cout << answer_vec[i];
    }
    cout << endl;
}

void dfs(int ja_c, int mo_c, int depth, int now) {
    if(depth == L && ja_c >=2 && mo_c >= 1) {
        prt();
    } 

    for(int i=now+1;i<C;i++) {
        if(!isVisited[i]) {
            isVisited[i] = true;
            answer_vec.push_back(v[i]);
            dfs(ja_c + isJa(v[i]), mo_c + isMo(v[i]), depth+1, i);
            answer_vec.pop_back();
            isVisited[i] = false;
        }
    }
}



void solution() {

    for(int i=0;i<C-L+1;i++) {
        isVisited[i] = true;
        answer_vec.push_back(v[i]);
        dfs(isJa(v[i]),isMo(v[i]),1,i);
        answer_vec.pop_back();
        isVisited[i] = false;
    }
}

int main () {
    input();
    sort(v.begin(),v.end());
    // cout << v[0] << v[1];
    solution();
}