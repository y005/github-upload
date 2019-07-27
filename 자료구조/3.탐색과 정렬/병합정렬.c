#include<stdio.h>

void mergesort(int list[],int temp[],int n);

int main(void){
	
	int i;
	int arr[9] = {7,13,87,65,45,36,68,47,34};
	int temp[9];//������ �迭�� �ʿ��ϴ� 
	
	mergesort(arr,temp,9);
	
	for(i=0;i<9;i++){
		printf("%d ",arr[i]);		
	}


	system("pause");
	return 0;
}

void mergesort(int numbers[],int temp[],int array_size){
	m_sort(numbers,temp,0,array_size-1);
}

void m_sort(int numbers[],int temp[],int left,int right){
	
	int mid;
	
	if(left<right){
		mid = (left+right)/2;
		m_sort(numbers,temp,left,mid);//���ĵ� ���� �κ� 
		m_sort(numbers,temp,mid+1,right);//���ĵ� ������ �κ� 
		merge(numbers,temp,left,mid+1,right);//���� �ٽ� ���Ľ��� ���� 
	}
}

void merge(int numbers[],int temp[],int left,int mid,int right){
	
	int i,left_end,num,tmp_pos;
	
	left_end = mid-1;//������ ���� �κ��� �� �ε��� 
	tmp_pos = left;//temp�迭���� ���� �ε��� 
	
	num = right-left+ 1;//��ü ���� 
	
	while((left<=left_end)&&(mid<=right)){
		if(numbers[left]<=numbers[mid]){
			temp[tmp_pos] = numbers[left];
			tmp_pos++;
			left++;
		}	
		else{
			temp[tmp_pos] = numbers[mid];
			tmp_pos++;
			mid++;	
		}
	}	
	while(left<=left_end){// ���ʺκи� ���� ���  
		temp[tmp_pos] = numbers[left];
		left++;
		tmp_pos++;
	}
	while(mid<=right){//������ �κи� ���� ��� 
		temp[tmp_pos] = numbers[mid];
		mid++;
		tmp_pos++;
	}
	for(i=0;i<num;i++){//���յ� �迭�� ���� �迭�� �ٽ� ���� 
		numbers[right] = temp[right];
		right--;
	}
}


