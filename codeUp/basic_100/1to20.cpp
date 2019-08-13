#include <iostream>
#include <string>
using namespace std;

int main() {
    // 정수 두개 출력
    // int a,b;
    // scanf("%d %d", &a, &b);
    // printf("%d, %d", a, b);

    // 문자 두개 출력
    // char c,d;
    // scanf("%c %c", &c,&d);
    // printf("%c %c",d, c);

    //1015 - 소수점 이하 둘째 자리
    // float a;
    // scanf("%f", &a);
    // printf("%.2f", a);

    // 1017 - 세 번 출력
    // int a;
    // scanf("%d", &a);
    // printf("%d %d %d", a);

    // 1018 - 시간 입출력
    // 입력예시: 3:18
    // sol 1
    // string s;
    // cin >> s;
    // cout << s << endl;

    // // sol2
    // int h,m;
    // scanf("%d:%d",&h,&m);
    // printf("%d:%d", h,m);

    // // 1019 - 년월일 출력
    // int y,m,d;
    // scanf("%d.%d.%d",&y,&m,&d);
    // printf("%04d.%02d.%02d", y,m,d);

    // 1020 - 주민번호 출력
    int front,back;
    scanf("%d-%d",&front,&back);
    printf("%06d%07d",front,back);
    return 0;
}