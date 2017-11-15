//注意这是解决的是单源最短路径
#include<iostream>
#define Infinity 10000
using namespace std;
const static int NumVertex = 7;
typedef int Vertex;

struct Node{
	bool Known;
	int Dis;
	int Pos;
};
struct Node T[NumVertex];
void unweigthted(int Graph[][NumVertex]);

int main() {
	int Graph[][NumVertex] = {	
		{0,1,0,1,0,0,0},
		{0,0,0,1,1,0,0},
		{1,0,0,0,0,1,0},
		{0,0,1,0,1,1,1},
		{0,0,0,0,0,0,1},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0}
	};
	
	for (int i = 0; i < NumVertex; i++) {
		T[i].Known = false;
		T[i].Dis = Infinity; //用来表示无穷	
		T[i].Pos = 0; 
	}	
	T[2].Dis = 0;
	T[2].Pos = 2; 
	unweigthted(Graph);	
	
	
} 

void unweigthted(int Graph[][NumVertex]) {
	int CurrDist;
		
	for (CurrDist = 0; CurrDist < NumVertex; CurrDist++) {
		for ( int i = 0; i < NumVertex; i++) {
			if (!T[i].Known && T[i].Dis == CurrDist) {
				T[i].Known = true;
				
				for (int j = 0; j < NumVertex; j++) {
					if (Graph[i][j] == 1) {
						if (T[j].Dis == Infinity) {
							T[j].Dis = CurrDist + 1;
							T[j].Pos = i; 
						}
					}
				} 
			}
		}
	} 
	
	for (int i = 0; i < NumVertex; i++) {
		cout << T[i].Pos << endl;
	}
} 
