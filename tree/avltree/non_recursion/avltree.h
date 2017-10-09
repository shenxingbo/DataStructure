struct AvlNode;
typedef int ElementType;

struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;

AvlTree MakeEmpty(AvlTree T);
Position Find(ElementType x, AvlTree T);
Position FindMin(AvlTree T) ;
Position FindMax(AvlTree T);
AvlTree Insert(ElementType x, AvlTree T);
AvlTree Delete(ElementType x, AvlTree T);
ElementType Retrieve(Position p);

struct AvlNode {
	ElementType value;
	AvlTree left;
	AvlTree right;
	int height;   //这个是平衡二叉树独有的 
}; 
 
