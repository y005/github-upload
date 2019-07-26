#include<stdio.h>

struct element{
	int key;
};

//�迭 ���¸� ���� �� 
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
	i = ++(*n);//Ʈ���� ���� ���κп� �����Ѵ� 
	while((i!=1)&&(item.key>heap[i/2].key)){
		heap[i] = heap[i/2];//���ʿ� �ִ� ���Ҹ� ������ �����ش� 
		i/=2;
	}
	heap[i].key = item.key;//�´� ��ġ�� ���Ҹ� �־��ش� 
}

//���� ū ���� ������ ���� ���� �տ� �ִ� ���� 
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
	
	//���� ���� �ִ� temp�� insert�� �� ���� �������Ѵ� 
		
	while(child<=(*n)){
		if((child<(*n))&&((heap[child].key)<(heap[child+1].key))){
			child++;//�� ū ���ڸ� �ٲ��ش� 
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
