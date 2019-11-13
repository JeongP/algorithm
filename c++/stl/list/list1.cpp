#include <iostream>
#include <list>

using namespace std;

int main() {

    list<int> lst;
    
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);

    for (list<int>::iterator itr = lst.begin(); itr != lst.end(); ++itr ) {
        cout << *itr << endl;
    }

    return 0;
}