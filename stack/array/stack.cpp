#include<iostream>
using namespace std;

Stack CreateStack(int maxElements){ //这个参数指示栈空间的大小
	
	if (maxElements < MinStackSize) {
		cout << "申请的空间太小";
		exit(-1);	
	} 
	
	Stack s =  (Stack) malloc(sizeof(struct StackRecord));
	if (s == NULL) {
		cout << "空间申请失败!!!";
		exit(-1); 	
	} 
	
	s->array = (ElementType*)malloc(sizeof(ElementType) * maxElements);
	if (s->array == NULL) {
		cout << "空间申请失败!!!";
		exit(-1); 
	}
	s->capacity = maxElements;
 	MakeEmpty(s); 
	return s;
} 

void MakeEmpty(Stack s) {
	s->topOfStack = EmptyTOS; //注意栈为空的指示并不是0，而是-1 
}


int IsFull(Stack s) {
	
	if (s->capacity == (s->topOfStack+1)){
		return 1;
	}else {
		return 0;
	}
}
int IsEmpty(Stack s) {
	if (s->capacity == -1) {
		return 1;
	}
	return 0;
}

void DisposeStack(Stack s) {
	if (s != NULL){
		free(s->array);
		free(s);
	} 
}

void Push(ElementType x, Stack s) {
	if (IsFull(s)) {
		cout << "栈空间不足！！！";
		exit(-1);
	}
	
	s->array[++s->topOfStack] = x; 
}

ElementType Top(Stack s) {
	if (IsEmpty(s)) {
		cout << "栈为空！！！";
	}else {
		return s->array[s->topOfStack];	
	}
} 

void Pop(Stack s) {
	if (IsEmpty(s)) {
		cout << "栈为空！！！";
		exit(-1);
	}else {
		--s->topOfStack;	
	}
}

ElementType TopAndPop(Stack s) {
	if (IsEmpty(s)) {
		cout << "栈为空！！！";
		exit(-1);
	}else {
		return s->array[s->topOfStack--];	
	}
}

