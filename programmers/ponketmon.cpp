#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
	int answer = 0;
    // 포켓몬 종류별로 담을 배열
	map<int,int> m;
    for(int i=0;i<nums.size();i++) {
        if(m.find(nums[i]) != m.end()) {
            m.insert(make_pair(nums[i],1));
        } else {
            m[nums[i]]++;
        }
    }
    
    
    answer = m.size();
    if(answer > nums.size()/2) {
        answer = nums.size()/2;
    } 
    return answer;
    
    
}