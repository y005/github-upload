#include<stdio.h>
#include<stdlib.h> 

//힙메모리에서 메모리를 동적으로
//할당받는 연결리스트 구현
 
typedef struct node1{
	int data;
	struct node1* link;
}node; //기본노드구조체 만들기 

typedef node* node_ptr;

node_ptr list;//연결리스트의 시작주소를 담는 포인터 변수
 
void add(node_ptr,int);//노드 추가시키는 함수
void del(node_ptr,node_ptr);//노드 삭제하는 함수
void print(node_ptr);//연결리스트 출력하는 함수
node_ptr reverse_list1(node_ptr);//역리스트 만드는 함수 
node_ptr reverse_list2(node_ptr);//역리스트 만드는 함수 
node_ptr reverse_listc(node_ptr);//역리스트 만드는 함수 

int main(void){
    
	node_ptr node1,node2,node3;
	
	node1 = (node_ptr)malloc(sizeof(node));
    node1->data = 100;
	node1->link = NULL;
	
	list = node1;
	
	node2 = (node_ptr)malloc(sizeof(node));
    node2->data = 200;
	node2->link = NULL;
	node1->link = node2;
	 
	node3 = (node_ptr)malloc(sizeof(node));
    node3->data = 300;
	node3->link = NULL;
	node2->link = node3;
	
	del(node1,node2);
	print(list);
	
	
	add(node3,400);
	add(node3,500);
	print(list);
	
	
	list = reverse_list1(list);
	print(list);
	
	list = reverse_list2(list);
	print(list);
	
	node3->link->link->link = node1;
	//순환리스트 만들기 
	list = reverse_listc(node1);
	print_c(list);
	
	
	system("pause");
	return 0;

}  

//역리스트 구현하기 위한 함수 
node_ptr reverse_list1(node_ptr one){
	node_ptr two,three;
	
	two = NULL;
	
	while(one){
		three = two;
		two = one;
		one = one->link;
		two->link = three;
	}
	
	return two;
} 

node_ptr reverse_list2(node_ptr one){
	
	node_ptr two,three;
	
	two = NULL;
	
	for(;one;){
		three = two;
		two = one;
		one = one->link;
		two->link = three;
	}
	return two;

} 

void add(node_ptr prev,int data){
	node_ptr node;
	
	if (!data){return;}//넣을 값 추가해야됨 
    node = (node_ptr)malloc(sizeof(node));
    if(!node){
    	printf("NO HEAP MEMORY\n");
    	return;
	}//힙 메모리에 공간 부족으로 실패 
	
	node->data = data;//새로 생긴 노드에 데이타 입력
	node->link = NULL;//노드의 끝주소는 반드시 널로 초기화		
	
	if(!list){
		list = node; 
	}//맨 처음으로 추가되는 노드 
	if(!prev){
		list = node;
	    node->link= list; 
	}//맨앞에 추가되는 경우기존 리스트와 합체 
	else{
        node->link= prev->link;
	  	prev->link = node;
	}//중간에 추가되는 경우 
}

void del(node_ptr prev,node_ptr node){
	
	if(!node){
		printf("delete failed\n");	
	}
	if(!prev){
		list = node->link;
	}//처음 노드를 삭제시 리스트 포인터를 다음 노드로 수정 
	else{
		prev->link =node->link; 
	}
	free(node);
	//노드에 할당된 힙메모리를 해제시킨다 
}
 
void print(node_ptr ptr){
  	
	while(ptr){
		printf("%d ",ptr->data);
		ptr = ptr->link;
	}
	printf("\n");
}
 
