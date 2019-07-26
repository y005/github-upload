#include<stdio.h>

void mergesort(int list[],int temp[],int n);

int main(void){
	
	int i;
	int arr[9] = {7,13,87,65,45,36,68,47,34};
	int temp[9];//여분의 배열이 필요하다 
	
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
		m_sort(numbers,temp,left,mid);//정렬된 왼쪽 부분 
		m_sort(numbers,temp,mid+1,right);//정렬된 오른쪽 부분 
		merge(numbers,temp,left,mid+1,right);//둘을 다시 정렬시켜 병합 
	}
}

void merge(int numbers[],int temp[],int left,int mid,int right){
	
	int i,left_end,num,tmp_pos;
	
	left_end = mid-1;//분할한 왼쪽 부분의 끝 인덱스 
	tmp_pos = left;//temp배열에서 쓰는 인덱스 
	
	num = right-left+ 1;//전체 갯수 
	
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
	while(left<=left_end){// 왼쪽부분만 남은 경우  
		temp[tmp_pos] = numbers[left];
		left++;
		tmp_pos++;
	}
	while(mid<=right){//오른쪽 부분만 남은 경우 
		temp[tmp_pos] = numbers[mid];
		mid++;
		tmp_pos++;
	}
	for(i=0;i<num;i++){//병합된 배열을 원래 배열에 다시 복사 
		numbers[right] = temp[right];
		right--;
	}
}


