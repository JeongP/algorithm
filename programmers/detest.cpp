#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
string arr[100020][4] = {"",};
int main () { 
    
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

