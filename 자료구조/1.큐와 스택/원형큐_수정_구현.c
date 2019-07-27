#include<stdio.h>

int c_q[5]; 

void addq(int);
int deleteq(void);

int is_empty = 1;
int front=0;
int rear = 0;


//원형 큐를 공간낭비 없이 다 채우기 위해서 
//프론트가 첫원소를 가르켜야 하고
//리어 가 마지막 원소를 가르켜야 하는데 
//하지만 원소가 1개인 경우와 빈 경우는
//프론트와 리어가 같은 곳을 가르키는  
//같은 상태로 구분하기 어려워지기 때문에 
//불변수로 1개인 경우와 빈경우를 구분시킴 
 
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
	//맨 처음에 원소 한개를 넣을 때 
	//역시 프론트와 리어 인덱스가 같은 값을 가르켜서 구분이 필요 
	//리어는 그대로지만 상태는 빈 상태가 아님을 표시 
	if(front==(rear+1)%5){
		printf("full queue\n"); 
		return;
	}//큐가 다 찼을 때 
	rear = (rear+1)%5;
	c_q[rear] = item;
	//원소 넣기 
}

int deleteq(void){
	int temp;
	
	if(is_empty){
		printf("empty!!\n");
		return -999;
	} //비워있을 경우 
    if(front == rear){
    	is_empty = 1;
		temp = c_q[front];
		c_q[front] = 0;
        return temp; 
	}
	//순환큐에 원소가 하나인 경우
	//마지막 원소를 제거할 때 
	//비워진 상태를 기록해야함
	temp = c_q[front];
	c_q[front] = 0;
	front = (front+1)%5;
    return temp;
    //원소제거 
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

