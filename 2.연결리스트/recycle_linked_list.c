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
node_ptr avail = NULL;//��Ȱ�� ����Ʈ�� ���� ���� ���� �ּ� 
 
void add(node_ptr,int);//��� �߰���Ű�� �Լ�
void del(node_ptr,node_ptr);//��� �����ϴ� �Լ�
void print(node_ptr);//���Ḯ��Ʈ ����ϴ� �Լ�

void recycle_node(node_ptr);//�Ⱦ��� ��带 available ����Ʈ���ٰ� 
void recycle_circle(node_ptr*);//��ȯ��带 ��ü�� ��Ȱ���ϱ� 
node_ptr get_node(void);//��Ȱ���� ���ִ� ��尡 �ִ��� Ȯ�� 
  
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
	node->link = avail;//��带 ��Ȱ�밡���� ��� ���ÿ� ���� 
	avail = node;//avail ���� 
	 
}//��� �ϳ��� ��Ȱ���ϴ� �Լ� 

void recycle_circle(node_ptr* ptr){
    
    node_ptr temp;

    if(*ptr){
		temp = (*ptr)->link; 
		(*ptr)->link = avail;//��ȯ����Ʈ 1��°�� ��Ȱ�� ���ÿ� ���� 
		avail = temp;//��ȯ ����Ʈ 2��°�� ���� ������ �ϱ� 
		*ptr=NULL;
	}
}//��ȯ����Ʈ ��ü�� ��Ȱ���ϴ� �Լ� 

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
}//��Ȱ�� ��尡 ������ ���� �ְ�
//������ ���� �Ҵ��� �޴´� 

void add(node_ptr prev,int data){
	node_ptr node;
	
	if (!data){return;}//���� �� �߰��ؾߵ� 
    node = get_node();
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
	
	recycle_node(node);
	//free(node);
	//��忡 �Ҵ�� ���޸𸮸� ��Ȱ���Ų�� 
}
 
void print(node_ptr ptr){
  	node_ptr temp = ptr;
	
	while(temp){
		printf("%d ",temp->data);
		temp = temp->link;
	}
	printf("\n");
}

