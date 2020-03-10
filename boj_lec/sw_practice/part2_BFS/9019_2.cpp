#include <iostream>
#include <cstring>
#include <queue>
#include <string>
using namespace std;

const int MAX = 10000 + 1;
int T,A,B;
queue<pair<int,string>> q;
bool visit[MAX];

void input() {
    cin >> T;
}

void clearQ() {
    while(!q.empty()) {
        q.pop();
    }
}

void BFS() {
    while(!q.empty()) {
        int num = q.front().first;
        string s = q.front().second;
        q.pop();


        if(num == B) {
            cout << s << endl;
            clearQ();
            return;
        }
        
        // D
        int next_num = (num*2)%10000;
        if(!visit[next_num]) {
            visit[next_num] = true;
            q.push(make_pair(next_num,s+"D"));
        }

        // S
        if(num == 0) { 
            next_num = 9999;
        } else {
            next_num = num-1;
        }
        if(!visit[next_num]) {
            visit[next_num] = true;
            q.push(make_pair(next_num,s+"S"));
        }

        // L
        next_num = (num%1000)*10 + num/1000;
        if(!visit[next_num]) {
            visit[next_num] = true;
            q.push(make_pair(next_num,s+"L"));
        }

        // R
        next_num = (num%10)*1000 + num/10;
        if(!visit[next_num]) {
            visit[next_num] = true;
            q.push(make_pair(next_num,s+"R"));
        }

    }

}

void solution() {
    while(T--) {
        memset(visit,false,sizeof(visit));
        cin >> A >> B;
        q.push(make_pair(A,""));
        BFS();
    }
}

int main () {
    input();
    solution();
}