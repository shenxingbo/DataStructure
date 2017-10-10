#include<iostream>
#include<stdlib.h>
using namespace std;

List CreateHeader(){
	List L;
	L = (Position)malloc(sizeof(struct Node));
	L->next = NULL;
	return L;
}

List InitList(List L, ElementType value) {
	PtrToNode p,temp;
	p = L;
	while(p->next != NULL) {
		p = p->next;
	}
	temp = (PtrToNode) malloc(sizeof(struct Node));
	temp->value = value;
	temp->next = NULL;
	p->next = temp;
	return L;
}

void PrintList(List L) {
	Position p;
	p = L->next;
	while(p != NULL) {
		cout << p->value << endl;
		p = p->next;
	}
}

List MakeEmpty(List L) {
	return L->next = NULL; //短小精悍 
}

int IsEmpty(List L) {
	return L->next == NULL;
}

int IsLast(Position p,List L) { //就是检查p是否是最后一个节点 ,第二个参数没用 
	 return p->next == NULL; 
} 

Position Find(ElementType x, List L) {
	Position temp;
	temp = L->next;
	while (temp!=NULL && temp->value != x) 
		temp = temp->next;
	
	if (temp == NULL) {
		cout << "没找到"; 
		return temp;
	}else{
		return temp;
	}
}


void Delete(ElementType x, List L) {
	Position temp,temp2;
	temp = FindPrevious(x,L);
	temp2 = temp->next;
	temp->next = temp2->next;
	free(temp2);
}

Position FindPrevious(ElementType x, List L) {
	Position temp;
	temp = L;
	while (temp->next != NULL&&temp->next->value != x) 
		temp = temp->next;
	
	return temp;	
}

void Insert(ElementType x, List L,Position p){ //这个是在p之后插入元素 
	Position temp;
	temp = (Position)malloc (sizeof(struct Node));
	if (temp == NULL) {
		cout << "申请失败";
		exit(-1); 
	}
	temp->value = x;
	temp->next = p->next;
	p->next = temp; 
}

void DeleteList(List L) { //头指针是不用释放的 
	Position p,q;
	p = L->next;
	L->next = NULL;
	 
	while (p != NULL){
		q = p;
		p = p->next;
		free(q);
	}
}

Position Header(List L) {
	return L;
}

Position First(List L) {
	return L->next;
}

Position Advance(Position p) {
	return p->next;
}

ElementType Retrieve(Position p) {//检索取回数据 
	return p->value;
}


 


