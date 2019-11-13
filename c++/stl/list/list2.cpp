#include <iostream>
#include <list>

using namespace std;

template <typename T>
void print_list(list<T>& lst) {
    cout << "[";
    for(const auto& elem : lst) {
        cout << elem << " ";
    }
    cout << "]" << endl;
}

// list 원소 삽입, 제거
int main() {

    list<int> lst;
    
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);

    cout << "처음 리스트의 상태 " << endl;
    print_list(lst);

    // 값 50인 원소 추가
    for (list<int>::iterator itr = lst.begin(); itr != lst.end(); itr++ ) {
        if(*itr == 20) {
            lst.insert(itr, 50);
        }
    } 

    cout << "값이 20인 원소 앞에 50인 원소 추가" << endl;
    print_list(lst);

    // 값 30인 원소 삭제
    for (list<int>::iterator itr = lst.begin(); itr !=lst.end(); itr ++) {
        if(*itr == 30) {
            lst.erase(itr);
            break;
        }
    }


    cout << "값이 30인 원소를 제거" << endl;
    print_list(lst);

    return 0;
}