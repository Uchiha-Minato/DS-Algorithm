/**
 * 链表
 * */
typedef struct Node{
    int val;
    struct Node *next;
    explicit Node(int val);
}Node, *LinkedList;

LinkedList initList(LinkedList &L);
void destroyList(LinkedList &L);

int getLength(LinkedList L);
Node priorElem(LinkedList L, Node cur_e, Node &pre_e);
Node nextElem(LinkedList L, Node cur_e, Node &next_e);
Node getElem(LinkedList L, int i, Node &e);
void clearList(LinkedList &L);
void putElem(LinkedList &L, int i, Node &e);
void insertElem(LinkedList &L, int i, Node e);
void deleteElem(LinkedList &L, int i, Node &e);
void putElemOnTail(LinkedList &L, Node *e);