#include<stdio.h>

void swap(int list[],int a,int b);
void quicksort(int list[],int s,int e);
void quicksort1(int list[],int left,int right);
int partition1(int a[],int start,int end);
int partition2(int a[],int s,int e);

int main(void){
	
	int i;
	int arr[9] = {4,1,3,6,5,2,9,7,8};
	
	quicksort(arr,0,8);
	
	for(i=0;i<9;i++){
		printf("%d ",arr[i]);		
	}
	system("pause");
	return 0;
}

void swap(int list[],int a,int b){
	
	int temp;
	
	temp = list[a]; 
	list[a] = list[b];
	list[b] = temp;	
}

int partition1(int a[],int start,int end){
	int i,j,k;
	i = start;
	j = end;
	int b[9];//정렬된 배열을 잠시 저장할 배열  
	
	for(k=start+1;k<=end;k++){
		if(a[k]<a[start]){//기준점을 중심으로 앞 뒤로 채워넣는다 
			b[i++] = a[k];
		}
		else{
			b[j--] = a[k];
		}
	}
	b[i] = a[start];// 기준점을 가운데로 
	for(k=start;k<=end;k++){
		a[k] = b[k];//다시 복사한다 
	}
	return i;
}

int partition2(int a[],int s,int e){
	int pivot,i,j;
	
	pivot = s;
	i= s;
	j= e+1;

	do{
		do{
			i++;
		}while((i<=e)&&(a[i]<a[pivot]));
		do{
			j--;
		}while((j>=s)&&(a[j]>a[pivot]));
		if(i<j){
			swap(a,i,j);//조건에 맞지 않는 원소의 위치를 서로  바꿔준다 
		}			
	}while(i<=j);
	
	swap(a,s,j);//기준점을 가운데로 옮겨준다 
	
	return j;
}

void quicksort(int list[],int s,int e){

	int m; 

	if(s>=e){
		return;
	}
	
	m = partition2(list,s,e);//기준점을 기준으로 앞뒤로 정렬 

	quicksort(list,s,m-1); 
	quicksort(list,m+1,e);
}

void quicksort1(int list[],int left,int right){

	int pivot,i,j,temp;
	
	if(left<right){
		i= left;
		j= right+1;
		pivot = list[left];//기준점 설정 
		
		do{
			do{
				i++;
			}while((list[i]<pivot)&&(i<=right));
			do{
				j--;
			}while((list[j]>pivot)&&(j>=left));
			if(i<j){
				temp = list[i];
				list[i] = list[j];
				list[j] = temp;//스왑 
			}			
		}while(i<=j);
		
		temp = list[left];
		list[left] = list[j];
		list[j] = temp;//기준점을 가운데로 스왑 
	
		quicksort1(list,left,j-1); 
		quicksort1(list,j+1,right);
	}
}
