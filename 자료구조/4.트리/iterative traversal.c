#include<stdio.h>
#include<stdlib.h>

typedef struct node* tree_ptr;

struct node{
	int data;
	tree_ptr left;
	tree_ptr right;
};
//���Ḯ��Ʈ ������ ��� 

tree_ptr stack[100];
tree_ptr stack1[100];

void make_tree(tree_ptr temp,int count);
void push(int* top,tree_ptr node);
tree_ptr pop(int* top);
void push1(int* top,tree_ptr node);
tree_ptr pop1(int* top);
void iterative_preorder(tree_ptr node);
void iterative_inorder(tree_ptr node);
void iterative_postorder(tree_ptr node);

int main(void){
	
	tree_ptr node;
			
	node = malloc(sizeof(struct node));
	make_tree(node,1);

	printf("preorder: ");	
	iterative_preorder(node);
	printf("\n");
	
	printf("inorder: ");
	iterative_inorder(node);
	printf("\n");
	
	printf("postorder: ");
	iterative_postorder(node);
	printf("\n");

	system("pause");	 
	return 0;
}


void make_tree(tree_ptr temp,int count){
	
	temp->data = count;
	
	if(count>2){
		temp->left = NULL;
		temp->right = NULL;
		return;
	}
	
	temp->left = malloc(sizeof(struct node));
	temp->right = malloc(sizeof(struct node));
		
	count++;
		
	make_tree(temp->left,count);
	make_tree(temp->right,count);
}

void push(int* top,tree_ptr node){
	if(*top== 100-1){
		printf("stack full");
		return;
	}
	stack[++(*top)] = node;
}

tree_ptr pop(int* top){
    tree_ptr temp;
    
	if(*top<0){
		printf("empty stack");
		return NULL;
	}
	
	temp = stack[*top];
    stack[*top] = NULL;
	(*top)--;  
    return temp;
}
void push1(int* top,tree_ptr node){
	if(*top== 100-1){
		printf("stack full");
		return;
	}
	stack1[++(*top)] = node;
}

tree_ptr pop1(int* top){
    tree_ptr temp;
    
	if(*top<0){
		printf("empty stack");
		return NULL;
	}
	
	temp = stack1[*top];
    stack1[*top] = NULL;
	(*top)--;  
    return temp;
}

void iterative_preorder(tree_ptr node){
	
	int top = -1;//���� ����� ���� �ʱ�ȭ(�迭�� �������� ����) 
	
	if(!node){
		return;
	}
	
	push(&top,node);//root�� ���ÿ� �߰� 
	
	while(top>-1){
		node = pop(&top);
		printf("%d ",node->data);	
		if((node->right)){
			push(&top,node->right);
		}//������ �ڽ��� ���� ���ÿ� Ǫ�� 
		if((node->left)){
			push(&top,node->left);
		}//���� ��µǴ� ���� �ڽ��� ���߿� ���ÿ� Ǫ�� 
	}
}

void iterative_inorder(tree_ptr node){
	
	int top = -1;//���� ����� ���� �ʱ�ȭ(�迭�� �������� ����) 

	for(;;){
		for(;node;node=node->left){
			push(&top,node);
		}
		node = pop(&top);
		if(!node){
			break;
		}
		printf("%d ",node->data);
		node = node->right;
	}
}

void iterative_postorder(tree_ptr node){
	
	int top = -1;//���� ����� ���� �ʱ�ȭ(�迭�� �������� ����) 
	int top1 = -1;
	
	if(!node){
		return;
	}
	
	push(&top,node);//root�� ���ÿ� �߰� 
	
	while(top>-1){
		 
		node = pop(&top); 
		
		push1(&top1,node);//���߿� �� ����� ���� ���ÿ� Ǫ��
						  //������ �ڽ��� ���� ���;��� 
		
		if((node->right)){
			push(&top,node->left);
		}//���� �ڽ��� ���� ���ÿ� Ǫ�� 
		if((node->left)){
			push(&top,node->right);
		}//���߿� ��µǴ� �������ڽ��� ���ÿ� Ǫ�� 
	}
	while(top1>-1){
		printf("%d ",pop1(&top1)->data);//��� 
	}
}

