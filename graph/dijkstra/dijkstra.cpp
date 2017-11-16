#include<iostream> 
#include<cstring>
#define NotAvertex (-1)
#define NumVertex (7) 
#define Infinity 10000 
using namespace std;
typedef int Vertex;
typedef struct TableEntry Table[NumVertex];
struct TableEntry {
	int Known;
	int Dist;
	Vertex Path;
};


void InitTable(Vertex start, int Graph[][NumVertex], Table T);
Vertex getShortestDis(Table T); 
void Dijkstra(Table T, int G[][NumVertex]);
void PrintPath(Vertex V, Table T); 
int main() {
	Table T;
	int Graph[][NumVertex] = {	
		{0,2,0,1,0,0,0},
		{0,0,0,3,10,0,0},
		{4,0,0,0,0,5,0},
		{0,0,2,0,2,8,4},
		{0,0,0,0,0,0,6},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0}
	};
	
	InitTable(0, Graph, T);
	Dijkstra(T, Graph);
	
	//��ӡ����Դ�㵽ÿ��������·��   
	for(int i = 0; i < NumVertex; i++) {
		PrintPath(i, T);
		cout << endl;
	}
	
}


void InitTable(Vertex start, int G[][NumVertex], Table T) {
	
	for (int i = 0; i < NumVertex; i++) {
		T[i].Known = false;
		T[i].Dist = Infinity;
		T[i].Path = NotAvertex;
	}
	
	T[start].Dist = 0;
}

//�������д����ʵ̫���� 
void PrintPath(Vertex V, Table T) {
	if (T[V].Path != NotAvertex) {
		PrintPath(T[V].Path, T);
		cout << "to "; 
	}
	
	cout << V+1 << " ";
} 

//��known��false�����Ҵ���С�Ľڵ� 
void Dijkstra(Table T, int G[][NumVertex]) {
	Vertex V, W;
	for (;;){
		V = getShortestDis(T);
		if (V == NotAvertex) 
			break;
		
		T[V].Known = true;
		for (int i = 0; i < NumVertex; i++) {
			if (G[V][i] != 0){
				if (!T[i].Known) {
					if (T[V].Dist + G[V][i] < T[i].Dist) {
						T[i].Dist = T[V].Dist + G[V][i];
						T[i].Path = V; 
					}
				} 
			}
		}
	}
	
}

Vertex getShortestDis(Table T) {
	Vertex min = Infinity;
	bool flag = false;
	for (int i = 0; i < NumVertex; i++) {
		if (T[i].Known == false && T[i].Dist < min) {
			flag = true;
			min = i;
		}
	}
	
	if (flag) {
		return min; //���еĽڵ㶼�ѱ����� 
	}else {
		return -1;
	} 
}

