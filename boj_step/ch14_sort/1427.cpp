#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool desc(int a,int b) {
    return a > b;
}

int main () {
    string s;
    cin >> s;
    string answer = "";
    vector<int> v;

    for(int i=0;i<s.length();i++) {
        int x = s[i] - '0';
        v.push_back(x);
    }

    sort(v.begin(),v.end(), desc);
    for(int i=0;i<v.size();i++) {
        answer += v[i] + '0';
    }

    cout << answer << endl;
}