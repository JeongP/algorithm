#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int alphabet[26];

int main () {
    int t;
    cin >> t;
    int result = 0;
    
    while(t--) {
        string s;
        cin >> s;
        bool check = false;
        memset(alphabet,0,sizeof(alphabet));
        // 첫 스펠링 cnt ++
        alphabet[s[0] -'a'] = 1;
        
        for(int i=1;i<s.length();i++) {
            if(s[i-1] == s[i]) continue;
            int x = s[i] - 'a';
            if(alphabet[x] == 0) {
                alphabet[x] += 1;    
            } else {
                check = true;
                break;
            }
        }
        if(!check) {
            result++;
        }
        
    }

    cout << result << endl;

}