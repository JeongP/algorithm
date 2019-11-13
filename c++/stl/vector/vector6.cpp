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

// 범위 기반 for 문 (range based for loop)
int main() {

    vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

    for ( int elem : vec ) {
        cout << elem << endl;
    }
    
    return 0;
}