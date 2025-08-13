#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 9//����������������� 
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EASY_COUNT 10//�����׵ĸ��� 

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
		   mine[x][y+1]+mine[x-1][y+1]-8*'0';//'0'-'0'=0,'1'-'0'=1�ģ�����������ȫ�����ַ�0����Ӿ�֪���м����ַ�1�����ף� 
} 
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row,int col)
{
	int x = 0;
	int y = 0;
	int count = 0;
	int win = 0;
	while(win < row*col-EASY_COUNT)
	{
		printf("�������Ų��׵�����");
	    scanf("%d%d", &x,&y);
	    if(x>=1&&x<=row && y>=1&&y<=col)
	    {
		    if(mine[x][y]=='1')
		   {
			    printf("���ź�����ȵ�����\n");
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
		    printf("�����������������\n");
	    } 
	}
	if(win == row*col-EASY_COUNT)
	{
		printf("��ϲ�����׳ɹ�\n"); 
		DisplayBoard(mine, row, col);
	}
}
void game()
{
	//�����׵���Ϣ
	char mine[ROWS][COLS] = {0}; 
	//�Ų��׵���Ϣ
	char show[ROWS][COLS] = {0};
	//��ʼ������
	InitBoard(mine, ROWS, COLS, '0');
    InitBoard(show, ROWS, COLS, '*');
    //��ӡ����
	//DisplayBoard(mine, ROW, COL);//��ӡ�������Լ�������Ϸ��ʼ���ô�ӡ 
	DisplayBoard(show, ROW, COL);
	//������
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);//��ӡ���������޶Դ��
	//ɨ��
	FindMine(mine, show, ROW, COL);
	//DisplayBoard(show, ROW, COL);  
} 
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do{
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		switch(input)
		{
			case 1:
			    game();
			    break;
			case 0:
			printf("�˳���Ϸ\n");
			break;
			default:
			printf("�����������������\n");
		}
	}while(input);
	return 0;
}
