// 석찬이의 받아쓰기

#include <iostream>
#include <string>
using namespace std;

int main () {
    int TC;
    cin >> TC;

    string s1;
    string s2;

    int cnt=0;
    int cur_cnt = 0;
    int N;
    while(TC--) {
        cur_cnt++;
        cin >> N;
        cin >> s1 >> s2;
        
        for(int i=0;i<N;i++) {
            if(s1[i]==s2[i]) cnt++;
        }

        cout << "#" << cur_cnt << " " << cnt << endl;
        cnt = 0;
    }
}