// 7인일 떄 가정
#include <iostream>

using namespace std;

int parent[8];

void initial() {
    for(int i=1;i<8;i++) {
        parent[i] = i;
    }
}

int getParent(int p[], int x) {
    if(p[x]==x) return x;
    return getParent(p, p[x]);
}

int findParent(int p[], int a, int b) {
    a = getParent(p,a);
    b = getParent(p,b);
    if(a==b) return 1;
    else return 0;
}

void unionParent(int p[], int a, int b) {
    a = getParent(p, a);
    b = getParent(p, b);
    if(a < b) p[b] = a;
    else p[a] = b;
}



int main () {
    initial();
    unionParent(parent,1,3);
}