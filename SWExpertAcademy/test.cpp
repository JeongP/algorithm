#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

int main () {
    int a = 10;
    // cout << (int)sqrt(a) << endl;    

    set<int> s;
    s.insert(40);
    s.insert(10);
    s.insert(80);
    s.insert(30);
    s.insert(70);
    s.insert(60);
    s.insert(20);
    s.insert(50);

    set<int>::iterator iter;
    for(iter=s.begin();iter!=s.end();iter++) {
        cout << *iter << " ";
    }
    cout << endl;

    s.insert(30);
    

}