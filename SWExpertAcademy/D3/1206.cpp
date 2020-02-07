#include<iostream>
#include<algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int N;
        cin >> N;
        int arr[1000];
        int sum = 0;
        for(int i=0;i<N;i++) {
            cin >> arr[i];
        }

        for(int i=2;i<N-2;i++) {
            int maxBuilding = max(arr[i-2],max(arr[i-1],max(arr[i+1],arr[i+2])));
            if(maxBuilding < arr[i]) sum = sum + (arr[i] - maxBuilding);
        }

        cout << "#" << test_case << " " << sum << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}


/*
    sol1. map으로 진행하려 했으나, 2차원이라 너무 커서안됐나..?
        아마 입력값에 문제가 있어서 그랬을듯.. 
         

    sol2. 입력받은 각 건물의 높이를 양 옆 2개씩의 건물중 가장 높은 건물에서 빼서 그 값들만 더해주는 식으로 함.
 */