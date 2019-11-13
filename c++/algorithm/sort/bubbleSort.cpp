#include <iostream>
#include <vector>

using namespace std;

template <typename T> 
void bubble_sort(vector<T>& data) {
    for (int i=0; i<data.size(); i++) {
        for(int j=0; j<data.size()-i; j++) {
            if(data[j] > data[j+1]) {
                T tmp = data[j];
                data[j] = data[j+1];
                data[j+1] = tmp;
            }
        }
    }
}


int main() {
    vector<int> vec = {1, 9, 8, 5, 4, 6, 7, 3, 2, 10};
    bubble_sort(vec);

    for ( int n : vec) {
        cout << n << " ";

    }
}