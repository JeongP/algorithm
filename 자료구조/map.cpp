/*

    1. unique Key - 키 값 중복 불가능
    2. Ordered - 삽입되면서 자동 정렬
    3. 

 */

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main () {

    // map

    map<int,string> m;
    m.insert(make_pair(40,"SS"));
    map<int,string>::iterator iter;

    for(iter = m.begin(); iter != m.end(); iter++) {
        cout << iter->first << "," << iter->second;
    }

    if(m.find(40) != m.end()) {
        cout << "FInd";
    }
}