#include<stdio.h>
#include<stdlib.h>

typedef struct node* thread_ptr;

struct node{
	int data;
	thread_ptr left;
	short int left_thread;
	thread_ptr right;
	short int right_thread;
};
//연결리스트 형태의 노드 

void make_tree(thread_ptr temp,int count);
void inorder(thread_ptr ptr);
thread_ptr successor(thread_ptr tree);

int main(void){
		
		thread_ptr node;

		node = malloc(sizeof(struct node));
		make_tree(node,1);
		inorder(node);	
	
	system("pause");
	return 0;
}

void make_tree(thread_ptr temp,int count){
	
	temp->data = count;
	
	if(count>2){
		temp->left_thread = 1;
		temp->right_thread = 1;
		temp->left = NULL;
		temp->right = NULL;
		return;
	}
	
	temp->left_thread = 0;
	temp->right_thread = 0;
	
	temp->left = malloc(sizeof(struct node));
	temp->right = malloc(sizeof(struct node));
		
	count++;
		
	make_tree(temp->left,count);
	make_tree(temp->right,count);
}


void inorder(thread_ptr ptr){
	
	thread_ptr temp;
	
	if(ptr){
		inorder(ptr->left);
		printf("%d ",ptr->data);
		inorder(ptr->right);	
	}
	
	
}

void thread_inorder(thread_ptr tree) {
	
	thread_ptr temp = tree;
	for(;;){
		temp = (thread_ptr)successor(temp);
		if(temp==tree){break;}
		printf("%d",temp->data);
	}
}

thread_ptr successor(thread_ptr tree){
	thread_ptr temp;
	temp = tree->right;
	if(!(tree->right_thread)){
		while(!(temp->left_thread)){
			temp = temp->left;
		}
	}
	return temp;
}
