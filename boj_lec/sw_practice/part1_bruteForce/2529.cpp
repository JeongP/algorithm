#include <iostream>
#include <vector>
#include <string>
using namespace std;

int k;
vector<char> op_v;
vector<int> v;
string minS = "9876543210";
string maxS = "0123456789";
bool used[10];

void input () {
    cin >> k;
    for(int i=0;i<k;i++) {
        char x;
        cin >> x;
        op_v.push_back(x);
    }
}

string makeString(vector<int> v) {
    string temp = "";
    for(int i=0;i<v.size();i++) {
        char a = v[i] + '0';
        temp += a;
    }
    return temp;
}

void DFS(int before_num,int op_loc) {

    if(op_loc == k) {
        string madeString = makeString(v);
        minS = min(minS, madeString);
        maxS = max(maxS, madeString);
    }
    
    for(int i=0;i<=9;i++) {
        if(op_v[op_loc] == '<') {
            if(!used[i] && before_num < i) {
                used[i] = true;
                v.push_back(i);
                DFS(i,op_loc+1);
                v.pop_back();
                used[i] = false;
            }
        } else if (op_v[op_loc] == '>') {
            if(!used[i] && before_num > i) {
                used[i] = true;
                v.push_back(i);
                DFS(i,op_loc+1);
                v.pop_back();
                used[i] = false;
            }
        }
    }
}


void sol () {
    for(int i=0;i<=9;i++) {
        used[i] = true;
        v.push_back(i);
        DFS(i,0);
        v.pop_back();
        used[i] = false;
    }
}


int main () {
    input();
    sol();
    cout << maxS << '\n';
    cout << minS << '\n';
}