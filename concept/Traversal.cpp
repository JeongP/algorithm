// 이진트리의 구현과 순회 방식
// 구조체와 포인터의 사용방법에 대한 습득.

#include <iostream>
using namespace std;

int num = 15;

typedef struct node *treePointer;
typedef struct node {
    int data;
    treePointer leftChild, rightChild;
}node;

void preOrder(treePointer ptr) {
    if(ptr) {
        cout << ptr->data << " ";
        preOrder(ptr->leftChild);
        preOrder(ptr->rightChild);
    }
}

void inOrder(treePointer ptr) {
    if(ptr) {
        inOrder(ptr->leftChild);
        cout << ptr->data << " ";
        inOrder(ptr->rightChild);
    }
}

void postOrder(treePointer ptr) {
    if(ptr) {
        postOrder(ptr->leftChild);
        postOrder(ptr->rightChild);
        cout << ptr->data << " ";
    }
}
int main () {
    node nodes[num+1];
    // 노드의 데이터 부분 초기화
    for(int i=1; i<=num; i++) {
        nodes[i].data = i;
        nodes[i].leftChild = NULL;
        nodes[i].rightChild = NULL;
    }
    // 차일드 부분 연결시켜주기
    for (int i=i; i<=num; i++) {
        if(i%2 == 0) {
            nodes[i/2].leftChild = &nodes[i];
        }else {
            nodes[i/2].rightChild = &nodes[i];
        }
    }
    
    preOrder(&nodes[1]);
    return 0;
}