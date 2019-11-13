#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<pair<int,int>> vec;
    vec.push_back(make_pair(1,6));
    vec.push_back(make_pair(2,4));
    vec.push_back(make_pair(3,7));
    vec.push_back(make_pair(4,5));

    for(int i=0; i<vec.size();i++) {
        cout << vec[i].first << endl;
    }

    vector<int> vec2;
    vec2.push_back(1);
    vec2.push_back(2);
    vec2.push_back(3);
    vec2.push_back(4);

    cout << vec2 << endl;

}