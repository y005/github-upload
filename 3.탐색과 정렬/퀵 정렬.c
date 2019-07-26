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
	int b[9];//���ĵ� �迭�� ��� ������ �迭  
	
	for(k=start+1;k<=end;k++){
		if(a[k]<a[start]){//�������� �߽����� �� �ڷ� ä���ִ´� 
			b[i++] = a[k];
		}
		else{
			b[j--] = a[k];
		}
	}
	b[i] = a[start];// �������� ����� 
	for(k=start;k<=end;k++){
		a[k] = b[k];//�ٽ� �����Ѵ� 
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
			swap(a,i,j);//���ǿ� ���� �ʴ� ������ ��ġ�� ����  �ٲ��ش� 
		}			
	}while(i<=j);
	
	swap(a,s,j);//�������� ����� �Ű��ش� 
	
	return j;
}

void quicksort(int list[],int s,int e){

	int m; 

	if(s>=e){
		return;
	}
	
	m = partition2(list,s,e);//�������� �������� �յڷ� ���� 

	quicksort(list,s,m-1); 
	quicksort(list,m+1,e);
}

void quicksort1(int list[],int left,int right){

	int pivot,i,j,temp;
	
	if(left<right){
		i= left;
		j= right+1;
		pivot = list[left];//������ ���� 
		
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
				list[j] = temp;//���� 
			}			
		}while(i<=j);
		
		temp = list[left];
		list[left] = list[j];
		list[j] = temp;//�������� ����� ���� 
	
		quicksort1(list,left,j-1); 
		quicksort1(list,j+1,right);
	}
}
