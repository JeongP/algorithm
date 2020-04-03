#include <iostream>
using namespace std;

int main (){

    int a,b;
    int min, max;
    int gm, sm;
    cin >> a >> b;
    
    if(a>=b){
        min = b;
        max = a;
    } else {
        min = a;
        max = b;
    }

    // greatest division
    for(int i=min; i>=1; i--) {
        if((min%i==0) && (max%i==0)) {
            gm = i;
            break;
        }
    }
    // smallest? multiple
    for (int i=max; ;i++) {
        if((i%max==0) && (i%min==0)) {
            sm = i;
            break;
        }
    }
    
    cout << gm << endl << sm;
    


}
