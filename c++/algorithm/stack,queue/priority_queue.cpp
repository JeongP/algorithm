#include <iostream>
#include <queue>
using namespace std;

template <typename T>
void print_pq(priority_queue<T> pq) {
    for(const auto &i : pq) {
        cout << i << " ";
        pq.pop();
    }
}


int main () {
    priority_queue<int, vector<int>, greater<int>> pq;
    
    vector<int> priorities;
    priorities.push_back(2);
    priorities.push_back(1);
    priorities.push_back(3);
    priorities.push_back(2);
    
    
    for(int i : priorities) {
        pq.push(i);
    }
    

    while(!pq.empty()){
        cout << pq.top() << endl;
        pq.pop();
    }


}