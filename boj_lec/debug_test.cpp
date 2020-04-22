#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

int a[5][5];

int main () {
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(3);
    pq.push(9);
    pq.push(6);

    while(!pq.empty()) {
        int x = pq.top();
        pq.pop();
        cout << x << " ";
    }

}

// 채팅 문의 : https://coding-test.channel.io
