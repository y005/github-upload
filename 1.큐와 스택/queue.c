#include<stdio.h>
int queue[5];

int first = -1;
int rear = -1;

int pop(void);
void push(int); 

//��ȯť �����(��� �迭������ �پ��� �ִ�)
//���������� ����Ʈ �ε���
//���߿� �ִ¸��� �ε���
//����Ʈ �ε������� ���ʴ�� �˰� ���õ� 
//����  �ε���������Ǫ�ÿ� ���õ�
	  
int main(void){
	push(5);
	push(4);
	push(6);
	push(8);
	push(2);
	push(1);
	print_queue();
	
	pop();
	print_queue();
	
	pop();
	pop();
	print_queue();
	pop();
	pop();
	pop();
    print_queue();
	system("pause");
	return 0;
}

int pop(void){
	int temp;
	if(first == rear){
		printf("empty queue\n");
	    return -999;
	}
	temp = queue[++first];
    queue[first] = 0;
	return temp;
	//ť�� ����Ʈ �ε����� �� ������ ����Ű�Ƿ� 
	//�� ĭ ���ؾ� �� 
} 

void push(int num){
	if(rear == 5-1){
		printf("full queue\n");
	    return; 
	}
	queue[++rear] = num;
	return;
}

void print_queue(void){
    int i;
    
    for(i=first+1;i<rear;i++){
    	printf("%d",queue[i]);
	}
	printf("\n");

}

