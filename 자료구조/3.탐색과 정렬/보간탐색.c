#include<stdio.h>

int interpolsearch(int num[],int key,int left,int right);

int main(void){
	
	int i;
	int arr[9] = {7,10,27,35,44,56,78,87,94};
	
	if(interpolsearch(arr,56,0,8)){
		printf("%d ",interpolsearch(arr,56,0,8));
	}
	
	system("pause");
	return 0;
}


int interpolsearch(int num[],int key,int left,int right){

	int pos;
	
	while(right<=left){
		
		pos = (int)left+(right-left)*(key-num[left])/(num[right]-num[left]);
		
		if(key<num[pos]){
			right = pos-1;
		}
		else{
			if(key>num[pos]){
				left = pos+1;
			}
			else{
				return pos;
			}
		}	
	}
	return 0;
}
