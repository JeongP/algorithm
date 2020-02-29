#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#define MAX 9
using namespace std;

int N,M;
int arr[MAX];
bool check[MAX];

vector<int> v;
set<string> visit;


void input() {
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        cin >> arr[i];
    }
    sort(arr, arr+N);
}

bool Duplicate() {
    string tmp = "";
    for(int i=0;i<v.size();i++) {
        char A = v[i] + '0';
        tmp = tmp + A;
    }
    if(visit.find(tmp) == visit.end()) {
        visit.insert(tmp);
        return false;
    }else {
        return true;
    }

}

void dfs (int depth) {
    if(depth == M) {
        if(Duplicate() == false) {
            for(int i=0;i<v.size();i++) {
                cout << v[i] << " ";
            }
            cout << endl;
        }
        return;
    }

    for(int i=0;i<N;i++) {
        if(!check[i]) {
            check[i] = true;
            v.push_back(arr[i]);
            dfs(depth+1);
            v.pop_back();
            check[i] = false;
        }
    }
}
void sol() {

    dfs(0);
}


int main () {
    input();
    sol();
}