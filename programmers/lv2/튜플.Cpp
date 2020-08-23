#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


bool cmp (pair<int,int> a,pair<int,int> b) {
    return a.first > b.first;
}

vector<int> solution(string s) {
    vector<int> answer;
    int arr[100010] = {0,};

    string tmp = "";
    for(int i=0;i<s.length();i++) {
        if(s[i] - '0' >= 0 && s[i] - '0' <= 9) {
            tmp += s[i];
        } else {
            if(tmp.length()) {
                arr[stoi(tmp)]++;
                tmp.clear();
            } 
        }
    }

    vector<pair<int,int>> v;
    for(int i=0;i< 100010;i++) {
        if(arr[i]) v.push_back(make_pair(arr[i],i));
    }
    sort(v.begin(),v.end(),cmp);
    for(auto x : v) answer.push_back(x.second);
    return answer;
}

