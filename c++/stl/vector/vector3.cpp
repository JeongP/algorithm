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

  // erase로 원소 올바르게 삭제하기.


  vector<int> vec;
  vec.push_back(10);
  vec.push_back(20);
  vec.push_back(30);
  vec.push_back(40);
  vec.push_back(20);

  cout << "처음 벡터 상태" << endl;
  print_vector(vec);

  vector<int>::iterator itr = vec.begin();
  vector<int>::iterator end_itr = vec.end();

  // 잘못된 방법
  /* 
  for (; itr != end_itr; ++itr) {
    if (*itr == 20) {
      vec.erase(itr);  // 이렇게 되면 itr은 유효한 반복자가 아니게 됨.
    }
  }
  */

  // sol 1 - 20을 지우고, 다시 처음으로 돌아가서 원소를 찾게 되서 비효율적
  /* 
  for (; itr != vec.end(); ++itr ) {
    if(*itr == 20) {
      vec.erase(itr);
      itr = vec.begin();
    }
  }
  */

  // sol 2 
  for ( vector<int>::size_type i=0; i != vec.size(); i++ ) {
    if(vec[i] == 20) {
      vec.erase(vec.begin()+i);
      i--; // 벡터는 erase하는 순간 뒤의 요소들이 자동으로 앞으로 당겨지기 때문에.
    }
  }

  cout << "값이 20인 원소를 지운다" << endl;
  print_vector(vec);


  return 0;
}