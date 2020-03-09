#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

const int MAX = 10000;
int T,A,B;
queue<pair<int,string>> q;
bool visit[MAX+1];

void input() {
    cin >> T;
}

void D(int n, string s) {
    int next_num;
    string next_s = s + "D";
    // 조건대로 해주고..
    if(n*2 > 9999) {
        next_num = n*2 % MAX;
    }else {
        next_num = n*2;
    }
    // cout << next_num << "," << next_s << endl;
    
    // 큐에 추가
    q.push(make_pair(next_num,next_s));
}

void S(int n, string s) {
    int next_num;
    string next_s = s + "S";
    if(n == 0) {
        next_num = 9999;
    }else {
        next_num = n-1;
    }
    // cout << next_num << "," << next_s << endl;
    q.push(make_pair(next_num,next_s));
}

void L(int n, string s) {
    int next_num = 0;
    string next_s = s + "L";
    vector<int> v;

    if(n==0) {
        next_num = 0;
    } else {
        // 벡터에 각자리 숫자를 뒤집어서 담아주고
        while(n!=0) {
            int c = n % 10;
            v.push_back(c);
            n = n / 10;
        }
        // 그 사이즈가 1이라면 *10을 통해 자리수 한칸 왼쪽으로 이동
        if(v.size() == 1) {
            next_num = v[0]*10;
            // cout << next_num << endl;
        } else {
            // 그렇지 않다면 조건대로 숫자 만들어주기..
            for(int i=v.size()-2;i>=0;i--) {
                int digit = i+1;
                next_num += v[i] * pow(10,digit);
            }
            next_num += v[v.size()-1];
        }
    }
    
    // cout << next_num << "," << next_s << endl;
    q.push(make_pair(next_num,next_s));
}

void R(int n, string s) {
    int next_num = 0;
    string next_s = s + "R";
    vector<int> v;

    if(n==0) {
        next_num = 0;
    }else {
        while(n!=0){
            int c = n%10;
            v.push_back(c);
            n = n/10;
        }

        if( v.size() == 1 ) {
            next_num = v[0];
        } else {
            next_num += v[0] * pow(10,v.size()-1);
            for(int i=v.size()-1;i>=1;i--) {
                int digit = i-1;
                next_num += v[i] * pow(10,digit);
            }
        }
    }
    
    // cout << next_num << "," << next_s << endl;
    q.push(make_pair(next_num,next_s));
}

void clear() {
    // queue 비우기
    while(!q.empty()) {
        q.pop();
    }
    // 방문여부해제
    memset(visit,false,sizeof(visit));
}


void BFS() {
    
    while(!q.empty()) {
        int num = q.front().first;
        string route = q.front().second;
        q.pop();

        // q front의 숫자가 B와 같다면 문자열 출력후 리턴.
        if(num == B) {
            cout << route << endl;
            clear();
            return;
        }

        // q front의 숫자를 방문하지 않았다면 DSLR 시작.
        if(!visit[num]) {
            visit[num] = true;
            D(num,route);
            S(num,route);
            L(num,route);
            R(num,route);
        }
        
    }
    
    


}

void sol () {
    while(T--) {
        cin >> A >> B;
        // 큐에 넘겨받을 숫자와 만들어지는 문자열을 담아서 시작.
        q.push(make_pair(A,""));
        BFS();
    }
}

int main () {
    input();
    sol();
}