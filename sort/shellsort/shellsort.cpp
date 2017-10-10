#include<iostream>
using namespace std;

//该算法是冲破二次时间屏障的第一批算法 
//这个算法的思想非常的好 

typedef int ElementType;
void shellsort(ElementType arr[], int length) {
	int i = 0, j = 0, increment = 0;
	ElementType temp;
	//首先控制增量 
	for (increment = length/2; increment > 0; increment = increment / 2){
		//下面是一个插入排序,仔细的理解这种思想 
		for (i = increment; i < length; i++) {
			temp = arr[i];
			for (j = i; j >= increment; j = j-increment){
				if (temp < arr[j-increment])
					arr[j] = arr[j-increment];
				else
					break;
			}
			arr[j] = temp;
		} 
	}
	 
}


