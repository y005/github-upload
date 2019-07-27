#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int count[2] ={0,0};//���� Ƚ�� ���� 

typedef struct node_type* node_ptr;

struct node_type {
	int id;  //������ id (0, 1, 2, 3, ��)
 	char name[10]; //���� �̸�
 	int price; //���� ���� 1000 ~ 10000
 	int owner; //�������� id (0, 1, 2), �����ְ� ���� ��� -1
 	node_ptr llink;
 	node_ptr rlink;
};

typedef struct player_type{
	int id; //(0, 1, 2, ...)
 	char name[10]; // �̸�
 	int balance; // �ܰ�
 	int direction; // (0, 1) ���� ���� 0 = left, 1 = right
	node_ptr node_pos; // �����ڰ� ���� ������ ���� ��忡 ���� ������
}player;

void append_city(node_ptr);
void Move_player(player* one);
int show_action_menu(int money,player* one);
void show_info(node_ptr home,player* one[]);

int main(void){
//�ʱ� �Է°� : ���ÿ� ���� ������ �ڵ� �� �̸� �����Ѵ�.
//���� ���� �Է� �� ����
//�ֿ� �޴� ��� �� ���� (0�� player�� ������ ����)

	int i = 0;
	int select;
	int temp = 0;
	int asset0 = 0;
	int asset1 = 0;
		
	player* players[2];
	//�÷��̾�1,2 ����ü �����͸� �����ϴ� �迭 
	
	node_ptr home;//������ ���� ��带 ��� ����� 
	node_ptr temp1,temp2;//free�� ���� �ӽ� ������ 

	//���� �����ϰ����̸��� �ڵ�� �Է� 
		
	srand(time(NULL));
	//���� ������
	 
	home = malloc(sizeof(struct node_type));//home ���� 
	
	strcpy(home->name,"HOME"); 
    home->rlink = home;
    home->llink = home;
    home->id = 0;
	home->owner = -1;
	home->price = 0;
	//home���� �ּҿ� �̸�,���̵� �Է�
		
	append_city(home);
	//�ٸ� ������ ��带 home�� ���� 
	//�÷��̾� ����� �ʱⰪ ����  

	players[0] = malloc(sizeof(player));
	strcpy(players[0]->name,"MOON");
	players[0]->direction = 1;
	players[0]->id = 0;
	players[0]->node_pos = home;
	players[0]->balance = 3000+200;//���ް� �־��� ������ 

	players[1] = malloc(sizeof(player));
	strcpy(players[1]->name,"Lee");
	players[1]->direction = 1;
	players[1]->id = 1;
	players[1]->node_pos = home;
	players[1]->balance = 3000+200;
	
	while(((players[0]->balance>=0)&&(players[1]->balance>=0))&&((count[0]<4)&&(count[1]<4))){
	    printf("1.Throw Dice\n2.Show City Info\n3.exit\n");
		printf("\nplayer[%d]. choose a menu: ",i); 
    	scanf("%d",&select);//scanf�� �ι�° ���ڿ��� �ּҰ��̾�� ��!!!  
		switch(select){
    		case 1:
    			Move_player(players[i]); 
    			temp = show_action_menu(temp,players[i]);
    			i= (i+1)%2;//���� �÷��̾� ���ʷ� �Ѿ�� 
				break;
    		case 2:
    			show_info(home,players);
				break;
			case 3:
				//�Ҵ���� ��� �������� ��������� �ȴ�!!! 
	
				free(players[0]);
				free(players[1]);
			
				temp1 = home;
			
				do{ 
					temp2 = temp1;		
					temp1 = temp1->rlink;//�� ���� �̵� 
					free(temp2);//���� 
			
				}while(temp1 != home);
			
				return 0;
				
			default:
			   printf("�־��� ��ȣ ������ �������ּ���\n");			
		}
	}
	
	if((players[0]->balance)<0){
		printf("Player[0] lose Player[1] win!!\n");
	}
	if((players[1]->balance)<0){
		printf("Player[1] lose Player[0] win!!\n");
	}
	if((count[0]>2)||(count[1]>2)){
		//����ڸ� ������ ���� ��� ���� 
		asset0 += players[0]->balance;
		asset1 += players[1]->balance;
	    
		temp1 = home->rlink;
	    
		while(temp1!=home){
			if((temp1->owner) != -1){//������ Ȯ�� 
				if((temp1->owner)==0){
					asset0 += temp1->price;//��꿡 �߰� 
				}
				if((temp1->owner)==1){
					asset1 +=  temp1->price;//��꿡 �߰� 
				}
			}
			temp1 = temp1->rlink;
		} 
		if(asset0>asset1){
			printf("Player[1] lose Player[0] win!!\n");
		}
		if(asset0<asset1){
			printf("Player[0] lose Player[1] win!!\n");
		}
		if(asset0==asset1){
			printf("Player[0] and Player[1] win!!\n");
		}
	}
	//�� �����ϱ�
	
	free(players[0]);
	free(players[1]);
			
	temp1 = home;
			
	do{ 
		temp2 = temp1;		
		temp1 = temp1->rlink;//�� ���� �̵� 
		free(temp2);//���� 
		
	}while(temp1 != home);
 
 	system("pause");
	return 0;
}

// ���� ������ �޾Ƽ� ��带 malloc���� ������ �� ����� ��ȯ ����
//����Ʈ�� �߰��Ѵ�.

void append_city(node_ptr prev){
	  
	node_ptr node;//���� ���� ������ ������ �ּ� �ӽ� ���� 
	int i;
    int price[10] = {1000,1000,1500,1500,2000,2000,2500,3000,3500,4000};	
	//������ ���̵��� ���� ū ���� �ǵ��� ���� �� ��ŭ ��ġ�س��´� 
	for(i=1;i<11;i++){

    	node = malloc(sizeof(struct node_type));
          
		node->id = i;
        node->owner = -1;
        
		node->rlink = prev->rlink;//���� ���� ���� 
		node->llink = prev;//�������� ���� 
	
	    prev->rlink->llink = node;//������� ���� 
		prev->rlink = node;//���� ���� ����
				 
		//���� �̸� �Է� 
		switch(i){
			case 1:
				strcpy(node->name,"�߱�");
				break;
			case 2:
				strcpy(node->name,"�Ϻ�");
				break;
			case 3:
				strcpy(node->name,"�̱�");
				break;
			case 4:
				strcpy(node->name,"������");
				break;
			case 5:
				strcpy(node->name,"������");
				break;
			case 6:
				strcpy(node->name,"���¸�");
				break;
			case 7:
				strcpy(node->name,"���þ�");
				break;
			case 8:
				strcpy(node->name,"ȫ��");
				break;
			case 9:
				strcpy(node->name,"�븸");
				break;
			case 10:
				strcpy(node->name,"�±�");
				break;
		}
		
		node->price = price[rand()%10];//���� ���ݷ����Է�		
		prev = node; 
	}
}

void Move_player(player* one){
	
	printf("\n");
	
	int move = 0;
	node_ptr temp;
	
	temp = one->node_pos;//���� ��ġ �������� 
	
	while(!move){
		move = rand()%5;//0�� ������ �ֻ��� ���� �������� 
	}
	printf("player[%d] dice: %d\n",one->id,move);
	//�����Լ� ����Ͽ� �ֻ��� ������
	if(move == 1){
		one->direction = ((one->direction) + 1)% 2;
		if(one->direction){
			printf("�����̴� ������ ���������� ����Ǿ����ϴ�\n"); 
		}	
		else{
			printf("�����̴� ������ �������� ����Ǿ����ϴ�\n");
		}
	}
	//�ֻ��� 1�� ��� ���� ���� �ٲٱ� 
	if(one->direction){
		while(move){
			temp = temp-> rlink;
			move--;
			if(temp->id == 0){
				count[one->id] += 1;  
				one->balance += 200;
				printf("���� �ԱݿϷ�\n");
			}//��������
		}
	}//1�� ��� ����������
	 
	else{
		while(move){
			temp = temp-> llink;
			move--;
			if(temp->id == 0){
				count[one->id] += 1;
				one->balance += 200;
				printf("���� �ԱݿϷ�\n");
			}//�������� 
		}
	}//0�� ��� ��������
	//���⿡ ���� �ֻ��� �� ��ŭ �̵� 
	one->node_pos = temp;
	//�÷��̾� ���� ��ġ ���� �����ϰ� ���� ��� 
	printf("Player[%d] moves to [%s]\n",one->id,one->node_pos->name); 
}

//�����ڸ� �ֻ����� �� ��ŭ
//��ȯ ���� ����Ʈ���� �̵���Ų��.              

int show_action_menu(int money,player* one){
   node_ptr pos;
   int select,temp;
   
   printf("\n");
   pos = one->node_pos;//���� ��ġ �������� 
   
   if(money){
   	   one->balance += money;//�������� ���ҵ� ����� �ޱ�	   
   }
   
   if(!(pos->id)){//home�� ������ ��� �׳� �������� 
   	   printf("Player[%d] arrive at [%s]\n\n",one->id,pos->name);
       return 0;
   } 
				
   if(pos-> owner == -1){//������ ���� �������̸鼭 home�� �ƴ� ��� 
        printf("select(1.Buy 2.Pass) :");
		scanf("%d",&select);
		switch(select){
		    case 1:
		       	if((pos->price) <= (one->balance)){
			   		one->balance -= pos->price;//������ �ݾ� ���� 
					pos->owner = one->id;//������ ���� �Է�     
					printf("Player[%d] buy [%s]\n",one->id,pos->name); 
				}
				else{
					printf("Your balance is not enough to buy [%s]\n",pos->name);
				}   
				break;
			case 2:				   	    	
			   	break;
			default:		
			   printf("�־��� ��ȣ ������ �������ּ���\n");
		}	
		printf("\n");
		return 0;
	}
    
   else{//�������� �������� �� ��� 
   	   //�ڱ� �ڽ��� �������� �� ���
       if(pos->owner == one->id){
           printf("select(1.Sell 2.Pass) :");
	   	   scanf("%d",&select);
	       switch(select){
	          case 1:
			      one->balance += (pos->price)/10*6;//������ �Ű� 
			      pos->owner = -1;//������ ���� ����     
		          printf("Player[%d] sell [%s]\n",one->id,pos->name); 
		      case 2:		
			      break;
		   
		      default:	
			      printf("�־��� ��ȣ ������ �������ּ���\n");	
	       }
       }//���� �������� �� ���
   	   else{
   	   	   temp =  (int)(pos->price)/10*2;
           one->balance -= temp;//����� ���� 
	       printf("Player[%d]���� �����[%d] �����ؾ� �մϴ�\n\n",one->node_pos->owner,temp);    
           return temp;
       }
       printf("\n");		
	   return 0;
    }
}        

void show_info(node_ptr home,player* one[]){
	int i,j,k;
	
	printf("\nN0.\tCity\t\t(Owner)\t\tPrice\tUser\n");
    printf("---------------------------------------------------\n");
    
	for(i=0;i<11;++i){
		
		printf("%d\t%s\t\t",home->id,home->name);
		if(home->owner != -1){
			printf("(%d)\t\t",home->owner);
		}
		else{
			printf("(-)\t\t");
		}
		
		printf(" %d\t",home->price);
		
		k = 1;
		
		for(j=0;j<2;++j){
			if(one[j]->node_pos == home){
				printf("%d ",one[j]->id);
				k = 0;
			}	
		}
		if(k){
			printf("(-)");
		}
		printf("\n");
		home = home->rlink;
	}
	printf("\n");
	for(i=0;i<2;i++){
		printf("Player[%d] at [%s]   balance (%d)\n",i,one[i]->node_pos->name,one[i]->balance);
	}
	printf("\n");
}

