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

Queue CreateQueue(int maxElements) { // maxElements ��ʵ������Ƕ��еĴ�С 
	
	Queue q;
	
	if (maxElements < MinQueueSize){
		cout << "���еĿռ��С";
		exit(-1); 
	}
	
	q = (Queue)malloc(sizeof(struct QueueRecord));
	
	if (q == NULL){
		cout << "����ͷ�ռ�����ʧ��";
		exit(-1);
	}
	
	q->array = (ElementType*)malloc(sizeof(ElementType) * maxElements);
	
	if (q->array == NULL) {
		cout << "������������ʧ��";	
		exit(-1);
	}	
	
	q->capacity = maxElements;
	
	MakeEmpty(q);
	return q;
}

void DisposeQueue(Queue q) {
	//����Ҫ����Ƿ�Ϊ��
	if (q != NULL) {
		free(q->array);
		free(q);	
	} 
}

static int Succ(int value, Queue q) {  //������ƶ�ָ�룬�γ�ѭ������ 
	if (++value == q->capacity) {
		value = 0;
	}
	
	return value;
}


void Enqueue(ElementType x, Queue q) { //�������Ҫ���п�ջ�ļ�� 
	
	if (IsFull(q)) {
		cout << "���пռ�����";
		exit(-1);
	}
	
	q->rear = Succ(q->rear,q);
	q->array[q->rear] = x;
	q->size++;
	
}



ElementType Front(Queue q) {
	if (IsEmpty(q)){
		cout << "����Ϊ��";
	}
	return q->array[q->front];
} 

void Dequeue(Queue q) {
	
	if (IsEmpty(q)){
		cout << "����Ϊ��";
		exit(-1);
	}
	
	Succ(q->front, q);
	q->size -- ;
	
}
 
ElementType FrontAndDequeue(Queue q) {
	ElementType temp;
	
	if (IsEmpty(q)){
		cout << "����Ϊ��";
		exit(-1);
	}
	temp = q->array[q->front];
	Succ(q->front, q);
	q->size -- ;
	return temp;
}
