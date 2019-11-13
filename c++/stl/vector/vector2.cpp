#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void print_vector(vector<T>& vec) {
  // 전체 벡터를 출력하기
  for (typename vector<T>::iterator itr = vec.begin(); itr != vec.end();
       ++itr) {
    cout << *itr << endl;
  }
}

int main () {

    // 반복자를 이용하여 insert 와 erase 사용해보기.
    // erase와 insert는 반복자를 인자로 받는다.

    vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

    cout << "처음 벡터 상태" << endl;
    print_vector(vec);
    cout << "----------------------------" << endl;

    // vec[2] 앞에 15 추가
    vec.insert(vec.begin() + 2, 15);
    print_vector(vec);

    cout << "----------------------------" << endl;
    // vec[3] 제거
    vec.erase(vec.begin() + 3);
    print_vector(vec);

    return 0;
}