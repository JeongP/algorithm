/*

    1. 입력받은 세개의 숫자를 벡터에 넣는다.
    2. next_permutation을 이용하여 순열을 진행시킨다.
    3. 한 순열이 진행될때마다 cnt++를 해주는데, cnt == k인 경우의 순열을 출력해준다.

 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a,b,c,k;
vector<int> v;

void input() {
    cin >> a >> b >> c >> k;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    sort(v.begin(),v.end());
}

void prt() {
    for(int i=0;i<v.size();i++) {
        cout << v[i] << " ";
    }
}
void sol() {
    int cnt = 1;
    do {
        if(cnt == k) prt();
        cnt++;
    }while(next_permutation(v.begin(),v.end()));
}
int main () {
    input();
    sol();
}