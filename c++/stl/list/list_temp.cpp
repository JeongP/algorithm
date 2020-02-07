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

int main() {

    list<int> lst;
    
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);


    return 0;
}