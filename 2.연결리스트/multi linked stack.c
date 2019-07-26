#include<stdio.h>
#include<stdlib.h> 

//힙메모리에서 메모리를 동적으로
//할당받는 연결리스트 구현 
typedef struct node1{
	int data;
	struct node1* link;
}node; 
//기본노드구조체 만들기 

typedef node* node_ptr;

node_ptr list0;
node_ptr list1;
node_ptr list2;
//연결리스트의 시작주소를 담는 포인터 변수

node_ptr top[3]; 
//멀티 링크드 스택 구조구현을 위한 
//구조체 노드를 가르키는 탑포인와 
//탑포인터들을 담을 배열 

void add(int,int);//노드 추가시키는 함수
int del(int);//노드 삭제하는 함수
void print(int);//연결리스트 출력하는 함수
 
int main(void){
    int i;
	node_ptr node1,node2,node3;
	
	node1 = (node_ptr)malloc(sizeof(node));
    node1->data = 100;
	node1->link = NULL;
	
	list0 = node1;
	
	node2 = (node_ptr)malloc(sizeof(node));
    node2->data = 200;
	node2->link = NULL;
	node1->link = node2;
	 
	node3 = (node_ptr)malloc(sizeof(node));
    node3->data = 300;
	node3->link = NULL;
	node2->link = node3;
	
	top[0] = list0;
	
	add(0,400);
	add(0,500);
	
	print(0);
	
	del(0);
	print(0);
	
	del(0);
	print(0);
    
	del(1);
	
	for(i=0;i<3;i++){
		del_all(i);
	}	
	
	system("pause");
	return 0;

}  

void add(int num,int data){
	node_ptr node;
	
	node = (node_ptr)malloc(sizeof(node));
	if(!node){
		printf("NO MORE HEAP MEMORY\n");
		return; 
	}
	node->data = data;
	node->link = NULL;
	//노드 생성 
	
	if(top[num]){
		node->link = top[num];
	}
	top[num] = node;
	//스택의 탑포인터를 갱신 
}

int del(int num){
	node_ptr temp = top[num];
	int temp1;
	
	if(!temp){
		printf("DELETE FAILED\n");
		return -999;
	}
	
	top[num] = temp->link;
	temp1 = temp->data;
	
	free(temp);
	
	return temp1;
}
 
void del_all(int num){

	node_ptr temp = top[num];
	int temp1;
	
	if(!temp){
		printf("DELETE FAILED\n");
		return -999;
	}
	
	top[num] = temp->link;
	temp1 = temp->data;
	
	free(temp);
	del_all(num);
}

void print(int num){
  	node_ptr temp = top[num];
	
	while(temp){
		printf("%d ",temp->data);
		temp = temp->link;
	}
	printf("\n");
}

