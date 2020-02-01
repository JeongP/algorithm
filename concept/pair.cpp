#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main () {
    vector<pair<int,int>> v;
    v.push_back(make_pair(3,5));

    // cout << v[0].first;
    // cout << endl;
    // cout <<v[0].second;

    map<string, int> m;
    m.insert(make_pair("a",4));
    m.insert(make_pair("b",6));
    m.insert(make_pair("c",7));
    m.insert(make_pair("d",8));
    m["e"] = 9;

    m.erase("b");

    cout << m["a"];

    cout << m.count("a");

    for(auto i : m) {
        cout << i.first << " ";
    }


}