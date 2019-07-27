#include<stdio.h>
#include<math.h>

//�̷� ã�� �˰������� �ִܰŸ��� ã�� ���� �ƴ� 
//�̷ο��� ���� �� �ִ� Ż�� ���θ� Ȯ�����ִ� �˰��� 
int maze[12][12];//�̷� ���� 1�̸� ���� ���� 0�̸� �ո� ���� 
int mark[12][12];//1�̸� �� �� 0�̸� ó�� �� �� 

//����ü �����
//�����̴� ���� ���� 
typedef struct move1{
	int vert;
	int horiz;
}move;  

//����ü �����
//���� ��� ���� ���� ���� 
//��,��,���� ���� 
typedef struct point1{
	int row;
	int col;
	int dir;
}point;  

move move[8] = [{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}];//���� ���� 

point stack[100];//���� ��� ���� �ִ� ���� �����ϴ� ���� 

int top = -1;
point pop(void);
void push(point); 
//���� ���� 

void random_maze(void);//���� �̷� ����� 

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
	//���ÿ� ������ ��ο�  �������� �߰� 
	while((top !=-1)&& (!found)){
		//��ο� ���� �ְ� ���� Ż���� ������ ��
		
		position = pop();
		row = position.row;
		col = position.col;
		dir = position.dir;
		//���� �� ����  
			
	    while((dir< 8)&&(!found)){
			next_row = row +move[dir].vert; 
			next_col = col +move[dir].horiz;
			//���� ����� ��ġ �̸�Ȯ���ϱ�
			if((next_row==10)&&(next_col==10)){
				found = 1;
				break;
				//������ �� ����Ž�� �ߴ�  
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
				//�ٸ� ������ �̵��ϸ鼭 ������ ���� ��� ���ÿ� ���� 
				//�� �� dir�� ++
				//�� �̻��� Ž���� ������ �� �ٸ� ���� Ž���� ����  
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
        //������� �����Լ� ���	
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


