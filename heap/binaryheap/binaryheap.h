//二叉堆具有结构性和堆序性 
#ifndef _BinHeap_H 

typedef int ElementType;
struct HeapStruct;
typedef struct HeapStruct * PriorityQueue; //优先队列又叫做堆 
PriorityQueue Initialize(int MaxElements);
void Destroy(PriorityQueue H);
void MakeEmpty(PriorityQueue H);
void Insert(ElementType X, PriorityQueue H);
ElementType DeleteMin(PriorityQueue H);
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
int IsFull(PriorityQueue H);
#endif

struct HeapStruct {
	int capacity;
	int size;
	ElementType *elements;		
};
