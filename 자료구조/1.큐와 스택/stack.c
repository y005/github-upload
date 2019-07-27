#include<stdio.h>

int stack [5];

int top = -1;

int pop(void);
void push(int);

//스택 재현 
//배열 할당 
//top 인덱스 설정
//팝과 푸시 함수 구현
	
int main(void){  
    push(1);
	push(7);
	push(2);
	push(5);
	push(3);
	push(9);
	print_stack();
	
	pop();
	print_stack();
	
	pop();
	print_stack();
	
	pop();
	print_stack();
	
	pop();
	print_stack();
	
	pop();
	print_stack();
	
	pop();
	print_stack();


	system("pause");		
	return 0;
}

void push(int num){
	if(top== 5-1){
		printf("stack full\n");
		return;
	}
	stack[++top] = num;
}

int pop(void){
    int temp;
    
	if(top==-1){
		printf("empty stack\n");
		return -999;
	}
	
	temp = stack[top];
    stack[top] = 0;
	top--;  
    return temp;
}

void print_stack(void){
	int i;
	
	for(i=0;i<5;i++){
		printf("%d",stack[i]);
	}
	
	printf("\n");
}


