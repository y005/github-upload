#include<stdio.h>
#include<stdlib.h> 

//���޸𸮿��� �޸𸮸� ��������
//�Ҵ�޴� ���Ḯ��Ʈ ���� 
typedef struct node1{
	int data;
	struct node1* link;
}node; 
//�⺻��屸��ü ����� 

typedef node* node_ptr;

node_ptr list0;
node_ptr list1;
node_ptr list2;
//���Ḯ��Ʈ�� �����ּҸ� ��� ������ ����

node_ptr top[3]; 
//��Ƽ ��ũ�� ���� ���������� ���� 
//����ü ��带 ����Ű�� ž���ο� 
//ž�����͵��� ���� �迭 

void add(int,int);//��� �߰���Ű�� �Լ�
int del(int);//��� �����ϴ� �Լ�
void print(int);//���Ḯ��Ʈ ����ϴ� �Լ�
 
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
	//��� ���� 
	
	if(top[num]){
		node->link = top[num];
	}
	top[num] = node;
	//������ ž�����͸� ���� 
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

