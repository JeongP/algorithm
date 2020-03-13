#include <iostream>
#include <string>
using namespace std;

int main () {
    int T,R;
    string S;
    

    cin >> T;
    
    while(T--) {
        cin >> R >> S;

        string answer = "";
        
        for(int i=0;i<S.length();i++) {
            for(int j=0;j<R;j++) {
                answer += S[i];
            }
        }

        cout << answer << endl;
    }
}
