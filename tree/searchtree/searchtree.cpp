#include<iostream>
#include<stdlib.h>
using namespace std;

SearchTree Insert(ElementType x, SearchTree T) {
	
	if (T == NULL) {
		T = (SearchTree)malloc(sizeof(struct TreeNode));
		if (T == NULL) {
			cout << "申请空间失败";	
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
		cout << "找不到！！！"; 
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

Position FindMin(SearchTree T) {  //对于二叉树来说，最小值和最大值的位置是固定的，不用全局搜索 
	if (T == NULL) {
		return NULL;
	}
	if (T ->left == NULL) {
		return T;
	}else {
		return FindMin(T->left);  //别忘了这里的return  
	} 
	 
}

Position FindMax(SearchTree T) { //这个有点不好写 
	if (T != NULL) {
		while (T->right != NULL) {
			T = T->right;
		}
	}
	return T;
}


SearchTree MakeEmpty(SearchTree T) { //这个很好 
	if (T == NULL) {
		return NULL;
	}else{	
		MakeEmpty(T->left);
		MakeEmpty(T->right);
		cout << endl<< "值:  " <<  T->value;
		free(T);
	}
} 

ElementType Retrieve(Position p) { //函数的名字是检索的意思，整个函数是返回p处的值 
	return p->value; 
}

SearchTree Delete(ElementType x,SearchTree T) { //感觉这是最麻烦的一种操作 
	cout << "这是我自己定义大的"; 
	Position tempCell; 
	//判断树是否为空 
	if (T == NULL) {
		cout << "delete树为空！！！";
		exit(-1);
	}
	
	//开始进行查找
	if (T->value < x) {
		T->right = Delete (x, T->right);  //首先留意这里 
	}else if (T->value > x) {
		T->left = Delete (x, T->left);
	}else{
		//待删除的节点有两个儿子 
		
		if (T->left && T->right) {
			tempCell = FindMin(T->right);
			T->value = tempCell->value;        //这几行非常的好 
			T->right = Delete (T->value,T->right);
			
		}else { //被删除的节点只有一个儿子 
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


