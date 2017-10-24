#include<iostream>
using namespace std;
void Initilialize(DisjSet S) {
	int i;
	
	for (i = NumSets; i > 0; i--) 
		S[i] = -1; // Õâ¸öÊ÷µÄsize 
}

SetType Find(ElementType X, DisjSet S) {
	if (S[X] < 0) {
		return X;
	}else {
		Find(S[X], S);
	}
}


void SetUnion(DisjSet S, SetType Root1, SetType Root2) {
	int Size;
	if (S[Root1] <= S[Root2]) {
		Size = S[Root2];
		S[Root2] = Root1;
		S[Root1] = S[Root1] + Size;
	}else {
		Size = S[Root1];
		S[Root1] = Root2;
		S[Root2] = S[Root2] + Size;
	}
}


