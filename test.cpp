#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    string s = "abdknzpdknfz";

    sort(s.begin(),s.end(),greater<int>());
    
    cout << s;
}