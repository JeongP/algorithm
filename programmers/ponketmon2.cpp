#include <vector>
#include <iostream>

using namespace std;
#define MAX 200001

int solution(vector<int> nums)
{
    int visit[MAX] = {0, };
    vector<int> v;
    for(int i = 0; i < nums.size(); i++)
        visit[nums[i]]++;   // 몇마리 == 몇번visit
    for(int i = 1; i <= MAX; i++)
        if(visit[i] > 0)
            v.push_back(visit[i]);  // 있는 종류는 모두 push
    
    if(nums.size() / 2 > v.size())  // case : 종류가 적은 경우
        return v.size();
    else
        return nums.size() / 2;
}