#include<stdio.h>
#include<stdlib.h>

typedef struct node1{
	int data;
	struct node1* link;
}node; //�⺻��屸��ü ����� 

typedef node* node_ptr;

node_ptr list;

void add_c(node_ptr prev,int data);
void del_c(node_ptr prev,node_ptr node);
node_ptr reverse_listc(node_ptr one);
void print_c(node_ptr ptr);

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
	node3->link = node1;
	node2->link = node3;
	
	add_c(node3,400);
	
	print_c(node1);
	
	list = reverse_listc(node1);
	print_c(list);
	
	system("pause");
	return 0;
}

void add_c(node_ptr prev,int data){
	node_ptr node;
	node = (node_ptr)malloc(sizeof(node));
	if(!node){
		printf("NO HEAP MEMORY\n");
	}
	node->data = data;
	if(!prev){
		node->link = node;
	}
	node->link = prev->link;
	prev->link = node;
	//����� ���� 
}

void del_c(node_ptr prev,node_ptr node){
	
	if(!node){
		printf("delete failed\n");	
	}
	if(!prev){
		printf("delete failed\n");	
	}//ó�� ��带 ������ ����Ʈ �����͸� ���� ���� ���� 
	else{
		prev->link =node->link; 
	}
	free(node);
	//��忡 �Ҵ�� ���޸𸮸� ������Ų�� 
}

node_ptr reverse_listc(node_ptr one){
	
	node_ptr two,three,temp;
	
	temp = one;
	two = NULL;

	do{
		three = two;
		two = one;
		one = one->link;
		two->link = three;
		
	}while(temp!= one);
	
	one->link = two;
	
	return two;

} 

void print_c(node_ptr ptr){
  	node_ptr temp = ptr;
	
	do{
		printf("%d ",ptr->data);
		ptr = ptr->link;
	}while(temp!=ptr);
	
	printf("\n");
	
}
