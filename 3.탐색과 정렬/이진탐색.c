#include<stdio.h>

int binsearch(int num[],int key,int low,int high);

int main(void){
	
	int i;
	int arr[9] = {7,10,27,35,44,56,78,87,94};
	
	if(binsearch(arr,56,0,8)){
		printf("%d ",binsearch(arr,56,0,8));
	}
	system("pause");
	return 0;
}


int binsearch(int num[],int key,int low,int high){

	int mid;
	
	while(low<=high){
		
		mid = (low+high)/2;//기준점을 정한다 
		if(key<num[mid]){
			high = mid -1;
		}
		else{
			if(key>num[mid]){
				low = mid+1;
			}
			else{
				return mid;
			}
		}	
	}
	return 0;
}
