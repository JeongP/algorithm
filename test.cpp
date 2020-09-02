#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    vector<vector<int>> v;
    v[0].push_back(3);
    v[1].push_back(4);
    // for(int i=0;i<v.size();i++) {
    //     for(int j=0;j<v[0].size();j++) {
    //         cout << v[i][j] << " ";
    //     }
    //     cout << endl; 

    // }
    cout << v[0][0];
}