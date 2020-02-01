#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> t;
vector<int> p;
int total_price = 0;

void input() {
    cin >> N;
    t.resize(N);
    p.resize(N);
    for(int i=0;i<N;i++) {
        cin >> t[i] >> p[i];
    }
}

void dfs(int day, int time, int price) {

    if(day > N-1) return;

    total_price = max(total_price, price);

    if(day+time == N-1 && t[day+time] != 1) {
        return;   
    }
    dfs(day+time, t[day+time], price + p[day+time]);
    dfs(day+time, 1, price);
}

int main () {
    input();
    // 상담한다.
    dfs(0,t[0],p[0]);
    // 상담안한다.
    dfs(0,1,0);
    cout << total_price;
}

// // 근무 불가 날짜.
    // if(day+1 <= day+time) {
    //     dfs(day+1, time, price);
    // } else {
    //     // 근무 가능 날짜.
    //     if(day+1 == N-1 && t[day+1] != 1) {
    //         dfs(day+1, 0, price);
    //     } else {
    //         dfs(day+1, t[day+1], price+p[day+1]);
    //         dfs(day+1, 0, price);
    //     }   
    // }