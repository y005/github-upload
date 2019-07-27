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
node_ptr avail = NULL;//재활용 리스트를 담은 스택 시작 주소 
 
void add(node_ptr,int);//노드 추가시키는 함수
void del(node_ptr,node_ptr);//노드 삭제하는 함수
void print(node_ptr);//연결리스트 출력하는 함수

void recycle_node(node_ptr);//안쓰는 노드를 available 리스트에다가 
void recycle_circle(node_ptr*);//순환노드를 전체를 재활용하기 
node_ptr get_node(void);//재활용할 수있는 노드가 있는지 확인 
  
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
	
	add(node3,400);
	print(list);
	
	del(node2,node3);
	print(list); 

    del(node1,node2);
    print(list); 

	add(list,500);
	print(list);
		
	add(list,600);	
	print(list); 
	
	
	system("pause");
	return 0;

}  

void recycle_node(node_ptr node){
	printf("RECYCLE!!\n");
	node->link = avail;//노드를 재활용가능한 노드 스택에 저장 
	avail = node;//avail 갱신 
	 
}//노드 하나를 재활용하는 함수 

void recycle_circle(node_ptr* ptr){
    
    node_ptr temp;

    if(*ptr){
		temp = (*ptr)->link; 
		(*ptr)->link = avail;//순환리스트 1번째를 재활용 스택에 연결 
		avail = temp;//순환 리스트 2번째를 가장 앞으로 하기 
		*ptr=NULL;
	}
}//순환리스트 전체를 재활용하는 함수 

node_ptr get_node(void){
    node_ptr temp;
    
	if(avail){
    	temp = avail;
    	avail = avail->link;
        printf("REUSE!!\n");
    }
	else{
		temp =(node_ptr)malloc(sizeof(node));
	}
    return temp;
}//재활용 노드가 있으면 뗴어내서 주고
//없으면 새로 할당을 받는다 

void add(node_ptr prev,int data){
	node_ptr node;
	
	if (!data){return;}//넣을 값 추가해야됨 
    node = get_node();
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
	
	recycle_node(node);
	//free(node);
	//노드에 할당된 힙메모리를 재활용시킨다 
}
 
void print(node_ptr ptr){
  	node_ptr temp = ptr;
	
	while(temp){
		printf("%d ",temp->data);
		temp = temp->link;
	}
	printf("\n");
}

