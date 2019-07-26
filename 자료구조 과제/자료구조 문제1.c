#include<stdio.h>
#include<ctype.h>

//infix -postfix, postfix-evaluation (P.108 연습 문제 18번 참고)
//다중 숫자 infix수식을 입력 받아 postfix로 변환한 후 값을 계산해야 
//각 변환 과정에서 스택의 상태를 각각 출력 하시오
//입력되는 infix 수식에서 피연산자와 연산자 사이에 공백이 없다고 가정한다
//postfix를 화면에 출력할 때는 피연산자와 피연산자 또는 연산자 사이에 공백을 삽입
//최소 3가지 이상의 infix 수식 예에 대하여 처리 


char postfix[50];//후위 수식을 저장하기 위한 배열 
int pos;//후위 수식 인덱스 
int index;

char token_stack[50];//후위수식으로 변환 할 때 쓰는 스택 
int token_top = -1;//중위 수식 변환시 연산자를 저장할 스택 포인터 


int eval_stack[50];//후위수식을 계산하기 위한 스택
int top= -1;//후위 수식 계산시 피연산자를 저장할 스택 포인터 

int digit_stack[10];//숫자 변환을 위한 스택 
int digit_stack_top = -1;
 
int sym_type;

typedef enum{	

	open_b,close_b,plus,minus,times,divide,mod,eos,operand

}priority; 

void infix_to_postfix(void);
int precendence(char op);
void push_token(char sym);
char pop_token(void);
void print_postfix(char* postfix);
void print_token_stack(char* token_stack);

int eval_postfix(void);
char read_item(void);
void push(int);
int pop(void);
void print_stack(void);

int main(void){
	int num;
	int i;  
	
	while(1){
		
		printf("select(1.infix-postfix 2.exit) :: ");
		scanf("%d",&num);
		
		switch(num){
		
			case 1:
				infix_to_postfix();
				printf("\nanswer: %d\n",eval_postfix());
				break;
		
			case 2:
				return 0;
				
			default: 
				printf("주어진 번호내에서 입력하세요\n");
				break;
		}
	}
	
	system("pause");
	return 0;
}


//숫자삽입이 끝나면 널값을 추가해주고  
void infix_to_postfix(void){
	char expr[50],sym,token;
	pos = 0;
	int i;
	index = 0;
	
	for(i=0;i<50;i++){
		expr[i] = '\0';
	}
	//배열 초기화 
	
	printf("Enter the expression:: ");
	scanf("%s",expr);//중위 수식 배열에 저장 
	
	while(((token = expr[pos++]) != '\0')){
		
		if(isalnum(token)==4){
			postfix[index++] = token;
			//피연산자 출력시 
		}
		else if(token == '('){
			push_token(token);
		}
		else if(token == ')'){
			while((sym = pop_token()) != '('){
				postfix[index++] = '\0';
				postfix[index++] = sym;
				//후위수식에 연산자와 널값 추가		
			}
		}
		else{
			while((precendence(token_stack[token_top]) >= precendence(token))&&(token_top !=-1)){
				postfix[index++] = '\0';
				postfix[index++] = pop_token();
				//후위수식에 연산자와 널값 추가		
			}
			postfix[index++] = '\0';
			//이전에 숫자면 앞에도 널값 추가		
			push_token(token);
		}
		print_postfix(postfix); 
		print_token_stack(token_stack);
	}

	while((token_top != -1)){
		postfix[index++] = '\0';
		postfix[index++] = pop_token();
		//후위 수식에 연산자와 널값 추가 
		print_postfix(postfix);
		print_token_stack(token_stack);
	}
	
}

int precendence(char op){
	if(op == '('){
		return 0;
	}
	if(op == '+'||op == '-'){
		return 1;
	}
	if(op == '*'||op == '/'||op == '%'){
		return 2;
	}
}


void print_postfix(char* postfix){
	int i;
	printf("\n");
	printf("postfix:");
    for(i= 0;i< index;i++){
		printf("%c",postfix[i]);
	}
	printf("\n");
}


void print_token_stack(char* token_stack){
	int i = token_top;
	
	printf("token stack:");
	while(token_stack[i]){
		printf("%c",token_stack[i]);
		i--;
	}
	printf("\n");
}


void push_token(char sym){
	if(token_top < 50){
		token_stack[++token_top] = sym;
	}
	else{
		printf("token stack full\n");
	}
}

char pop_token(void){
	if(token_top >= 0){
		return token_stack[token_top--];
	}
	printf("token stack empty\n");
	return ' ';
}

//후위수식들을 계산해야 함
//피연산자를 스택에 저장하고
//연산자를 만나면 피연산자 두개를 꺼내서 연산함  
//연속되는 숫자를 변환하기
	
int eval_postfix(void){
	char sym;
	int op1,op2;
	int eos_count = 0;//널값이 두번 이상이면 후위수식 종료해야 된다 
	
	pos = 0;
	sym = read_item();
	 
	while(eos_count<2){
		if(sym_type != eos){
			eos_count = 0;
			if(sym_type == operand){
				digit_push(sym -'0'); 
			}
			else{
			
				op2 = pop();
				op1 = pop();
			
				switch(sym_type){
					case plus: push(op1+op2); break;
					case minus: push(op1-op2); break;
					case times: push(op1*op2); break;
					case divide: push(op1/op2); break;
					case mod: push(op1%op2); break;
				}
			}
		}
		else{//널값이 읽어지는 경우 
			if(digit_stack_top > -1){//변환해야 하는 숫자가 있다면 계산스택에 푸시한다 
				push(trans_digit());
			}
			//널값카운트 변수 증가시킨다	
			eos_count++;
		}
		sym = read_item();
	}
	return pop();
}

char read_item(void){

	char sym;
    sym = postfix[pos++];
	
	switch(sym){
		
		case '(': 
			sym_type= open_b;
			break;
		case ')': 
			sym_type= close_b;
			break;
		case '+': 
			sym_type= plus;
			break;
		case '-': 
			sym_type= minus;
			break;
		case '*': 
			sym_type= times;
			break;
		case '/': 
			sym_type= divide;
			break;
		case '%': 
			sym_type= mod;
			break;
		case '\0': 
			sym_type= eos;
			break;
		default: sym_type= operand;		
	}
	return sym;
}

//후위수식을 계산 할떄 사용하는 스택 메소드 
void push(int item){
	if(top>= 49){
		printf("stack full\n");
		return;
	}
	eval_stack[++top] = item;
	print_stack();
}

int pop(void){
	if(top<0){
		printf("stack empty\n");
		return 0;
	}
	return eval_stack[top--];
}

void print_stack(void){
	int i= top;
   	printf("\neval stack: ");
	while(eval_stack[i]){
   		printf("%d ",eval_stack[i]);
		i--;
	}
	printf("\n");
	
}

//실제 수로 변환하기 스택구조 이용하여 계산하기 위한 수로 변환해준다 
int trans_digit(void){
	
	int i;
	int ten = 1;
	int digit= 0;
	
	for(i= digit_stack_top;digit_stack_top> -1 ;){
		digit += ten * digit_pop();
		ten *= 10;	
	}
	return digit;
}

//실제 수로 변환하기 위한 스택의 메소드 
void digit_push(int item){
	if(digit_stack_top >= 49){
		printf("stack full\n");
		return;
	}
	digit_stack[++digit_stack_top] = item;
}

int digit_pop(void){
	if(digit_stack_top < 0){
		printf("stack empty\n");
		return 0;
	}
	return digit_stack[digit_stack_top--];
}

