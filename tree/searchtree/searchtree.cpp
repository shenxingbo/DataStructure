#include<iostream>
#include<stdlib.h>
using namespace std;

SearchTree Insert(ElementType x, SearchTree T) {
	
	if (T == NULL) {
		T = (SearchTree)malloc(sizeof(struct TreeNode));
		if (T == NULL) {
			cout << "����ռ�ʧ��";	
			exit(-1);
		}
		
		T->value = x;
		T->left = T->right = NULL;
	}else {
		if (T->value > x) {
			T->left = Insert(x, T->left);
		}else if(x > T->value) {
			T->right = Insert(x, T->right);
		}
	}
	return T;
} 

Position Find(ElementType x, SearchTree T){
	if (T == NULL) {
		cout << "�Ҳ���������"; 
	}else {
		if (x == T->value) {
			return T;
		}else if (x < T->value) {
			Find(x, T->left);
		}else {
			Find(x, T->right);	
		}
	}
}

Position FindMin(SearchTree T) {  //���ڶ�������˵����Сֵ�����ֵ��λ���ǹ̶��ģ�����ȫ������ 
	if (T == NULL) {
		return NULL;
	}
	if (T ->left == NULL) {
		return T;
	}else {
		return FindMin(T->left);  //�����������return  
	} 
	 
}

Position FindMax(SearchTree T) { //����е㲻��д 
	if (T != NULL) {
		while (T->right != NULL) {
			T = T->right;
		}
	}
	return T;
}


SearchTree MakeEmpty(SearchTree T) { //����ܺ� 
	if (T == NULL) {
		return NULL;
	}else{	
		MakeEmpty(T->left);
		MakeEmpty(T->right);
		cout << endl<< "ֵ:  " <<  T->value;
		free(T);
	}
} 

ElementType Retrieve(Position p) { //�����������Ǽ�������˼�����������Ƿ���p����ֵ 
	return p->value; 
}

SearchTree Delete(ElementType x,SearchTree T) { //�о��������鷳��һ�ֲ��� 
	cout << "�������Լ�������"; 
	Position tempCell; 
	//�ж����Ƿ�Ϊ�� 
	if (T == NULL) {
		cout << "delete��Ϊ�գ�����";
		exit(-1);
	}
	
	//��ʼ���в���
	if (T->value < x) {
		T->right = Delete (x, T->right);  //������������ 
	}else if (T->value > x) {
		T->left = Delete (x, T->left);
	}else{
		//��ɾ���Ľڵ����������� 
		
		if (T->left && T->right) {
			tempCell = FindMin(T->right);
			T->value = tempCell->value;        //�⼸�зǳ��ĺ� 
			T->right = Delete (T->value,T->right);
			
		}else { //��ɾ���Ľڵ�ֻ��һ������ 
			if (T->left == NULL) {
				tempCell  = T;
				T = T->right;
			}else if (T->right == NULL){
				tempCell  = T;
				T = T->left;
			}
			free(tempCell); 
		}	
	} 
	return T;
}


