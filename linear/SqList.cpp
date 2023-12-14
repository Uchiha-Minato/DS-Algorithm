#include<iostream>
#include "SqList.h"

using namespace std;

void InitList(SqList &list) {
    list.elem = (ElemType *) malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!list.elem)
        exit(-1);
    list.length = 0;
    list.capacity = LIST_INIT_SIZE;
}

int locateElem(SqList list, ElemType e) {
    ElemType *p = list.elem;
    int i = 1;

    do {
        if (*p != e) {
            p++;
            i++;
        } else break;
    } while (p <= &(list.elem[list.length - 1]));

    if (i > list.length)
        i = 0;

    return i;
}

bool listInsert(SqList &list, int i, ElemType e) {
    if ((i < 1) || (i > list.length + 1)) {
        cout << "current length is:" << list.length << ", i out of range" << endl;
        return false;
    } else {
        ElemType *q = &(list.elem[i - 1]);

        for (ElemType *p = &(list.elem[list.length - 1]); p >= q; --p) {
            *(p + 1) = *p;
        }
        *q = e;
        ++list.length;
        return true;
    }
}

bool listDelete(SqList &list, int i) {
    if (i < 1 || i > list.length) {
        cout << "i out of range" << endl;
        return false;
    }
    ElemType *p = &(list.elem[i - 1]); //第i个位置的元素地址
    ElemType *q = list.elem + list.length - 1; //队尾元素地址
    for (++p; p <= q; ++p)
        *(--p) = *p;
    --list.length;
    return true;
}

void insertTail(SqList &list, ElemType e) {
    ElemType *p = &(list.elem[list.length - 1]);
    *(++p) = e;
    list.length++;
}

void mergeSqList(SqList la, SqList lb, SqList &lc) {
    ElemType *pa = la.elem, *pb = lb.elem;
    lc.capacity = lc.length = la.length + lb.length;
    ElemType *pc = lc.elem = (ElemType *) malloc(lc.capacity * sizeof(ElemType));
    if (!lc.elem)
        exit(-1);

    ElemType *pa_last = la.elem + la.length - 1;
    ElemType *pb_last = lb.elem + lb.length - 1;
    while (pa <= pa_last && pb <= pb_last) {
        if (*pa < *pb)
            *pc++ = *pa++;
        else
            *pc++ = *pb++;
    }

    while (pa <= pb_last) {
        *pc++ = *pa++;
    }
    while (pb <= pb_last) {
        *pc++ = *pb++;
    }
}

int cmp(const void *a,const void *b) {
    return *(int*)a-*(int*)b;
}
void sort(SqList &list) {
    int arr[] = {};
    ElemType *p = list.elem;
    int *q = arr;
    int length = 0;
    for (p++; p < &(list.elem[list.length]); p++) {
        *q++ = int(*p++);
        length++;
    }
    q = arr;
    p = list.elem;
    qsort(arr, length, sizeof(int), cmp);
    for (p++; p < &(list.elem[list.length]); p++) {
        *p++ = char(*q++);
    }
}

int main() {
    SqList sqList;
    InitList(sqList);
    cout << &sqList << "\t sizeof SqList:" << sizeof(sqList) << endl;

    ElemType a = 'a';
    insertTail(sqList, a);
    insertTail(sqList, 'b');
    insertTail(sqList, 'c');
    insertTail(sqList, 'c');
    listInsert(sqList, 2, 'f');
    listInsert(sqList, 2, 'f');
    listInsert(sqList, sqList.length + 2, 'd');
    for (char *i = sqList.elem; i < &(sqList.elem[sqList.length]); i++) {
        cout << *i << " ";
    }
    cout << locateElem(sqList, 'g') << endl;

    SqList sqList1;
    InitList(sqList1);
    SqList sqList2;
    InitList(sqList2);

    insertTail(sqList1, 'a');
    insertTail(sqList1, 'b');
    insertTail(sqList1, 'c');
    insertTail(sqList1, 'v');
    insertTail(sqList1, 'w');
    mergeSqList(sqList, sqList1, sqList2);
    for (char *i = sqList2.elem; i < &(sqList2.elem[sqList2.length]); i++) {
        cout << *i << " ";
    }

    return 0;
}