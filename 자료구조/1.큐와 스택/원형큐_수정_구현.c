#include<stdio.h>

int c_q[5]; 

void addq(int);
int deleteq(void);

int is_empty = 1;
int front=0;
int rear = 0;


//���� ť�� �������� ���� �� ä��� ���ؼ� 
//����Ʈ�� ù���Ҹ� �����Ѿ� �ϰ�
//���� �� ������ ���Ҹ� �����Ѿ� �ϴµ� 
//������ ���Ұ� 1���� ���� �� ����
//����Ʈ�� ��� ���� ���� ����Ű��  
//���� ���·� �����ϱ� ��������� ������ 
//�Һ����� 1���� ���� ���츦 ���н�Ŵ 
 
int main(){
	
	addq(1);
	addq(2);
	print_q();
	
	deleteq();  
	print_q();
	
	deleteq();  
	print_q();
	
	addq(3);
	print_q();
	
	addq(4);
	addq(5);
	print_q();
	
	addq(6);
	addq(7);
	print_q();
	
	deleteq();  
    print_q();
    
	addq(8);
	addq(9);
	print_q();
	
	deleteq();  
    print_q();
    
	deleteq();
    print_q();
    
	deleteq();
    print_q();
    
    deleteq();
    print_q();
 
    deleteq();
    print_q();
	   
	system("pause");
	return 0;
}

void addq(int item){
	if(is_empty){
		c_q[rear] = item;
		is_empty = 0;
		return;
	}
	//�� ó���� ���� �Ѱ��� ���� �� 
	//���� ����Ʈ�� ���� �ε����� ���� ���� �����Ѽ� ������ �ʿ� 
	//����� �״������ ���´� �� ���°� �ƴ��� ǥ�� 
	if(front==(rear+1)%5){
		printf("full queue\n"); 
		return;
	}//ť�� �� á�� �� 
	rear = (rear+1)%5;
	c_q[rear] = item;
	//���� �ֱ� 
}

int deleteq(void){
	int temp;
	
	if(is_empty){
		printf("empty!!\n");
		return -999;
	} //������� ��� 
    if(front == rear){
    	is_empty = 1;
		temp = c_q[front];
		c_q[front] = 0;
        return temp; 
	}
	//��ȯť�� ���Ұ� �ϳ��� ���
	//������ ���Ҹ� ������ �� 
	//����� ���¸� ����ؾ���
	temp = c_q[front];
	c_q[front] = 0;
	front = (front+1)%5;
    return temp;
    //�������� 
}

void print_q(void){
	int i;
	if(is_empty){
		printf("empty!!\n");
        return; 
	}
	
	for(i=0;i<5;i++){
		printf("%d ",c_q[i]);
	}
	printf("\n");
	return;
}

