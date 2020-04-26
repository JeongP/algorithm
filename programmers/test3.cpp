#include <string>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;

int divide(string s) {
    int idx = 0;
    for(int i=0;i<s.length();i++) {
        int a = s[i] - '0';
        if(a>1 && a<9) {
            idx = i;
            break;       
        }
    }
    return idx;
}

string solution(vector<string> registered_list, string new_id) {
    string answer = "";
    vector<string>::iterator it;
    

    while(1) {
        it = find(registered_list.begin(),registered_list.end(),new_id);
        // 없는경우
        if(it == registered_list.end()) {
            answer = new_id;
            return answer;
        } else {
            int idx = divide(new_id);
            if(idx == 0) {
                new_id += "1";
            } else {
                // string
                string str = new_id.substr(0,idx);
                // number
                int n = atoi(new_id.substr(idx,10).c_str());
                n+=1;
                cout << n << " ";
                new_id = str + to_string(n);
            }
            
        }
    }
    return answer;
}