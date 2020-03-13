#include <iostream>
#include <string>
using namespace std;

int main () {
    int N;
    string s;
    int sum = 0;
    cin >> N >> s;

    for(int i=0;i<s.length();i++) {
        int a = s[i] -'0';
        sum+=a;
    }
    cout << sum << endl;
    
    return 0;
}