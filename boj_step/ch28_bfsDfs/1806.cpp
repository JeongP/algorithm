#include <iostream>
#include <cstdio>
#include <algorithm>
 
#define MAX_N 100001
using namespace std;
 
int arr[MAX_N];
int pSum[MAX_N];
 
int main()
{
    int n, s, minLen = MAX_N, len = 0;
    int p1 = 1, p2 = 1;
 
    scanf("%d %d", &n, &s);
 
    // pSum은 구간 1~i까지의 합을 나타내준다.
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
 
        pSum[i] = pSum[i - 1] + arr[i];
    }
 
    
    while (!(n == p1 && p1 == p2))
    {
        
        if (pSum[p2] - pSum[p1-1] >= s)
        {
            
            len = p2 - p1 + 1;
            if (minLen > len)
                minLen = len;
 
            p1++;
        }
 
        // p1~p2까지의 합이 s보다 작으면
        else if (pSum[p2] - pSum[p1 - 1] < s)
        {

            if (p2 < n)
                p2++;
            else
                p1++;
        }
 
    }
 

    if (minLen == MAX_N)
        cout << "0";
    else
        cout << minLen;
 
    return 0;
}
