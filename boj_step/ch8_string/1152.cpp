#include <iostream>
#include <string>
#include <string.h>
using namespace std;



int main () {
    string s;
    int cnt = 0;
    bool space = true;
    getline(cin, s);
    
    for(int i=0;i<s.length();i++) {
        if(s[i] == ' ') {
            space = true;
        } else if (space) {
            space = false;
            cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}
