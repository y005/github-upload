#include<stdio.h>

struct element{
	int key;
};

//배열 형태를 가진 힙 
void insert_heap(struct element item,int *n);
struct element delete_heap(int*n); 
struct element heap[10];
	
int main(void){
	
	struct element temp;
	int n =0;
    int temp1;	
	
	while(temp1){
		scanf("%d",&temp1);
		temp.key = temp1;
		insert_heap(temp,&n);
	}
	
	temp= delete_heap(&n);
	
	printf("%d ",temp.key);
	
	system("pause");			
	return 0;
}

void insert_heap(struct element item,int*n){

	int i;
	if(*n>10){
		printf("FULL\n");
	}
	i = ++(*n);//트리의 제일 끝부분에 삽입한다 
	while((i!=1)&&(item.key>heap[i/2].key)){
		heap[i] = heap[i/2];//위쪽에 있는 원소를 밑으로 내려준다 
		i/=2;
	}
	heap[i].key = item.key;//맞는 위치에 원소를 넣어준다 
}

//제일 큰 수를 꺼낸다 힙에 제일 앞에 있는 숫자 
struct element delete_heap(int*n){
	
	int parent,child;
	struct element item,temp;

	if((*n)==0){
		printf("empty\n");
	}
	
	item = heap[1];
	temp = heap[(*n)--];
	
	parent = 1;
	child = 2;
	
	//제일 끝에 있는 temp를 insert한 뒤 힙을 재정렬한다 
		
	while(child<=(*n)){
		if((child<(*n))&&((heap[child].key)<(heap[child+1].key))){
			child++;//더 큰 숫자를 바꿔준다 
		}
		if(temp.key>=heap[child].key){
			break;
		}
		heap[parent]=heap[child];
		parent = child;
		child *= 2;
	}
	heap[parent]= temp;
	return item;
} 
