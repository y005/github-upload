#include<stdio.h>

void insertsort(int list[],int n);

int main(void){
	
	int i;
	int arr[9] = {7,13,87,65,45,36,68,47,34};
	
	insertsort(arr,9);
	
	for(i=0;i<9;i++){
		printf("%d ",arr[i]);		
	}

	system("pause");
	return 0;
}

void insertsort(int list[],int n){

	int i,j,next;
	
	for(i=1;i<n;i++){
		next = list[i];//���ĵ� �迭�� ���� ���� 
		for(j=i-1;(j>=0)&&(next<list[j]);j--){
			list[j+1] = list[j];//�� ���Ҹ� ���� �ڸ��� ����� �ش� 
		} 
		list[j+1] = next;//���� ���� ������ �����Ѵ� 
	}
}

