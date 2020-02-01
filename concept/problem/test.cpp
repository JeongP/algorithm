#include <iostream>

using namespace std;

int main () {
    
    int a[3] = {1,2,3};
    int b[3] = {1,2,5};

    int s = 99;
    

    int mask;
    for(int i=31;i>=0;i--) {
        mask = 1<<i;
        printf("%d", mask & s ? 1:0);

        if(i%8==0) cout << " ";
    }


    return 0;
}