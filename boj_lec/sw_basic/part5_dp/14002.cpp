/*

    수열을 담아줄 배열 arr
    각 수열을 마지막 원소로 하면서 증가하는 부분수열의 길이(n)와, 그 원소들(a)을 담아줄 배열 dp[n][a]; 
    각 원소들의 dp의 값이 이전원소들의 dp값보다 크다면, dp값을 바꿔주고 그 원소들도 가져와서 나열해준다.

 */


#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1001

int main () {
    int n;
    int arr[MAX] = {0,};
    int dp[MAX][MAX] = {0};

    // input
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
    }

    // solution
    int answer = 0;
    int ans_idx = 0;
    for(int i=1;i<=n;i++) {
        dp[i][0] = 1;
        dp[i][1] = arr[i];
        int tmp = dp[i][1];
        for(int j=1;j<i;j++) {

            if(arr[i]>arr[j]) {

                if(dp[i][0] < dp[j][0]+1) {
                    dp[i][0] = dp[j][0] + 1;
                    int idx = 0;
                    
                    for(int k=1;k<dp[i][0];k++) {
                        dp[i][k] = dp[j][k];
                        idx = k+1;
                    }
                    dp[i][idx] = tmp;
                }
            }

        }
        if(answer < dp[i][0]) {
            answer = dp[i][0];
            ans_idx = i;
        }
    }

    cout << answer << endl;
    for(int i=1;i<=answer;i++) {
        cout << dp[ans_idx][i] << " ";
    }

    

}