#include<stdio.h>

void shellsort(int list[],int n);

int main(void){
	
	int i;
	int arr[9] = {7,13,87,65,45,36,68,47,34};
	
	shellsort(arr,9);
	
	for(i=0;i<9;i++){
		printf("%d ",arr[i]);		
	}

	system("pause");
	return 0;
}

void shellsort(int list[],int n){

	int i,j,gap,tmp;
	
	for(gap=n/2;gap>0;gap/=2){
		if(gap%2 == 0){
			gap++;//   ¦���� ��� Ȧ���� �ٲ��ش� 
		}
		for(i=gap;i<n;i++){//���������� �̷������ 
			tmp = list[i];//������ ���� 
			for(j=i;j>=gap;j-=gap){
				if(tmp<list[j-gap]){
					list[j] = list[j-gap];
				}			
				else{
					break;//������ ���� 
				}
			}
			list[j] = tmp;
		} 
	}
}

