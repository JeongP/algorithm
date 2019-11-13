#include <iostream>
#include <queue>

using namespace std;

int main () {

    queue<pair<int,int>> q;
    queue<pair<int,int>> p;
    q.push(make_pair(3,5));
    q.push(pair<int,int>(3,1));
    p.push(q.front());

    pair<int,int> r = make_pair(7,7);
    q.push(r);

    cout << q.front().first << endl;
}