#include <iostream>
#include <string>
using namespace std;
int main() {
	string s;
	cin >> s;
	
	int last = s.length()-1;
	// 마지막 문자에 대한 체크
	if(s[last] == 1) {
		return false;
	}
	
	for(int i=0;i<s.length()-1;i++) {
		if(s[i] == '1') {
			if(s[i+1] != '1') return false;
		} 
	}
	
	return true;
    return 0;
}