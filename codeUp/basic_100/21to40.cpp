#include <iostream>
#include <string>
using namespace std;

int main() {

    // // 1021 - 공백없는 문자열.
    // sol 1
    // string s;
    // cin >> s;
    // cout << s << endl;

    // // sol 2  - %s로 입력 받게되면 마지막엔 null 값 자동 들어감.
    // char d[51];
    // scanf("%s", d);
    // printf("%s", d);


    // 1022 - 띄어쓰기 있는 문자열.
    
    // string s;
    // getline(cin, s); // cin.get(s);
    // cout << s << endl;

    // char chr[2100];
    // gets(chr);
    // printf("%s", chr);


    // 1023 - 실수 정수부 소수부 나누기
    // int a,b;
    // scanf("%d.%d", &a, &b);
    // printf("%d\n%d",a,b);

    // 1024 - 한 단어 철자별로 나눠서 출력하기.
    // char d[21];
    // scanf("%s", d);
    // for (int i=0; d[i]!='\0'; i++) {
    //     printf("\'%c\'\n", d[i]);
    // }

    /*
        배열에 연속된 문자를 저장하는 경우, 문자열의 마지막임을 알려주기 위해 마지막에 널 문자를 삽입해준다.
        단어나 문장을 scanf("%s", ...); 로 입력받게 되면, 그 마지막에 널문자가 자동으로 입력되는 것이다.
        마지막을 나타내는 널문자가 나올 때까지를 조건으로 하는 문제들이 종종 있음.
        printf("%s", ...); 는 널문자가 나올 때까지 출력해주라는 말.
     */

    // 1025 - 정수 자리수 별로 입력받고 출력
    // 입력을 한 자리씩 따로 저장하는 방법.
    // int a,b,c,d,e;
    // scanf("%1d%1d%1d%1d%1d",&a,&b,&c,&d,&e);

    // printf("[%d]\n", a * 10000);
    // printf("[%d]\n", b * 1000);
    // printf("[%d]\n", c * 100);
    // printf("[%d]\n", d * 10);
    // printf("[%d]\n", e * 1);

    // 1026 - 시분초
    // int h,m,s;
    // scanf("%d:%d:%d",&h,&m,&s);
    // printf("%d", m);

    // 1027 - 년월일
    // int a,b,c;
    // scanf("%d.%d.%d",&a,&b,&c);
    // printf("%02d-%02d-%04d", c,b,a);

    // 1029 - double 소수점 표현 방법.
    // double a;
    // scanf("%lf", &a);
    // printf("%.11lf", a); //소수점 아래 11자리수 표현

    // 1030 - long long int의 사용
    // long long int a;
    // scanf("%lld", &a);
    // printf("%lld",a);

    // 1031 ~ 1035- 진수변환
    // int a;
    // scanf("%d", &a);
    
    // printf("%o", a); // 8진수 출력
    // printf("%x",a); // 16진수 소문자 출력
    // printf("%X",a); // 16진수 대문자 출력

    // int b; 
    // scanf("%o", &b);
    // printf("%d", b);

    // 1036, 1037 - 아스키코드 와 10진수
    // char a;
    // scanf("%c", &a);
    // printf("%d", a);

    // int a;
    // scanf("%d", &a);
    // printf("%c", a);

    // 1039 - 정수 두개 입력 후 합 출력
    // int a,b;
    // scanf("%d %d", &a,&b);
    // printf("%lld", a+b);

    //1040 - 부호바꿔출력
    // int a;
    // scanf("%d", &a);
    // printf("%d", -a);



    return 0;
}