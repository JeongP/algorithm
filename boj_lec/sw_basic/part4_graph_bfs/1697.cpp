#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100001;
bool visited[MAX];

int minSecond(int n,int k) {
    queue<pair<int,int>> q;
    q.push(pair<int,int>(n,0));
    visited[n] = true;

    while(!q.empty()) {
        int curLoc = q.front().first;
        int curSec = q.front().second;
        q.pop();
        // cout << curLoc << "," << curSec << endl;

        if(curLoc == k) return curSec;

        if(curLoc+1 < MAX && !visited[curLoc+1]) {
            visited[curLoc+1] = true;
            q.push(pair<int,int>(curLoc+1,curSec+1));
        }

        if(curLoc-1 >= 0 && !visited[curLoc-1]) {
            visited[curLoc-1] = true;
            q.push(pair<int,int>(curLoc-1,curSec+1));
        }

        if(curLoc*2 < MAX && !visited[curLoc*2]) {
            visited[curLoc*2] = true;
            q.push(pair<int,int>(curLoc*2,curSec+1));
        }
    }
    return 0;
}

int main () {
    int n,k;
    cin >> n >> k;

    cout << minSecond(n,k) << endl;
    return 0;
}