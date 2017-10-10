#include<iostream>
using namespace std; 
typedef int ElementType;

void InsertionSort(ElementType a[],int length) {
	int i = 0;
	int j = 0;
	ElementType temp = 0;
	
	for (i = 1; i < length; i++) {
		temp = a[i];
		for (j = i; j > 0 && temp < a[j-1]; j--) {
			a[j] = a[j-1];
		}
		a[j] = temp;
	}
} 


