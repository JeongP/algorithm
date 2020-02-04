#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

const int MAX = 100001;
bool v[MAX];


int sol (int n, int k) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
   
    // 위치와 경과시간을 담은 큐
    q.push(make_pair(0,n));
    v[n] = true;

    while(!q.empty()) {
        
        int sec = q.top().first;
        int loc = q.top().second;
        q.pop();

        if(loc == k) return sec;

        if(loc-1>=0 && !v[loc-1]) {
            v[loc-1] = true;
            q.push(make_pair(sec+1,loc-1));
        }

        if(loc+1<=MAX && !v[loc-1]) {
            v[loc+1] = true;
            q.push(make_pair(sec+1,loc+1));
        }

        if(loc*2 <= MAX && v[loc*2]) {
            v[2*loc] = true;
            q.push(make_pair(sec,loc*2));
        }
    }

}

int main () {

    int n,k;
    cin >> n >> k;

    cout << sol(n,k) << endl;
}