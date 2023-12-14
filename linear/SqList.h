#define LIST_INIT_SIZE 80
#define LIST_INCREMENT 10

/**
 * ElemType是一个抽象概念，代表的是顺序表中数据的类型\n
 * 可以使用typedef自定义
 * */
#define ElemType char

/**
 * 顺序表
 * */
typedef struct SqList{
    ElemType *elem; // 存储空间基址
    int length; //当前长度
    int capacity; //当前分配的存储容量
} SqList;

void InitList(SqList &list);

/**
 * 在给定顺序表中查询第一个满足判定条件的数据元素\n
 * 若存在，则返回它的位置，否则返回0
 * */
int locateElem(SqList list, ElemType e);

/**
 * 在给定顺序表的第i个位置插入一个新元素e
 * */
bool listInsert(SqList &list, int i, ElemType e);

[[maybe_unused]] bool listDelete(SqList &list, int i);
void insertTail(SqList &list, ElemType e);

/**
 * 线性表la和lb中数据非递减有序排列，将la和lb合并成新的线性表。
 * */
void mergeSqList(SqList la, SqList lb, SqList &lc);

void sort(SqList &list);