#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void print_vector(vector<T>& vec) {
    for( typename vector<T>::iterator itr = vec.begin(); itr != vec.end(); ++itr ) {
        cout << *itr << endl;
    }
}

// const iterator 사용해보기. 
int main () {

    
    vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

    cout << "초기 vec 상태" << endl;
    print_vector(vec);

    vector<int>::iterator itr = vec.begin()+2;
    *itr = 50;

    cout << "변경된 vec 상태" << endl;
    
    for( vector<int>::iterator i = vec.begin(); i != vec.end(); ++i) {
        cout << *i << endl;
    }

    for ( vector<int>::size_type i=0; i < vec.size(); i++) {
        cout << vec[i] << endl;
    }

    vector<int>::const_iterator citr = vec.begin() + 2;

    // const_iterator가 가리키는 값은 변경시킬 수없다!!
    // *citr = 50; 

    // 이런식으로 값을 얻을 수도 있음.
    // vector<int>::const_iterator citr = vec.cbegin();


    return 0;
}