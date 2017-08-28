
struct QueueRecord;
typedef struct QueueRecord *Queue;
typedef int ElementType ; 

int IsEmpty(Queue q);
int IsFull(Queue q);
Queue CreateQueue(int MaxElements); //ָʾ����ջ�����
void DisposeQueue(Queue q);
void MakeEmpty(Queue q);
void EnQueue(ElementType x,Queue q);
ElementType Front(Queue q);
void Dequeue(Queue q);
ElementType FrontAndDequeue(Queue q);

struct QueueRecord{
	int capacity;
	int front;
	int rear;
	int size;
	ElementType *array;
};




