#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v;

    v.push_back(6);
    v.push_back(3);
    v.push_back(9);
    v.push_back(4);

    v.erase(v.begin() + 2);

    for(int i=0; i<v.size(); i++) {
        cout << i << ": " << v[i] << endl;
        cout << v.size();
    }
    return 0;
}