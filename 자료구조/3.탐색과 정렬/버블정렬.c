#include<stdio.h>

void bubblesort(int list[],int n);

int main(void){
	
	int i;
	int arr[9] = {7,13,87,65,45,36,68,47,34};
	
	bubblesort(arr,9);
	
	for(i=0;i<9;i++){
		printf("%d ",arr[i]);		
	}
	
	system("pause");
	return 0;
}

void bubblesort(int list[],int n){

	int i,j,flag = 1;
	int temp;
	for(i=n-1;flag>0;j--){
		flag = 0;//���Ŀ��� ���� �ʱ�ȭ 
		for(j=0;j<i;j++){
			if(list[j]>list[j+1]){
				temp = list[j];//�պκ��� �� Ŭ ������ �������ش� 
				list[j] = list[j+1];
				list[j+1] = temp;
				flag = 1;//���� ���� üũ 
			}
		} 
	}
}
