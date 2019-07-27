#include<stdio.h>
int queue[5];

int first = -1;
int rear = -1;

int pop(void);
void push(int); 

//순환큐 만들기(모든 배열공간을 다쓸수 있는)
//먼저들어오는 프론트 인덱스
//나중에 넣는리어 인덱스
//프론트 인덱스에서 차례대로 팝과 관련된 
//리어  인덱스에서는푸시와 관련된
	  
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
	//큐의 프런트 인덱스는 빈 공간을 가르키므로 
	//한 칸 더해야 함 
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

