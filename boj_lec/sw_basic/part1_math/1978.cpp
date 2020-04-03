#include <iostream>
#include <vector>
using namespace std;

int main () {
    int n;
    vector<int> v;
    int result =0;

    cin >> n;
    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    for(int i=0; i<v.size();i++) {
        int cnt = 0;
        if(v[i] == 1) continue;
        for(int j=2;j<=v[i];j++) {
            if(v[i]%j == 0) cnt++;
        }
        if(cnt == 1) result++;
    }

    cout << result;

}