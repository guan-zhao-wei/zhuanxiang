#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3 
#define COL 3

void menu()
{
	 printf("*************************************\n");
	 printf("********   1.play 0.exit   **********\n");
	 printf("*************************************\n");
}
void InitB0ard(char arr[ROW][COL],int row, int col)
{
	int i = 0;
	int j = 0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			 arr[i][j] = ' ';
		}
	}
}
void DisplayBoart(char arr[ROW][COL], int row,int col)
{
	int i = 0;
	int j = 0;
	 for(i=0;i<row;i++)
    {
		for(j=0;j<col;j++)
		{
			printf(" %c ", arr[i][j]);
			if(j<col-1)
			printf("|");
		}
		printf("\n");
		if(i<row-1)
	    {
			for(j=0;j<col;j++)
		    {
		     	printf("---");
		        if(j<col-1)
		 	    printf("|");
		    }
		    printf("\n");
          }
    }
}
void playermove(char arr[ROW][COL],int row,int col)
{
	int x = 0;
	int y = 0;
	while(1)
    {
  		printf("����������(1-%d)(1-%d)\n", row, col);
        scanf("%d%d", &x, &y);
		if(x>=1 && x<=row && y>=1 && y<=col)
		{
			if(arr[x-1][y-1] == ' ')
			{
			    arr[x-1][y-1] = '*';
			    break;
			}
			else
			printf("�����ѱ�ռ�ã�������ѡ��"); 
		}
		else
		printf("�������\n");
  	}
}
void ComputerMove(char arr[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("������\n");
    while(1)
    {
	    x = rand()%row;
	    y = rand()%col;
	    if(arr[x][y]==' ')
	    {
    		arr[x][y] = '#';
    		break;
    	}
    }
}

int IsFull(char arr[ROW][COL], int row, int col)
{
	int i =0;
	int j = 0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(arr[i][j]==' ')
			return 0;
		}
	}
	return 1;
}
char IsWin(char arr[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0; 
	//������ 
	for(i=0;i<row;i++)
	{
		if(arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][1]!=' ')
		{
			return arr[i][1];
		}
	}
	//������ 
	for(i=0;i<col;i++)
	{
		if(arr[0][i]==arr[1][i] && arr[1][i]==arr[2][i] && arr[1][i]!=' ')
		{
			return arr[1][i];
		}
	}
	//б����
	if(arr[0][0]==arr[1][1] && arr[1][1] == arr[2][2] && arr[1][1]!=' ')
	    return arr[1][1];
	if(arr[2][0]==arr[1][1] && arr[1][1]==arr[0][2] && arr[1][1]!=' ')
	    return arr[1][1];
    if(1 == IsFull(arr, ROW, COL))
    return 'Q';
    return 'C';
}
void game()
{
	char ret = 0;
	//char arr[3][3] = {0};//������#define����ĳ���������arr���к���֮������Ը��� 
  //������������Ϣ 
	char arr[ROW][COL];
	//��ʼ������ 
	InitB0ard(arr, ROW, COL);
	//��ӡ���� 
	DisplayBoart(arr, ROW,COL);
	//����
	while(1)
	{
		//������� 
		playermove(arr, ROW, COL);
		//��ӡ���� 
		DisplayBoart(arr, ROW, COL);
		//�ж���Ӯ 
		ret = IsWin(arr, ROW, COL );
		if(ret != 'C')
		{
			break;
		} 
		//�������� 
		ComputerMove(arr, ROW, COL);
		//��ӡ���� 
		DisplayBoart(arr, ROW,COL);
		ret = IsWin(arr, ROW, COL );
		if(ret != 'C')//ret='C'��ʾ���� 
		{
			break;
		}  
	} 
	if(ret=='*') 
	{
		printf("���Ӯ");
	}
	else if(ret=='#')
	{
		printf("����Ӯ");
	}
	else
	printf("ƽ��");//ret='Q'��ʾƽ�� 
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do{
		menu();
		printf("��ѡ��\n");
		scanf("%d", &input);
        switch(input)
        {
        	case 1:
        	{
	            game();
	        	break;
	        }
	        case 0:
	        {
        		printf("�˳���Ϸ\n");
				break; 
        	}
        	default: 
        	{
	        	printf("ѡ�����������ѡ��");
				break; 
	        }
        }
	}while(input);
	return 0;
}
/*
void mel(char arr[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while(1)
    {
  		printf("����������");
        scanf("%d%d", &x, &y);
		if(x>=1 && x<=row && y>=1 && y<=col)
		{
			if(arr[x-1][y-1] == ' ')
			{
			    arr[x-1][y-1] = '*';
			    break;
			}
			else
			printf("�����ѱ�ռ�ã�������ѡ��"); 
		}
		else
		printf("�������\n");   
  	}
}*/
