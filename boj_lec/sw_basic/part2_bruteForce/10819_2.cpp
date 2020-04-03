#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    int n;
    cin >> n;
    int result = 0;
    vector<int> v;
    for(int i=0;i<n;i++) {
        int x; cin >> x;
        v.push_back(x);
    }

    sort(v.begin(),v.end());
    do {
        int sum = 0;
        for(int i=0;i<v.size()-1;i++) {
            sum += abs(v[i] - v[i+1]);
        }
        result = max(result, sum);

    }while(next_permutation(v.begin(),v.end()));

    cout << result << endl;
}