#include<iostream>
#include<stdlib.h>
using namespace std; 

static int Height(Position p) {
	if (p == NULL) {
		return -1; //这里为什么是-1？ 
	}else {
		return p->height;
	}
}

static ElementType Max(ElementType a, ElementType b) {
	return a > b? a : b;
}

//这是在不平衡节点左子树的单旋转 
static Position SingleRotateWithLeft(Position k2) {
	Position k1;
	k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;
	
	k2->height = Max(Height(k2->left),Height(k2->right)) + 1;
	
	k1->height = Max(Height(k1->left),k2->height) + 1;
	
	return k1; 
} 

//这是在不平衡节点右子树的单旋转 

static Position SingleRotateWithRight(Position k1) {
	Position k2;
	k2 = k1->right;
	k1->right = k2->left;
	k2->left = k1;
	
	k1->height = Max(Height(k1->left),Height(k1->right)) + 1;
	
	k2->height = Max(Height(k2->left),k1->height) + 1;
	
	return k2; 
} 

//这是在不平衡节点左子树的双旋转
//双旋转首先要编程上面的两种情况之一 
static Position DoubleRotateWithLeft(Position k3) { //这个程序写的是在是精妙 
	k3->left = SingleRotateWithRight(k3->left);
	return SingleRotateWithLeft(k3); 
} 

//这是在不平衡节点左子树的双旋转
//双旋转首先要编程上面的两种情况之一 
static Position DoubleRotateWithRight(Position k2) { //这个程序写的是在是精妙 
	k2->right = SingleRotateWithLeft(k2->left);
	return SingleRotateWithRight(k2); 
} 



//这是在不平衡节点右子树的双旋转



//首先应该完成二叉树的创建insert操作
AvlTree Insert(ElementType x, AvlTree T) { 
	 
	if (T == NULL) {
		T = (AvlTree) malloc(sizeof(struct AvlNode));
		if (T == NULL) {
			cout << "Insert申请失败！！！"; 
			exit(-1);
		} 
		
		T->value = x;
		T->left = T->right = NULL;
		T->height = 0;  //这个是第一次修改其高度的值 
	}else if (x < T->value) {
			T->left = Insert(x, T->left);
			//当插入完成的时候，我们应该对插入完成后的树进行平衡处理
			if (Height(T->left) - Height(T->right) == 2) { //证明在不平衡节点的左子树上进行插入 
				if (x < T->left->value) { //判定是在不平衡节点的左子树上面插入的 
					T = SingleRotateWithLeft(T); 
				}else {
					T = DoubleRotateWithLeft(T);	
				}
			} 
		}else if (x > T->value) {
			T->right = Insert(x, T->right);
			
			if (Height(T->right) - Height(T->left) == 2) {
				if (x > T->right->value) {
					T = SingleRotateWithRight(T); 
				}else {
					T = DoubleRotateWithRight(T);	
				}
			}
	} 
	
	//下面更新高度信息,很重要 
	T->height = Max(Height(T->left),Height(T->right)) + 1;  
} 

AvlTree MakeEmpty(AvlTree T) {
	if (T == NULL) {
		return NULL;
	}else {
		MakeEmpty(T->left);
		MakeEmpty(T->right);
		cout <<"值为："<< T->value << endl;
		free(T);
	}
	
	
}
 
