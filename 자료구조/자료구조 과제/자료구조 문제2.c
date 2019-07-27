#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int count[2] ={0,0};//도는 횟수 저장 

typedef struct node_type* node_ptr;

struct node_type {
	int id;  //도시의 id (0, 1, 2, 3, …)
 	char name[10]; //도시 이름
 	int price; //도시 가격 1000 ~ 10000
 	int owner; //소유주의 id (0, 1, 2), 소유주가 없을 경우 -1
 	node_ptr llink;
 	node_ptr rlink;
};

typedef struct player_type{
	int id; //(0, 1, 2, ...)
 	char name[10]; // 이름
 	int balance; // 잔고
 	int direction; // (0, 1) 진행 방향 0 = left, 1 = right
	node_ptr node_pos; // 참가자가 현재 도착한 도시 노드에 대한 포인터
}player;

void append_city(node_ptr);
void Move_player(player* one);
int show_action_menu(int money,player* one);
void show_info(node_ptr home,player* one[]);

int main(void){
//초기 입력값 : 도시에 대한 정보는 코드 상에 미리 선언한다.
//도시 정보 입력 및 생성
//주요 메뉴 출력 및 선택 (0번 player가 진행할 차례)

	int i = 0;
	int select;
	int temp = 0;
	int asset0 = 0;
	int asset1 = 0;
		
	player* players[2];
	//플레이어1,2 구조체 포인터를 저장하는 배열 
	
	node_ptr home;//도시의 시작 노드를 담는 저장소 
	node_ptr temp1,temp2;//free를 위한 임시 포인터 

	//도시 생성하고도시이름들 코드상에 입력 
		
	srand(time(NULL));
	//난수 제조기
	 
	home = malloc(sizeof(struct node_type));//home 생성 
	
	strcpy(home->name,"HOME"); 
    home->rlink = home;
    home->llink = home;
    home->id = 0;
	home->owner = -1;
	home->price = 0;
	//home에는 주소와 이름,아이디만 입력
		
	append_city(home);
	//다른 여행지 노드를 home과 연결 
	//플레이어 만들고 초기값 설정  

	players[0] = malloc(sizeof(player));
	strcpy(players[0]->name,"MOON");
	players[0]->direction = 1;
	players[0]->id = 0;
	players[0]->node_pos = home;
	players[0]->balance = 3000+200;//월급과 주어진 돈지급 

	players[1] = malloc(sizeof(player));
	strcpy(players[1]->name,"Lee");
	players[1]->direction = 1;
	players[1]->id = 1;
	players[1]->node_pos = home;
	players[1]->balance = 3000+200;
	
	while(((players[0]->balance>=0)&&(players[1]->balance>=0))&&((count[0]<4)&&(count[1]<4))){
	    printf("1.Throw Dice\n2.Show City Info\n3.exit\n");
		printf("\nplayer[%d]. choose a menu: ",i); 
    	scanf("%d",&select);//scanf의 두번째 인자에는 주소값이어야 함!!!  
		switch(select){
    		case 1:
    			Move_player(players[i]); 
    			temp = show_action_menu(temp,players[i]);
    			i= (i+1)%2;//다음 플레이어 차례로 넘어간다 
				break;
    		case 2:
    			show_info(home,players);
				break;
			case 3:
				//할당받은 모든 힙데이터 해제해줘야 된다!!! 
	
				free(players[0]);
				free(players[1]);
			
				temp1 = home;
			
				do{ 
					temp2 = temp1;		
					temp1 = temp1->rlink;//옆 노드로 이동 
					free(temp2);//해제 
			
				}while(temp1 != home);
			
				return 0;
				
			default:
			   printf("주어진 번호 내에서 선택해주세요\n");			
		}
	}
	
	if((players[0]->balance)<0){
		printf("Player[0] lose Player[1] win!!\n");
	}
	if((players[1]->balance)<0){
		printf("Player[1] lose Player[0] win!!\n");
	}
	if((count[0]>2)||(count[1]>2)){
		//우승자를 가리기 위한 재산 측정 
		asset0 += players[0]->balance;
		asset1 += players[1]->balance;
	    
		temp1 = home->rlink;
	    
		while(temp1!=home){
			if((temp1->owner) != -1){//소유지 확인 
				if((temp1->owner)==0){
					asset0 += temp1->price;//재산에 추가 
				}
				if((temp1->owner)==1){
					asset1 +=  temp1->price;//재산에 추가 
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
	//힙 해제하기
	
	free(players[0]);
	free(players[1]);
			
	temp1 = home;
			
	do{ 
		temp2 = temp1;		
		temp1 = temp1->rlink;//옆 노드로 이동 
		free(temp2);//해제 
		
	}while(temp1 != home);
 
 	system("pause");
	return 0;
}

// 도시 정보를 받아서 노드를 malloc으로 생성한 후 양방향 순환 연결
//리스트에 추가한다.

void append_city(node_ptr prev){
	  
	node_ptr node;//새로 생긴 여행지 정보의 주소 임시 저장 
	int i;
    int price[10] = {1000,1000,1500,1500,2000,2000,2500,3000,3500,4000};	
	//게임의 난이도를 위해 큰 수는 되도록 적은 수 만큼 위치해놓는다 
	for(i=1;i<11;i++){

    	node = malloc(sizeof(struct node_type));
          
		node->id = i;
        node->owner = -1;
        
		node->rlink = prev->rlink;//이전 노드와 연결 
		node->llink = prev;//이전노드와 연결 
	
	    prev->rlink->llink = node;//현재노드와 연결 
		prev->rlink = node;//현재 노드와 연결
				 
		//도시 이름 입력 
		switch(i){
			case 1:
				strcpy(node->name,"중국");
				break;
			case 2:
				strcpy(node->name,"일본");
				break;
			case 3:
				strcpy(node->name,"미국");
				break;
			case 4:
				strcpy(node->name,"프랑스");
				break;
			case 5:
				strcpy(node->name,"스페인");
				break;
			case 6:
				strcpy(node->name,"이태리");
				break;
			case 7:
				strcpy(node->name,"러시아");
				break;
			case 8:
				strcpy(node->name,"홍콩");
				break;
			case 9:
				strcpy(node->name,"대만");
				break;
			case 10:
				strcpy(node->name,"태국");
				break;
		}
		
		node->price = price[rand()%10];//도시 가격랜덤입력		
		prev = node; 
	}
}

void Move_player(player* one){
	
	printf("\n");
	
	int move = 0;
	node_ptr temp;
	
	temp = one->node_pos;//현재 위치 가져오기 
	
	while(!move){
		move = rand()%5;//0이 제외한 주사위 숫자 랜덤지정 
	}
	printf("player[%d] dice: %d\n",one->id,move);
	//랜덤함수 사용하여 주사위 굴린다
	if(move == 1){
		one->direction = ((one->direction) + 1)% 2;
		if(one->direction){
			printf("움직이는 방향이 오른쪽으로 변경되었습니다\n"); 
		}	
		else{
			printf("움직이는 방향이 왼쪽으로 변경되었습니다\n");
		}
	}
	//주사위 1일 경우 현재 방향 바꾸기 
	if(one->direction){
		while(move){
			temp = temp-> rlink;
			move--;
			if(temp->id == 0){
				count[one->id] += 1;  
				one->balance += 200;
				printf("월급 입금완료\n");
			}//월급지급
		}
	}//1일 경우 오른쪽으로
	 
	else{
		while(move){
			temp = temp-> llink;
			move--;
			if(temp->id == 0){
				count[one->id] += 1;
				one->balance += 200;
				printf("월급 입금완료\n");
			}//월급지급 
		}
	}//0일 경우 왼쪽으로
	//방향에 따라 주사위 수 만큼 이동 
	one->node_pos = temp;
	//플레이어 현재 위치 정보 갱신하고 상태 출력 
	printf("Player[%d] moves to [%s]\n",one->id,one->node_pos->name); 
}

//참가자를 주사위의 눈 만큼
//순환 연결 리스트에서 이동시킨다.              

int show_action_menu(int money,player* one){
   node_ptr pos;
   int select,temp;
   
   printf("\n");
   pos = one->node_pos;//현재 위치 가져오기 
   
   if(money){
   	   one->balance += money;//이전에서 지불된 통행료 받기	   
   }
   
   if(!(pos->id)){//home에 도착한 경우 그냥 지나간다 
   	   printf("Player[%d] arrive at [%s]\n\n",one->id,pos->name);
       return 0;
   } 
				
   if(pos-> owner == -1){//주인이 없는 여행지이면서 home이 아닌 경우 
        printf("select(1.Buy 2.Pass) :");
		scanf("%d",&select);
		switch(select){
		    case 1:
		       	if((pos->price) <= (one->balance)){
			   		one->balance -= pos->price;//여행지 금액 지불 
					pos->owner = one->id;//소유자 정보 입력     
					printf("Player[%d] buy [%s]\n",one->id,pos->name); 
				}
				else{
					printf("Your balance is not enough to buy [%s]\n",pos->name);
				}   
				break;
			case 2:				   	    	
			   	break;
			default:		
			   printf("주어진 번호 내에서 선택해주세요\n");
		}	
		printf("\n");
		return 0;
	}
    
   else{//누군가의 소유지에 온 경우 
   	   //자기 자신의 소유지에 온 경우
       if(pos->owner == one->id){
           printf("select(1.Sell 2.Pass) :");
	   	   scanf("%d",&select);
	       switch(select){
	          case 1:
			      one->balance += (pos->price)/10*6;//소유지 매각 
			      pos->owner = -1;//소유자 정보 갱신     
		          printf("Player[%d] sell [%s]\n",one->id,pos->name); 
		      case 2:		
			      break;
		   
		      default:	
			      printf("주어진 번호 내에서 선택해주세요\n");	
	       }
       }//남의 소유지에 온 경우
   	   else{
   	   	   temp =  (int)(pos->price)/10*2;
           one->balance -= temp;//통행료 지불 
	       printf("Player[%d]에게 통행료[%d] 지급해야 합니다\n\n",one->node_pos->owner,temp);    
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

