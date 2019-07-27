#include<stdio.h>

void selectsort(int list[],int n);

int main(void){
	
	int i;
	int arr[9] = {7,13,87,65,45,36,68,47,34};
	
	selectsort(arr,9);
	
	for(i=0;i<9;i++){
		printf("%d ",arr[i]);		
	}

	system("pause");
	return 0;
}

void selectsort(int list[],int n){

	int i,j,min,temp;
	
	for(i=0;i<n-1;i++){
		min = i;
		for(j=i;j<n;j++){
			if(list[j]<list[min]){
				min = j;//제일 작은 원소의 인덱스를 저장 
			}
		}
		temp = list[i];
		list[i] = list[min];
		list[min] = temp;//원소위치를 변경한다 
	}
}
