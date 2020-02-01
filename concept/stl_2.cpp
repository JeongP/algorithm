#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp (pair<string, pair<int,int>> a, pair<string, pair<int,int>> b) {
    if(a.second.first == b.second.first) {
        return a.second.second > b.second.second;
    } else {
        return a.second.first > b.second.first;
    }
}
int main () {
    
    vector<pair<string, pair<int,int>>> v;
    v.push_back(pair<string, pair<int,int>> ("jp",pair<int,int>(90,19930101)));
    v.push_back(pair<string, pair<int,int>> ("jap",pair<int,int>(95,19910101)));
    v.push_back(pair<string, pair<int,int>> ("jaap",pair<int,int>(61,19960101)));
    v.push_back(pair<string, pair<int,int>> ("jzzzp",pair<int,int>(95,20000101)));
    v.push_back(pair<string, pair<int,int>> ("ccjp",pair<int,int>(47,39930101)));
    

    sort(v.begin(), v.end(),cmp);
    for (int i=0; i<v.size();i++) {
        cout << v[i].first << " ";
    }
}