#include <iostream>
#include <unistd.h>
#include <vector>
using namespace std;

int compute(int n);

int main() {
	// [!!주의!!] compute 함수는 이미 구현되어있지만, 숨김처리되어 있습니다. 호출해서 테스트 해주세요.
	
	// 중복이 있는 경우, 원래 썼던 값을 가져다 써라.
	int n;
	vector<int> v;
	vector<int> cmpV;
	vector<int> value;
	bool flag = false;
	
	do {
		cin >> n;
		v.push_back(n);
	}while(getc(stdin) == ' ');
	
	for(int i=0;i<v.size();i++) {
		for(int j=0;j<cmpV.size();j++) {
			if(cmpV[j] == v[i]) {
				cout << value[j] << " ";
				flag = true;
				break;
			}
		}
		
		if(flag) {
			flag = false;
			continue;
		}
		cout << compute(v[i]) << " ";
		cmpV.push_back(v[i]);
		value.push_back(compute(v[i]));
	}
	
	return 0;
}


TEST[2020 토스 NEXT] Server Developer - 1
[Server-1] 1은 2가 좋지만 2는 생각이 없다
[Server-2] 내가 주운 로또 복권이 가짜인가
[Server-3] 초고속 응답 함수
[Server-4] 단기 기억상실증
[Server-5] 김토스와 이토스
[Server-6] 토스 카페 바 테이블 둘레 구하기
[Server-7] 유효 데이터 복사하기
TEST[2020 토스 NEXT] Server Developer - 1
4 / 7
0:00:07
문제정보
문제정보
[Server-6] 토스 카페 바 테이블 둘레 구하기
2초
﻿﻿﻿﻿회사 14층에는 바리스타분 들이 직접 내려주시는 커피를 마실 수 있는 공간이 있다. 그 공간에 설치된 바 테이블의 둘레를 구하십시오. 



규칙


바 테이블의 영역, 입력은 0과 1로 이루어진 문자열로 구성된다.

0은 빈 공간, 1은 테이블이 있는 공간이다.

1과 1이 상하좌우 어디 방향으로든 연속적이면 그 두 영역은 연결된 영역으로 구분한다.

각 문자는 공백 한 칸으로, 각 한 줄은 세미콜론(;)로 구분된다.

입력 데이터가 n*m 일 때 모든 행은 동일한 길이를 가진다.


입력의 테이블은 하나의 연속된 테이블 정보를 나타내고 있다.

테이블의 둘레는 바깥 둘레 뿐만 아니라 안쪽 둘레까지 구해야 한다. 



0 0 0 0 0

0 1 1 1 0   


0 1 0 1 0  -> 둘레: 16

0 1 1 1 0

0 0 0 0 0



인풋 데이터의 최소 크기는 가로 3칸, 세로 3칸 이상이며 각 상하좌우 끝은 0으로 둘러싸여 있다고 가정한다.



0 0 0

0 1 0   ->   0 0 0;0 1 0;0 0 0; 

0 0 0





입/출력 예시
:
공백
:
줄바꿈
:
탭
예시 1
입력
0000;0110;0010;0000
출력
8
⋇ 입출력 형식을 잘 지켜주세요
C++
1
#include <iostream>
2
using namespace std;
3
int main() {
4
  
5
  return 0;
6
}
실행결과
제출결과
2020년 토스 NEXT 개발자 채용
6/7
