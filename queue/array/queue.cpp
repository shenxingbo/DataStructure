#include<iostream>
#include<stdlib.h>

using namespace std;
int IsEmpty(Queue q) { 
	return (q->size == 0);
} 

int IsFull(Queue q) {
	return (q->size == q->capacity);	
} 

void MakeEmpty(Queue q) {
	q->size  = 0;
	q->front = 1;
	q->rear = 0;
} 

Queue CreateQueue(int maxElements) { // maxElements 其实代表的是队列的大小 
	
	Queue q;
	
	if (maxElements < MinQueueSize){
		cout << "队列的空间过小";
		exit(-1); 
	}
	
	q = (Queue)malloc(sizeof(struct QueueRecord));
	
	if (q == NULL){
		cout << "队列头空间申请失败";
		exit(-1);
	}
	
	q->array = (ElementType*)malloc(sizeof(ElementType) * maxElements);
	
	if (q->array == NULL) {
		cout << "队列数组申请失败";	
		exit(-1);
	}	
	
	q->capacity = maxElements;
	
	MakeEmpty(q);
	return q;
}

void DisposeQueue(Queue q) {
	//首先要检查是否为空
	if (q != NULL) {
		free(q->array);
		free(q);	
	} 
}

static int Succ(int value, Queue q) {  //这个是移动指针，形成循环队列 
	if (++value == q->capacity) {
		value = 0;
	}
	
	return value;
}


void Enqueue(ElementType x, Queue q) { //这个不需要进行空栈的检查 
	
	if (IsFull(q)) {
		cout << "队列空间已满";
		exit(-1);
	}
	
	q->rear = Succ(q->rear,q);
	q->array[q->rear] = x;
	q->size++;
	
}



ElementType Front(Queue q) {
	if (IsEmpty(q)){
		cout << "队列为空";
	}
	return q->array[q->front];
} 

void Dequeue(Queue q) {
	
	if (IsEmpty(q)){
		cout << "队列为空";
		exit(-1);
	}
	
	Succ(q->front, q);
	q->size -- ;
	
}
 
ElementType FrontAndDequeue(Queue q) {
	ElementType temp;
	
	if (IsEmpty(q)){
		cout << "队列为空";
		exit(-1);
	}
	temp = q->array[q->front];
	Succ(q->front, q);
	q->size -- ;
	return temp;
}
