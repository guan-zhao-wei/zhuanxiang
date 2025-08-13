#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 9//设置两个数组的行列 
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EASY_COUNT 10//设置雷的个数 

void menu()
{
	printf("********************************\n");
	printf("********  1.play  **************\n");
	printf("********  0.exit  **************\n");
	printf("********************************\n");
}
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for(i=0;i<rows;i++)
	{
		for(j=0;j<cols;j++)
		{
			board[i][j] = set;
		}
	}
}
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for(i=0;i<=col;i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for(i=1;i<=row;i++)
	{
		printf("%d ", i);
		for(j=1;j<=col;j++)
		{
		printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
void SetMine(char board[ROWS][COLS], int row, int col)
{
	int conut = EASY_COUNT;
	while(conut)
	{
		int x = rand()%row+1;
	    int y = rand()%col+1;
		if(board[x][y]=='0')
		{
			board[x][y] = '1';
			conut--;
		}
	}
}
int get_mine_conut(char mine[ROWS][COLS], int x, int y)
{
	return mine[x-1][y]+mine[x-1][y-1]+mine[x][y-1]+
	       mine[x+1][y-1]+mine[x+1][y]+mine[x+1][y+1]+
		   mine[x][y+1]+mine[x-1][y+1]-8*'0';//'0'-'0'=0,'1'-'0'=1的，所以让他们全部减字符0再相加就知道有几个字符1（地雷） 
} 
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row,int col)
{
	int x = 0;
	int y = 0;
	int count = 0;
	int win = 0;
	while(win < row*col-EASY_COUNT)
	{
		printf("请输入排查雷的坐标");
	    scanf("%d%d", &x,&y);
	    if(x>=1&&x<=row && y>=1&&y<=col)
	    {
		    if(mine[x][y]=='1')
		   {
			    printf("很遗憾，你踩到雷了\n");
			    DisplayBoard(mine, row, col);
			    break;
		   }
		   else
		   {
   			    count = get_mine_conut(mine,x,y);
   			    show[x][y] = count+'0';
   			    DisplayBoard(show, ROW, COL);
   			    win++;
   		   }
	    }
	    else
	    {
		    printf("输入错误，请重新输入\n");
	    } 
	}
	if(win == row*col-EASY_COUNT)
	{
		printf("恭喜你排雷成功\n"); 
		DisplayBoard(mine, row, col);
	}
}
void game()
{
	//布置雷的信息
	char mine[ROWS][COLS] = {0}; 
	//排查雷的信息
	char show[ROWS][COLS] = {0};
	//初始化棋盘
	InitBoard(mine, ROWS, COLS, '0');
    InitBoard(show, ROWS, COLS, '*');
    //打印棋盘
	//DisplayBoard(mine, ROW, COL);//打印出来给自己看的游戏开始不用打印 
	DisplayBoard(show, ROW, COL);
	//布置雷
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);//打印出来看有无对错的
	//扫雷
	FindMine(mine, show, ROW, COL);
	//DisplayBoard(show, ROW, COL);  
} 
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do{
		menu();
		printf("请选择");
		scanf("%d", &input);
		switch(input)
		{
			case 1:
			    game();
			    break;
			case 0:
			printf("退出游戏\n");
			break;
			default:
			printf("输入错误，请重新输入\n");
		}
	}while(input);
	return 0;
}
