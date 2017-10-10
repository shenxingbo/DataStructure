#include<iostream>
using namespace std;

//���㷨�ǳ��ƶ���ʱ�����ϵĵ�һ���㷨 
//����㷨��˼��ǳ��ĺ� 

typedef int ElementType;
void shellsort(ElementType arr[], int length) {
	int i = 0, j = 0, increment = 0;
	ElementType temp;
	//���ȿ������� 
	for (increment = length/2; increment > 0; increment = increment / 2){
		//������һ����������,��ϸ���������˼�� 
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


