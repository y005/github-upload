#include<stdio.h>
#include<stdlib.h>

typedef struct node* tree_ptr;

struct node{
	int data;
	tree_ptr left;
	tree_ptr right;
};
//연결리스트 형태의 노드 

tree_ptr queue[100];
	
void make_tree(tree_ptr temp,int count);
void preorder(tree_ptr ptr);
void inorder(tree_ptr ptr);
void postorder(tree_ptr ptr);
void levelorder(tree_ptr ptr);


int main(void){
	
	tree_ptr node;
			
	node = malloc(sizeof(struct node));
	make_tree(node,1);
	
	printf("preorder: ");
	preorder(node);	
	printf("\n");

	printf("inorder: ");
	inorder(node);
	printf("\n");
	
	printf("postorder: ");
	postorder(node);
	printf("\n");	
	
	printf("levelorder: ");	
	levelorder(node);
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

void preorder(tree_ptr ptr) {
	
	if(ptr){
		printf("%d ",ptr->data);
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

void inorder(tree_ptr ptr) {
	
	if(ptr){
		inorder(ptr->left);
		printf("%d ",ptr->data);
		inorder(ptr->right);
	}	
}

void postorder(tree_ptr ptr) {
	
	if(ptr){
		postorder(ptr->left);
		postorder(ptr->right);
		printf("%d ",ptr->data);
	}
}

tree_ptr popq(int*front,int rear){
	
	tree_ptr temp;
	if(*front == rear){
		printf("empty queue");
	    return NULL;
	}
	temp = queue[++(*front)];
	return temp;
	//큐의 프런트 인덱스는 빈 공간을 가르키므로 
	//한 칸 더해야 함 
} 

void addq(int* rear,tree_ptr node){
	if(*rear == 100-1){
		printf("full queue");
	    return; 
	}
	queue[++(*rear)] = node;
	return;
}

void levelorder(tree_ptr ptr){

	int front = -1;
	int rear = -1; 
	
	if(!ptr){
		return;
	}
	addq(&rear,ptr);
	for(;;){
		ptr = popq(&front,rear);
		if(ptr){
			printf("%d ",ptr->data);
			if(ptr->left){
	     	addq(&rear,ptr->left);
			}
			if(ptr->right){
			addq(&rear,ptr->right);
			}
		}
		else{
			break;
		}
	}
}
