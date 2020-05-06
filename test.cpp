#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main () {
    vector<vector<int>> V2D;

    vector<int> v1;
    vector<int> v2;

    for(int i=0;i<2;i++) {
        v1.push_back(i);
    }
    
    for(int i=0;i<5;i++) {
        v2.push_back(i);
    }

    V2D.push_back(v1);
    V2D.push_back(v2);

    cout << V2D[0].size();
    cout << V2D[1].size();


}