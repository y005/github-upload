#include<stdio.h>
#include<stdlib.h> 

//���޸𸮿��� �޸𸮸� ��������
//�Ҵ�޴� ���Ḯ��Ʈ ����
 
typedef struct node1{
	int data;
	struct node1* link;
}node; //�⺻��屸��ü ����� 

typedef node* node_ptr;

node_ptr list;//���Ḯ��Ʈ�� �����ּҸ� ��� ������ ����
 
void add(node_ptr,int);//��� �߰���Ű�� �Լ�
void del(node_ptr,node_ptr);//��� �����ϴ� �Լ�
void print(node_ptr);//���Ḯ��Ʈ ����ϴ� �Լ�
node_ptr reverse_list1(node_ptr);//������Ʈ ����� �Լ� 
node_ptr reverse_list2(node_ptr);//������Ʈ ����� �Լ� 
node_ptr reverse_listc(node_ptr);//������Ʈ ����� �Լ� 

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
	//��ȯ����Ʈ ����� 
	list = reverse_listc(node1);
	print_c(list);
	
	
	system("pause");
	return 0;

}  

//������Ʈ �����ϱ� ���� �Լ� 
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
	
	if (!data){return;}//���� �� �߰��ؾߵ� 
    node = (node_ptr)malloc(sizeof(node));
    if(!node){
    	printf("NO HEAP MEMORY\n");
    	return;
	}//�� �޸𸮿� ���� �������� ���� 
	
	node->data = data;//���� ���� ��忡 ����Ÿ �Է�
	node->link = NULL;//����� ���ּҴ� �ݵ�� �η� �ʱ�ȭ		
	
	if(!list){
		list = node; 
	}//�� ó������ �߰��Ǵ� ��� 
	if(!prev){
		list = node;
	    node->link= list; 
	}//�Ǿտ� �߰��Ǵ� ������ ����Ʈ�� ��ü 
	else{
        node->link= prev->link;
	  	prev->link = node;
	}//�߰��� �߰��Ǵ� ��� 
}

void del(node_ptr prev,node_ptr node){
	
	if(!node){
		printf("delete failed\n");	
	}
	if(!prev){
		list = node->link;
	}//ó�� ��带 ������ ����Ʈ �����͸� ���� ���� ���� 
	else{
		prev->link =node->link; 
	}
	free(node);
	//��忡 �Ҵ�� ���޸𸮸� ������Ų�� 
}
 
void print(node_ptr ptr){
  	
	while(ptr){
		printf("%d ",ptr->data);
		ptr = ptr->link;
	}
	printf("\n");
}
 
