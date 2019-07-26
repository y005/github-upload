#include<stdio.h>
#include<math.h>

//미로 찾기 알고리즘으로 최단거리를 찾는 것이 아닌 
//미로에서 나갈 수 있는 탈출 여부를 확인해주는 알고리즘 
int maze[12][12];//미로 정보 1이면 막힌 상태 0이면 뚫린 상태 
int mark[12][12];//1이면 간 곳 0이면 처음 간 곳 

//구조체 만들기
//움직이는 방향 정보 
typedef struct move1{
	int vert;
	int horiz;
}move;  

//구조체 만들기
//가는 경로 위에 점의 정보 
//행,렬,방향 정보 
typedef struct point1{
	int row;
	int col;
	int dir;
}point;  

move move[8] = [{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}];//가능 방향 

point stack[100];//가는 경로 위에 있는 점을 보관하는 공간 

int top = -1;
point pop(void);
void push(point); 
//스택 구현 

void random_maze(void);//랜덤 미로 만들기 

int main(void){
	
	int found = 0;
	int row,col,dir;
	int next_row,next_col;
	point position;
	
	
	for(i=0;i<12;i++){
		maze[0][i] = 1;
		maze[11][i] = 1;
		//horizional wall
	}
	for(i=0;i<12;i++){
		maze[i][0] = 1;
		maze[i][11] = 1;
		//vertical wall
	}
	
	random_maze();
	
	stack[0].row = 1;
	stack[0].col = 1;
	stack[0].dir = 2;
	top = 0;
	//스택에 시작점 경로에  수동으로 추가 
	while((top !=-1)&& (!found)){
		//경로에 점이 있고 아직 탈출을 못했을 때
		
		position = pop();
		row = position.row;
		col = position.col;
		dir = position.dir;
		//현재 점 복사  
			
	    while((dir< 8)&&(!found)){
			next_row = row +move[dir].vert; 
			next_col = col +move[dir].horiz;
			//다음 경로의 위치 미리확인하기
			if((next_row==10)&&(next_col==10)){
				found = 1;
				break;
				//도착점 일 때는탐색 중단  
			}
			else if((mark[next_row][next_col]==0)&&(maze[next_row][next_col]==0)){
				
				mark[next_row][next_col]= 1;
				position.row = row;
				position.col = col;
				position.dir = ++dir;
				push(position);
				row = next_row;
				col = next_col;
				dir = 0; 
				//다른 점으로 이동하면서 현재의 점을 경로 스택에 저장 
				//이 때 dir는 ++
				//더 이상의 탐색이 실패할 때 다른 방향 탐색을 위한  
			}
			else{
				++dir;
			}
		}	 
	}
    
    if(found){
    	printf("ESCAPE SUCCESS\n");
	}
	else{
		printf("FAILED!!\n");
	}	

	system("pause");
} 

void random_maze(void){

	int i,j;
	
	for(i=1;i<12;i++){
		for(j=1;j<12;j++){
	
		}	
	}
        //벽만들기 랜덤함수 사용	
}


point pop(void){
	if(top == -1){
		printf("empty stack!!\n");
	    return -999;	
	}
	return stack[top--];
}

void push(point item){
	if(top == 99 ){
		printf("full stack!!\n");
		return;
	}
	stack[++top] = item;
}


