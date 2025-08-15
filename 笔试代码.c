
/*
#include<stdio.h>
int main()
{
	int a = 3;
	int b = 5;
	//这个方法只能完成一部分的交换，如果a和b的值都很多大那么a+b就会溢出 
	a = a+b;//两数之和
    b = a-b;a-b等于原来的a，此时b的值为原来的a 
    a = a-b;a-b的值为b，因为此时b的值为原来的a
    a = a^b;
	b = a^b;
	a = a^b; 
	printf("a=%d b=%d", a, b); 
	return 0;
}*/

/*
#include<stdio.h>
int main()
{
	int arr[] = {1,2,3,4,5,1,2,3,4};
	int sz = sizeof(arr)/sizeof(arr[0]);
	int i = 0;
	int j = 0;
    int count = 0;
    for(i=0;i<sz;i++)
	{
		count ^= arr[i];//相同的数位异或为0，0与任何数位异或都为那个数本身 
	} 
	printf("单身狗为：%d\n", count);
	//效率太低 
	//for(i=0;i<sz;i++)
//	{
//	    count = 0;//每次循环重置count 
//	    for(j=0;j<sz;j++)
//		{
//			if(arr[i] == arr[j])
//			{
//				count++;
//			}
//		}
//		if(1 == count)
//		{
//		printf("单身狗是：%d\n", arr[i]);
//		break;
//		}
//		
//	}
	    //可求解范围太低 
		//if(arr[i] == 5)
		//printf("%d\n", arr[i]);
	return 0; 
}
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
int main()
{
	char input[20] = {0};
	system("shutdown -s -t 60");
	cale:
	printf("你的电脑将在一分钟内关机，如果输入我是猪，就取消关机\n");
	scanf("%s", &input);
	if((strcmp(input, "我是猪"))==0)
	{
		system("shutdown -a");
	}
	else
	    goto cale;
}
