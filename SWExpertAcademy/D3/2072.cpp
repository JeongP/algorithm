#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	int d[10] = {0,};
    int sum;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        sum = 0;
        for(int i=0;i<10;i++) {
            cin >> d[i];
        }
        
        for(int i=0;i<10;i++) {
            if(d[i]%2 != 0) {
                sum+=d[i];        
            }
        }

        cout << "#" << test_case << " " << sum << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}