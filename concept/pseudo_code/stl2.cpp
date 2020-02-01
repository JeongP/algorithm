#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp (pair<string, int> a, pair<string, int> b) {
    return a.second < b.second;
}

int main () {
    vector<pair<string, int>> v;
    v.push_back(pair<string, int> ("c",99));
    v.push_back(pair<string, int> ("d",19));
    v.push_back(pair<string, int> ("ap",999));
    v.push_back(pair<string, int> ("bp",89));

    sort(v.begin(), v.end(), cmp);

    for(int i=0;i<v.size();i++) {
        cout << v[i].first << " ";
    }
}