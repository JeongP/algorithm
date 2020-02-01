#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    int N;
    cin >> N;

    vector<int> v;
    int x;
    for(int i=0;i<N;i++) {
        cin >> x;
        v.push_back(x);
    }

    if(next_permutation(v.begin(),v.end())) {
        for(int i=0;i<N;i++) {
            cout << v[i] << " ";
        }
    } else {
        cout << -1;
    }

}