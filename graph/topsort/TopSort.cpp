#include<iostream>
#include<stdlib.h>
#include<cstring>
using namespace std;
static const int NumVertex = 7; //��������� 
typedef  int Vertex; 
void TopSort(int Graph[][NumVertex], int Indegree[]); 
int* CalInDegree(int Graph[][NumVertex]);
Vertex FindNewIndegreeZero(int Indegree[]);


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
	//������ÿ����������
	int *Indegree = CalInDegree(Graph); 
	
	TopSort(Graph, Indegree);	
}


void TopSort(int Graph[][NumVertex], int Indegree[]) {
	int Counter;
	Vertex V, W;
	int flag = 0;
	int record[NumVertex];
	for (Counter = 0; Counter < NumVertex; Counter++) {
		V = FindNewIndegreeZero(Indegree);
		
		if (V == -1) {
			cout << "���ڻ�";
			return;
		} 
		record[flag++] = V+1;
		
		for (int z = 0; z < NumVertex; z++) {
			if (Graph[V][z] == 1) {
				--Indegree[z];
			}
		}
	} 
	
	for (int i = 0; i < NumVertex; i++) 
		cout << record[i] << "  ";
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

//�ҵ����Ϊ0�Ķ��� 
Vertex FindNewIndegreeZero(int Indegree[]) {
	for (int i = 0; i < NumVertex; i++) {
		if (Indegree[i] == 0) {
			Indegree[i] = -1; //֤���ýڵ��Ѿ����򣬽����޳����� 
			return i;
		}
	}
	return -1;
} 
