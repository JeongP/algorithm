// 일곱 난쟁이
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sumVector(vector<int> v) {
    int result = 0;
    for(int i=0;i<9;i++) {
        result += v[i];
    }
    return result;
}

int main ()  {
    int sum = 0;
    vector<int> v;

    for(int i=0;i<9;i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    sum = sumVector(v);
    
    bool chk = false;
    for(int i=0;i<8;i++) {
        for(int j=i+1;j<9;j++) {
            if(sum - (v[i]+v[j]) == 100) {
                v[i] = -1;
                v[j] = -1;
                chk = true;
                break;
            }
        }
        if(chk) break;
    }
    cout << endl;
    sort(v.begin(), v.end());
    for(int i=2;i<9;i++) {
        cout <<v[i] << endl;
    }
}
