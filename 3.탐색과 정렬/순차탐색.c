#include<stdio.h>

int seqsearch(int num[],int searchkey,int n);

int main(void){
	
	int i;
	int arr[9] = {10,34,35,27,87,57,37,94,34};
	
	if(seqsearch(arr,57,9)){
		printf("%d",seqsearch(arr,57,9));	
	}
	system("pause");
	return 0;
}


int seqsearch(int num[],int searchkey,int n){

	int i;
	
	for(i=0;i<n;i++){
		if(searchkey == num[i]){
			return i;
		}
	}
	return 0;

}
