#include <iostream>
#include <map>
#include <string>
using namespace std;

int main () {
    multimap<int,string> mm;
    mm.insert(make_pair(60,"C"));
    mm.insert(make_pair(30,"C++"));
    mm.insert(make_pair(70,"Linux"));
    mm.insert(make_pair(90,"Mac"));

    multimap<int,string>::iterator iter;

    // size , count
    cout << mm.size() << endl;
    cout << mm.count(30) << endl;

    for(iter = mm.begin();iter!=mm.end();iter++) {
        cout << "(" << iter->first << "," << iter->second << ")";
    }
    cout << endl << endl;

    mm.insert(make_pair(30,"Java"));
    mm.insert(make_pair(30,"Unix"));

    cout << mm.count(30) << endl;

    //upper_bound, lower_bound
    cout << " upper_bound, lower_bound " << endl;
    
    for(iter = mm.lower_bound(30);iter!=mm.upper_bound(30);iter++) {
        cout << "(" << iter->first << "," << iter->second << ")";
    }
}


/*

출처 : https://modoocode.com/224


 */