#include <iostream>
using namespace std;

int main () {
    // 1061
    int a,b;
    scanf("%d %d", &a,&b);
    printf("%d", a^b);

    // 1062
    int a,b;
    scanf("%d %d", &a,&b);
    printf("%d", a|b);

    // 1063
    int a,b;
    scanf("%d %d", &a,&b);
    printf("%d", a>b ? a:b);

    // 1064
    int a,b,c;
    scanf("%d %d %d", &a,&b,&c);
    printf("%d\n", ((a<b?a:b) < c) ? (a<b?a:b):c);
    
    // 1065
    int a,b,c;
    scanf("%d %d %d", &a,&b,&c);
    
    if (a%2 == 0) printf("%d\n",a);
    if (b%2 == 0) printf("%d\n",b);
    if (c%2 == 0) printf("%d\n",c);
    
    // 1066
    int a[3];
    scanf("%d %d %d", &a[0],&a[1],&a[2]);
    
    for (int i=0; i<3; i++) {
        if(a[i]%2==0) printf("even\n");
        else printf("odd\n");
    }

    // 1067 +/-/양/음 분석
    int a;
    scanf("%d", &a);
    
    if(a>0) {
        if(a%2==0) {
            printf("plus\neven");
        }else {
            printf("plus\nodd");
        }
    } else {
        if(a%2==0) {
            printf("minus\neven");
        }else{
            printf("minus\nodd");
        }
    }

    // 1068 학점 부여
    int a;
    scanf("%d", &a);
    
    if(a>=90) {
        printf("A");
    }else if (a>=70) {
        printf("B");
    }else if (a>=40) {
        printf("C");
    }else {
        printf("D");
    }

    // 1069
    char a;
    scanf("%c",&a);

    switch(a)
    {
        case 'A': printf("best!!!"); break;
        case 'B': printf("good!!"); break;
        case 'C': printf("run!"); break;
        case 'D': printf("slowly~"); break;
        default: printf("what?");
    }

    switch(a) {
        case 'A': cout << "best!!!" << endl; break;
        case 'B': cout << "good!!"<< endl; break;
        case 'C': cout << "run!" << endl; break;
        case 'D': cout << "slowly~" << endl; break;
        default: cout << "what?" << endl; break;
    }

    // 1070
    int a;
    scanf("%d",&a);

    switch(a)
    {
        case 12: case 1: case 2: printf("winter");break;
        case 3: case 4: case 5: printf("spring");break;
        case 6: case 7: case 8: printf("summer");break;
        case 9: case 10: case 11: printf("fall");break;
    }

    // 1071: 원하는 숫자 나올때까지 출력

    while (1) {
        int n;
        scanf("%d", &n);
        if(n==0) {
            printf("%d\n", n); break;
        }else {
            printf("%d\n", n);
        }   
    }

    // goto문 사용
    goto_test:
    int n;
    scanf("%d", &n);
    printf("%d\n",n);
    if(n!=0) goto goto_test;

    // 1072: 동적으로 입력받ㄷ고 출력하기

    int n;
    scanf("%d", &n);
    int a[n];
    
    for (int i=0; i<n; i++) {
        scanf("%d ", &a[i]);
    }
    
    for (int i=0; i<n; i++) {
        printf("%d\n", a[i]);
    }

    // 1073 
    int a;    
    while(1) {
        scanf("%d", &a);
        printf("%d\n", a);
        if(a==0) break;
    }

    // 1074 
    int n;
    scanf("%d", &n);
    
    for (int i=n; i>0; i--) {
        printf("%d\n", n);
        n--;
    }

    // 1075
    int n;
    scanf("%d", &n);
    
    for (; n-1>=0; n--) {
        printf("%d\n", n-1);
    }
    
    // 1076
    char a, b='a';
    scanf("%c", &a);
    
    do {
        printf("%c ", b);
        b++;
    }while(b<=a);

    // 1077
    int a;
    scanf("%d", &a);
    
    for (int i=0; i<=a; i++ ) {
        printf("%d\n", i);
    }

    
    
    
}