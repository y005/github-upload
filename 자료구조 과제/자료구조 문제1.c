#include<stdio.h>
#include<ctype.h>

//infix -postfix, postfix-evaluation (P.108 ���� ���� 18�� ����)
//���� ���� infix������ �Է� �޾� postfix�� ��ȯ�� �� ���� ����ؾ� 
//�� ��ȯ �������� ������ ���¸� ���� ��� �Ͻÿ�
//�ԷµǴ� infix ���Ŀ��� �ǿ����ڿ� ������ ���̿� ������ ���ٰ� �����Ѵ�
//postfix�� ȭ�鿡 ����� ���� �ǿ����ڿ� �ǿ����� �Ǵ� ������ ���̿� ������ ����
//�ּ� 3���� �̻��� infix ���� ���� ���Ͽ� ó�� 


char postfix[50];//���� ������ �����ϱ� ���� �迭 
int pos;//���� ���� �ε��� 
int index;

char token_stack[50];//������������ ��ȯ �� �� ���� ���� 
int token_top = -1;//���� ���� ��ȯ�� �����ڸ� ������ ���� ������ 


int eval_stack[50];//���������� ����ϱ� ���� ����
int top= -1;//���� ���� ���� �ǿ����ڸ� ������ ���� ������ 

int digit_stack[10];//���� ��ȯ�� ���� ���� 
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
				printf("�־��� ��ȣ������ �Է��ϼ���\n");
				break;
		}
	}
	
	system("pause");
	return 0;
}


//���ڻ����� ������ �ΰ��� �߰����ְ�  
void infix_to_postfix(void){
	char expr[50],sym,token;
	pos = 0;
	int i;
	index = 0;
	
	for(i=0;i<50;i++){
		expr[i] = '\0';
	}
	//�迭 �ʱ�ȭ 
	
	printf("Enter the expression:: ");
	scanf("%s",expr);//���� ���� �迭�� ���� 
	
	while(((token = expr[pos++]) != '\0')){
		
		if(isalnum(token)==4){
			postfix[index++] = token;
			//�ǿ����� ��½� 
		}
		else if(token == '('){
			push_token(token);
		}
		else if(token == ')'){
			while((sym = pop_token()) != '('){
				postfix[index++] = '\0';
				postfix[index++] = sym;
				//�������Ŀ� �����ڿ� �ΰ� �߰�		
			}
		}
		else{
			while((precendence(token_stack[token_top]) >= precendence(token))&&(token_top !=-1)){
				postfix[index++] = '\0';
				postfix[index++] = pop_token();
				//�������Ŀ� �����ڿ� �ΰ� �߰�		
			}
			postfix[index++] = '\0';
			//������ ���ڸ� �տ��� �ΰ� �߰�		
			push_token(token);
		}
		print_postfix(postfix); 
		print_token_stack(token_stack);
	}

	while((token_top != -1)){
		postfix[index++] = '\0';
		postfix[index++] = pop_token();
		//���� ���Ŀ� �����ڿ� �ΰ� �߰� 
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

//�������ĵ��� ����ؾ� ��
//�ǿ����ڸ� ���ÿ� �����ϰ�
//�����ڸ� ������ �ǿ����� �ΰ��� ������ ������  
//���ӵǴ� ���ڸ� ��ȯ�ϱ�
	
int eval_postfix(void){
	char sym;
	int op1,op2;
	int eos_count = 0;//�ΰ��� �ι� �̻��̸� �������� �����ؾ� �ȴ� 
	
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
		else{//�ΰ��� �о����� ��� 
			if(digit_stack_top > -1){//��ȯ�ؾ� �ϴ� ���ڰ� �ִٸ� ��꽺�ÿ� Ǫ���Ѵ� 
				push(trans_digit());
			}
			//�ΰ�ī��Ʈ ���� ������Ų��	
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

//���������� ��� �ҋ� ����ϴ� ���� �޼ҵ� 
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

//���� ���� ��ȯ�ϱ� ���ñ��� �̿��Ͽ� ����ϱ� ���� ���� ��ȯ���ش� 
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

//���� ���� ��ȯ�ϱ� ���� ������ �޼ҵ� 
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

