#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;

int N,M,K;
int a[101][101] = {0,};
int tree[101][101] = {0,};
vector<pair<pair<int,int>,int>> v;
vector<pair<int,int>> iv;
int result = 0;

void input() {
    cin >> N >> M >> K;

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> a[i][j];
        }
    }

    for(int i=0;i<M;i++) {
        int x,y,z;
        cin >> y >> x >> z;
        v.push_back(make_pair(make_pair(y,x),z));
        tree[y][x]++;
    }
}

void prt() {
    for(int i=0;i<iv.size();i++) {
        cout << iv[i].first << " ";
    }
}

void spring() {
    // 하나의 칸에 나무의 개수가 여러개인 곳 chk
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(tree[i][j] > 1) {
                for(int k=0;k<v.size();k++) {
                    int y = v[k].first.first;
                    int x = v[k].first.second;
                    int age = v[k].second;
                    if(i == y && j == x) {
                        iv.push_back(make_pair(age,k));
                    }
                }
                sort(iv.begin(),iv.end());
            }
        }
    }
    // 2 이상인 경우
        // 그 좌표에 있는 나무들 나이 비교
    // 아닌 경우
        // 양분 섭취.
    
}
int main(int argc, char** argv)
{
	// int test_case;
	// int T;
	
	// freopen("input.txt", "r", stdin);
	// cin>>T;
    
	// for(test_case = 1; test_case <= T; ++test_case)
	// {   

	// }
    
    input();
    while(K--) {
        spring();
        // summer();
        // fall();
        // winter();
    }
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}