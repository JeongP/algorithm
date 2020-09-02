#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s) {
    string answer = "";
    int min, max;
    vector<int> v;
    
    string tmp = "";
    for(int i=0;i<s.length();i++) {
        if(i == s.length()-1) {
            tmp += s[i];
            v.push_back(stoi(tmp));
        }
        else {
            if(s[i] == ' ') {
                int n = stoi(tmp);
                tmp = "";
                v.push_back(n);
            }else {
                tmp += s[i];
            }
        }
        
    }
    
    min = v[0]; max = v[0];
    for(int i=1;i<v.size();i++) {
        if(min > v[i]) min = v[i];
        if(max < v[i]) max = v[i];
    }
    
    answer = to_string(min) + " " + to_string(max);
    return answer;
}