#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void print_vector(std::vector<T>& vec) {
  // 전체 벡터를 출력하기
  for (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end();
       ++itr) {
    std::cout << *itr << std::endl;
  }
}

// vector 역으로 출력하기
int main() {

    vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

    cout << "초기 vec 상태" << endl;
    print_vector(vec);

    cout << "역으로 vec 출력하기" << endl;
    vector<int>::reverse_iterator r_itr = vec.rbegin();

    for (; r_itr != vec.rend(); ++r_itr ) {
        cout << *r_itr << endl;
    }

    return 0;
}