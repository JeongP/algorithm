#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

int a[5][5];
bool cmp(vector<vector<int>> a, vector<vector<int>> b) {
   if (a[1] == b[1])
      return a[1] > b[1];

   else
      return a[2] > b[2];
}
int main () {

    // 우선순위 큐 2차원 배열
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push(make_pair(3,2));
    pq.push(make_pair(7,2));
    pq.push(make_pair(6,2));
    // pq.push(9);
    // pq.push(6);

    // while(!pq.empty()) {
    //     int x = pq.top().first;
    //     pq.pop();
    //     cout << x << " ";
    // }

    
}

// 채팅 문의 : https://coding-test.channel.io
