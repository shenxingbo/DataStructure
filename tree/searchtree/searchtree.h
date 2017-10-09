struct TreeNode;
typedef struct TreeNode * SearchTree;
typedef struct TreeNode *Position;
typedef int ElementType;
SearchTree MakeEmpy(SearchTree T);
Position Find(ElementType x, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(ElementType x, SearchTree T);
SearchTree Delete(ElementType x, SearchTree T);
ElementType Retrieve(Position p);  //返回p处的值 

struct TreeNode {
	ElementType value;
	SearchTree left;
	SearchTree right;
};
