struct Node;
typedef int ElementType;
typedef struct Node *PtrToNode;

typedef PtrToNode List; //头指针 

typedef PtrToNode Position;  //指向下一个位置的指针 

List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position p, List L);
Position Find(ElementType x, List L);
void Delete(ElementType x, List L);
Position FindPrevious(ElementType x,List L);
void Insert(ElementType x, List L, Position p);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position p);
ElementType Retrieve(Position p); // 取回某个位置上的值 

//自己加入的函数 
List CreateHeader(); 
List InitList(List L, ElementType value);
void PrintList(List L);
 
struct Node {
	ElementType value;
	Position next;	
};


