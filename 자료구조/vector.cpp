#include <vector>
#include <iostream>

using namespace std;

int main () {
    vector<int> v1(6);
    vector<int> v2(6,5);
    vector<int> v3(v2); // 벡터 복사
    vector<int> v4;
    vector<int>::iterator it;

    // for(int i=0;i<v2.size();i++) {
    //     cout << v2[i] << " ";
    // }

    v4.push_back(1);v4.push_back(2);v4.push_back(3);
    
    v4.insert(v4.begin()+1, 5);
    // v4.erase(v4.begin() +1);

    
    for(int i=0;i<v4.size();i++) {
        cout << v4[i] << " ";
    }
    cout << endl;

    vector<int>::iterator iter;
    for(iter = v4.begin();iter!=v4.end();iter++) {
        cout << *iter << " ";
    }

    for(iter = v4.begin(); iter!=v4.end();iter++) {
        if(*iter == 3) {
            v4.erase(iter);
            break;
        }
    }

    for(iter = v4.begin();iter!=v4.end();iter++) {
        cout << *iter << " ";
    }
}