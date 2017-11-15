#include<iostream>
#include<cstring>
#include"queue.h"
#include"queue.cpp"
static const int NumVertex = 7;
typedef int Vertex;
void TopSort(int G[][NumVertex], int Indegree[]);
int* CalInDegree(int Graph[][NumVertex]);
int main() {
		int Graph[][NumVertex] = {	
		{0,1,1,1,0,0,0},
		{0,0,0,1,1,0,0},
		{0,0,0,0,0,1,0},
		{0,0,1,0,0,1,1},
		{0,0,0,1,0,0,1},
		{0,0,0,0,0,0,0},
		{0,0,0,0,0,1,0}
	};
	int *Indegree = CalInDegree(Graph);
	TopSort(Graph, Indegree);
}


void TopSort(int G[][NumVertex], int Indegree[]) {
	Queue Q;
	int Counter = 0;
	Vertex V, W;
	//下面两个是个记录器 
	int record[NumVertex]; //防止存在环的情况,所以加100 
    int flag = 0;
	 
	Q = CreateQueue(NumVertex);
	MakeEmpty(Q);
	
	for (int i = 0; i < NumVertex; i++) {
		if (Indegree[i] == 0){
			Enqueue(i ,Q);
		}	
	}
	
	memset(record, 0, sizeof(int) * NumVertex);
	while(!IsEmpty(Q)) {
		V = FrontAndDequeue(Q);
		record[flag++] = V;
		for (int Z = 0; Z < NumVertex; Z++){
			if (G[V][Z] == 1) {
				if (--Indegree[Z] == 0) {
					Enqueue(Z, Q);
				}
			}
		} 
	}
	
	if (flag != NumVertex) {
		cout << "图中存在环";
		//return ;
	}
	
	for (int i = 0; i < NumVertex; i++) 
		cout << record[i]+1 << " ";
	
	DisposeQueue(Q); 
}

int* CalInDegree(int Graph[][NumVertex]) {
	int i, j;
	int* Indegree;
	Indegree = (int *) malloc(NumVertex * sizeof(int));
	memset(Indegree, 0, sizeof(int) * NumVertex);
	
	for (int i = 0; i < NumVertex; i++) {
		for (int  j = 0; j < NumVertex; j++) {
			if (Graph[i][j] == 1) {
				++Indegree[j]; 
			}
		}
	}
	
	return Indegree;
}


