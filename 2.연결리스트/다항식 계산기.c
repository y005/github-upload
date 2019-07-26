#include<stdio.h>
#include<stdlib.h> 

//다항식 계산기 만들기
typedef struct poly_node1{
	int coef;
	int expon;
	struct poly_node1* link;
}poly_node; 

typedef poly_node* poly_ptr;

poly_ptr list;//더한 식을 모아놓은 장소 

poly_ptr add_poly(poly_ptr,poly_ptr);
void attach(int,int,poly_ptr*);
void print(poly_ptr);
 
int main(void){
	
	poly_ptr node1,node2,node3;
	poly_ptr node4,node5,node6;
	
	node1 = (poly_ptr)malloc(sizeof(poly_node));
    node1->coef = 5;
	node1->expon = 12;

	node2 = (poly_ptr)malloc(sizeof(poly_node));
    node2->coef = -6;
	node2->expon = 8;
	node1->link = node2;
	
	node3 = (poly_ptr)malloc(sizeof(poly_node));
    node3->coef = 13;
	node3->expon = 3;
	node2->link = node3;
	
	node3->link = NULL;
	
	node4 = (poly_ptr)malloc(sizeof(poly_node));
    node4->coef = 10;
	node4->expon = 15;
	
	node5 = (poly_ptr)malloc(sizeof(poly_node));
    node5->coef = 4;
	node5->expon = 8;
	node4->link = node5;
	
	node6 = (poly_ptr)malloc(sizeof(poly_node));
    node6->coef = 9;
	node6->expon = 0;
	node5->link = node6;
	
	node6->link = NULL;
	
	print(node1);
	print(node4);
	
	list = add_poly(node1,node4);
	
	print(list);
	
	
	system("pause");
	return 0;
} 

poly_ptr add_poly(poly_ptr poly_a,poly_ptr poly_b){
   int sum;
   poly_ptr front,rear,temp;
   
   front = (poly_ptr)malloc(sizeof(poly_node));
   rear = front;
   //더한 다항식을 보관하기 위한 준비	
   
   while(poly_a&&poly_b){ 
	   if((poly_a->expon)>(poly_b->expon)){
   	       attach(poly_a->coef,poly_a->expon,&rear);
		   poly_a = poly_a->link; 	     
       }
       else if((poly_a->expon) == (poly_b->expon)){
   	       sum = (poly_a->coef)+ (poly_b->coef);
		   if(sum){
	          	attach(sum,poly_a->expon,&rear);
	          	poly_a = poly_a->link; 
   				poly_b = poly_b->link; 
	       }
	   }
   	   else{
   	   	   attach(poly_b->coef,poly_b->expon,&rear);   
	   	   poly_b = poly_b->link; 
	   }	
   }
   while(poly_a){
       attach(poly_a->coef,poly_a->expon,&rear);   
	   poly_a = poly_a->link;	
   }
   while(poly_b){
       attach(poly_b->coef,poly_b->expon,&rear);   
  	   poly_b = poly_b->link;
   }	
   
   rear->link = NULL;
   temp = front;
   front = front->link; 
   free(temp);
   //빈 첫 노드를 없애주자
   return front;	
}

void attach(int coef1,int expon1,poly_ptr* ptr){
	
	poly_ptr node;
	
	node = (poly_ptr)malloc(sizeof(poly_node));
	if(!node){
		printf("NO MORE HEAP MEMORY\n");
		return; 
	}
	node->coef = coef1;
	node->expon = expon1;
	//노드 생성 
	
	(*ptr)->link = node;
	*ptr = node;
	//큐의 리어를 갱신 
}	
	
void print(poly_ptr list){
	poly_ptr temp;
	temp = list;
	
	while(temp){
		printf("%d*X%d ",temp->coef,temp->expon);
		temp = temp->link;
	}
	printf("\n");
	
}






