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
		next = list[i];//정렬된 배열에 넣을 원소 
		for(j=i-1;(j>=0)&&(next<list[j]);j--){
			list[j+1] = list[j];//새 원소를 넣을 자리를 만들어 준다 
		} 
		list[j+1] = next;//작은 원소 다음에 삽입한다 
	}
}

