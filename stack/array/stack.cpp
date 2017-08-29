#include<iostream>
using namespace std;

Stack CreateStack(int maxElements){ //�������ָʾջ�ռ�Ĵ�С
	
	if (maxElements < MinStackSize) {
		cout << "����Ŀռ�̫С";
		exit(-1);	
	} 
	
	Stack s =  (Stack) malloc(sizeof(struct StackRecord));
	if (s == NULL) {
		cout << "�ռ�����ʧ��!!!";
		exit(-1); 	
	} 
	
	s->array = (ElementType*)malloc(sizeof(ElementType) * maxElements);
	if (s->array == NULL) {
		cout << "�ռ�����ʧ��!!!";
		exit(-1); 
	}
	s->capacity = maxElements;
 	MakeEmpty(s); 
	return s;
} 

void MakeEmpty(Stack s) {
	s->topOfStack = EmptyTOS; //ע��ջΪ�յ�ָʾ������0������-1 
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
		cout << "ջ�ռ䲻�㣡����";
		exit(-1);
	}
	
	s->array[++s->topOfStack] = x; 
}

ElementType Top(Stack s) {
	if (IsEmpty(s)) {
		cout << "ջΪ�գ�����";
	}else {
		return s->array[s->topOfStack];	
	}
} 

void Pop(Stack s) {
	if (IsEmpty(s)) {
		cout << "ջΪ�գ�����";
		exit(-1);
	}else {
		--s->topOfStack;	
	}
}

ElementType TopAndPop(Stack s) {
	if (IsEmpty(s)) {
		cout << "ջΪ�գ�����";
		exit(-1);
	}else {
		return s->array[s->topOfStack--];	
	}
}

