#include <iostream>
#include <queue>

using namespace std;

int main () {
    priority_queue <int,vector<int>,greater<int>> q;
    q.push(3);
    q.push(5);
    q.push(1);

    cout << q.top();

}