#include <iostream>
#include <set>

using namespace std;

template <typename T>
void print_set(set<T>& s) {

  // 셋의 모든 원소들을 출력하기
    cout << "[ ";
    for (typename set<T>::iterator itr = s.begin(); itr != s.end(); ++itr) {
        cout << *itr << " ";
    }
    cout << " ] " << endl;
}


// 셋의 기본적인 사용방법과, find의 사용방법.
int main() {

    set<int> s;
    s.insert(10);
    s.insert(50);
    s.insert(20);
    s.insert(40);
    s.insert(30);

    cout << "순서대로 정렬되어 나온다" << endl;
    print_set(s);

    cout << "20이 s의 원소인가요? :: ";
    auto itr = s.find(20);
    if(itr != s.end()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    cout << "25가 s의 원소인가요? :: ";
    itr = s.find(25);
    if( itr != s.end()) {
        cout << "yes" << endl;
    } else {
        cout << "NO" << endl;
    }
  

    return 0;
}