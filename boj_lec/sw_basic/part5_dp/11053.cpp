/*

    수열을 입력받은 배열과 각 수열을 마지막원소로 하여 '증가하는 부분수열의 길이'를 원소로 갖는 배열 필요(arr[], d[])
    d배열은 초기값이 모두 1일 것이고.
    각 수열원소들에 대해 이전 수열 값보다 큰 경우, 작은 수열 원소값의 d배열 값에 +1값과 현재 가지고 있는 값 중 큰 값을 넣어준다.
        => d[i] = max(d[i],d[j]+1)
    그리고 마지막엔 d[]의 값들 중에서 가장 큰 값을 뽑아낸다.
    
    ** 주의 **
    memset을 활용해 1로 초기화를 하게 되면 이상한 수가 들어가게 됨.
    memset은 1byte단위로 초기화를 하기 때문에 char 자료형의 경우에만 1로 초기화가 정상적으로 됨.
 */

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1001

int main () {
    int n;
    int arr[MAX] = {0,};
    int d[MAX];
    
    cin >> n;
    for(int i=1;i<=n;i++) {
        cin >> arr[i];
    }

    int answer = 0;
    for(int i=1;i<=n;i++) {
        d[i] = 1;
        for(int j=1;j<i;j++) {

            if(arr[i] > arr[j]) {
                d[i] = max(d[i],d[j]+1);
            }

        }
        
        answer = max(answer, d[i]);
    }

    cout << answer << endl;
    // cout << d[1] << endl;
    
}