#include<iostream>
#include<stdlib.h> 
#define MinData (-1000)
#define MinQueue (5)
using namespace std;
PriorityQueue Initialize(int MaxElement) {
	PriorityQueue H;
	
	if (MaxElement < MinQueue) {
		cout << "申请的空间过小";
		exit(-1);
	} 
	
	H = (PriorityQueue) malloc(sizeof(struct HeapStruct));
	if (H == NULL) {
		cout << "空间申请失败";
		exit(-1);
	}
	
	H->elements = (ElementType *)malloc(sizeof(ElementType )* MaxElement);
	if (H->elements == NULL) {
		cout << "空间申请失败";
		exit(-1);
	}
	
	H->capacity = MaxElement;
	H->size = 0;
	H->elements[0] = MinData;  //这个的意义 
	return H;
}

void Insert(ElementType x, PriorityQueue H) {
	int i;
	if (IsFull(H)) {
		cout <<"堆空间已满";
		exit(0); 
	} 
	
	for ( i = ++H->size; H->elements[i/2] > x; i /= 2) {
		H->elements[i] = H->elements[i/2]; 
	}
	
	H->elements[i] = x;
	
	
}

int IsFull(PriorityQueue H){
	if (H->size == H->capacity) {
		//cout << "堆空间已满";
		return 1;
	}else {
		//cout << "空间未满";
		return 0;
	}
}

int IsEmpty(PriorityQueue H) {
	if (H->size == 0) {
		return 1;
	}else {
		return 0;
	}
} 
ElementType DeleteMin(PriorityQueue H){
	int i, child;
	ElementType minElement,lastElement;
	
	if (IsEmpty(H)) {
		cout << "堆的空间为0";
		exit(-1);	
	}
	
	minElement = H->elements[1];
	lastElement = H->elements[H->size--];
	
	for (i=1; i * 2 <= H->size; i = child) {
		child = 2 * i;
		//拿出左右儿子中最小的那个
		
		if (child != H->size && H->elements[child+1] < H->elements[child]) {
			child++ ;
		} 
		
		if (lastElement > H->elements[child]) {
			H->elements[i] = H->elements[child];
		}else {
			break;
		}
	}
	
	H->elements[i] = lastElement;
	return minElement;
}

void Destroy(PriorityQueue H){
	free(H->elements);
	free(H);
}

void MakeEmpty(PriorityQueue H){
	H->size = 0;
}

ElementType FindMin(PriorityQueue H) {
	if (H->size == 0) {
		cout << "栈为空";
		exit(-1);	
	}else {
		return H->elements[1];
	}
	
}

