#include <iostream>
#include <vector>
using namespace std;

int main () {

    // vector의 기본 사용방법.
  
    vector<int> vec;
    vec.push_back(10);  // 맨 뒤에 10 추가
    vec.push_back(20);  // 맨 뒤에 20 추가
    vec.push_back(30);  // 맨 뒤에 30 추가
    vec.push_back(40);  // 맨 뒤에 40 추가

    // size의 리턴 값은 size_type을 자료형으로 가짐.
    for (vector<int>::size_type i = 0; i < vec.size(); i++) {
        cout << "vec 의 " << i + 1 << " 번째 원소 :: " << vec[i] << endl;
    }
        
    
    int count = 1;
    
    // iterator 사용 전체 벡터를 출력하기
    for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
        cout << *itr << endl;
    }

    vector<int>::iterator itr = vec.begin() +2;
    cout << "3번째원소 :: " << *itr << endl;

    return 0;

}