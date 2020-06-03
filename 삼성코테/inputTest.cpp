
#include<iostream>
#include<vector>
#include <cstdio>
using namespace std;

vector<int> v;
int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	freopen("input.txt", "r", stdin);
	cin>>T;
    int cnt = 1;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{   
        int sum = 0;
        for(int i=0;i<10;i++) {
            int x; cin >> x;
            sum+= x;
            
        }
        cout << "#" << test_case << " " << sum << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}