#include <iostream>
#include <string>

using namespace std;

int main () {
    
    string s = "abc";
    string t = "def";
    string s2 = s;

    cout << s.length() << endl;
    cout << s + t << endl;
    if(s==s2) {
        cout << "s same s2" << endl;
    }
}