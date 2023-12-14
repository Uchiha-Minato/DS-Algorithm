#include "LinkedList.h"
#include <iostream>

Node::Node(int val) {
    this->val = val;
    this->next = nullptr;
}

LinkedList initList(LinkedList &L) {
    L = (LinkedList) malloc(sizeof(Node));
    L->next = nullptr;
    return L;
}

int getLength(LinkedList L) {
    int i = 0;
    do {
        L = L-> next;
        i++;
    } while(L);
    return i;
}

void putElemOnTail(LinkedList &L, Node *e) {
    L->next = e;
}

int main() {
    LinkedList list;
    initList(list);
    std::cout << list->next << std::endl;

    Node node = *new Node(0);
    putElemOnTail(list, &node);
    std::cout << getLength(list) << std::endl;

    int *p = reinterpret_cast<int *>(&node);
    printf("%d", p);
}

