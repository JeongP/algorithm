#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int abs(int n) {
    if(n>=0) {
        return n;
    }else {
        return -n;
    }
}

int main () {
    int n;
    int result = 0;
    int Max_v;
    
    vector<int> v;
    deque<int> dq;
    int dq_front = 0; 
    int dq_back = 0;
    int dq_front_minus = 0; int dq_back_minus = 0;
    int front_max_index =0, back_max_index =0;
    cin >> n;
    
    int x;
    for(int i=0;i<n;i++) {
        cin >> x;
        v.push_back(x);
    }


    int max_index = 0;
    Max_v = v[0];
    for(int i=1;i<v.size();i++) {
        if(Max_v < v[i]) {
            Max_v = v[i];
            max_index = i;
        }
    }

    dq.push_back(Max_v);
    v.erase(v.begin()+max_index);

    while(!v.empty()) {
        dq_front = dq.front();
        dq_back = dq.back();

        //  돌면서 max 찾기.
        dq_front_minus = abs(dq_front - v[0]);
        front_max_index = 0;
        dq_back_minus = abs(dq_back - v[0]);
        back_max_index = 0;

        for(int i=1;i<v.size();i++) {
            if(dq_front_minus < abs(dq_front - v[i])) {
                dq_front_minus = abs(dq_front - v[i]);
                front_max_index = i;
            }

            if(dq_back_minus < abs(dq_back - v[i])) {
                dq_back_minus = abs(dq_back - v[i]);
                back_max_index = i;
            }
        }

        
        
        
        // 인덱스 추가 & 삭제
        if(dq_front_minus >= dq_back_minus) {
            dq.push_front(v[front_max_index]);
            v.erase(v.begin() + front_max_index);
        } else {
            int a = abs(dq_back_minus - dq_back);
            dq.push_back(v[back_max_index]);
            v.erase(v.begin() + back_max_index);
        }
        
    }

    // 합 구하기
    for(int i=0;i<dq.size()-1;i++) {
        result += abs(dq[i]-dq[i+1]);
        // cout << dq[i] << " ";
    }

    cout << result << endl;
}