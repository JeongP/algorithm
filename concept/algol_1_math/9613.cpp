#include <iostream>
#include <vector>
using namespace std;

int main () {
    int t,n;
    vector<int> v;
    cin >> t;

    int max, min;
    



    while(t--) {
        cin >> n;
        long long sum = 0;
        for(int i=0; i<n;i++) {
            int x;
            cin >> x;
            v.push_back(x);
        }

        for(int i=0;i<n-1;i++) {
            for(int j=i+1;j<n;j++) {

                if(v[i]>=v[j]) {
                    max = v[i];
                    min = v[j];
                }else {
                    max = v[j];
                    min = v[i];

                }

                for(int k=min;k>=1;k--) {
                    if((min%k==0) && (max%k==0)) {
                        sum += k;
                        break;
                    }
                }
            }
        }
        cout << sum << endl;
        v.clear();
    }

}
