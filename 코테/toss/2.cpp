#include <iostream>
#include <vector>
using namespace std;
int main() {
	// 입력받고
    vector<int> v;
    int n;
    do {
        cin >> n;
        v.push_back(n);
    }while(getc(stdin) ==' ');

    cout << v.size() << endl;
    // 사이즈 여섯개인지
    // 숫자 범위내에 있는지
    // 오름차순인지
	return 0;
}