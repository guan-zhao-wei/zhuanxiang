//一维数组 
/*
#include<stdio.h>
int main()
{
	int arr[10] = {1,2,3,4,5};//不完全初始化数组，剩下的元素默认初始化为0
	int arr1[5] = {1,2,3,4,5};//初始化数组
	char arr3[] = {'a','b','c'};
	char arr4[] = "abc";
	int i = 0;
	for(i=0;i<5;i++)
	printf("%p\n", &arr1[i]);//0308FA40,0308FA44,0308FA48,0308FA4C,0308FA50,数组元素在内存中是连续存放的 
	//printf("arr3=%s arr4=%s\n", arr3, arr4);//arr3arr4不一样 
	return ;
}
*/
//二维数组
//#include<stdio.h>
//int main()
//{
//	//int arr[3][4] = {1,2,3,4,5};//这是表示三行四列的数组。初始化是第一行存储满后，进入第二行，满了进入第三行;
//	int arr[3][4] = {{1,2,3},{4},{5}};//将1，2，3存入第一行数组，4存入第二行，5存入第三行
//	//int arr1[][] = {1,2,3,4,5,6,7,8};//这样初始化二维数组是不行的
//	//int arr2[][] = {{1,2,3,4},{5,6,7,8}};//这样也不可以
//	//int arr3[2][] = {1,2,3,4,5,6,7,8};//这样也不行列不可以省略
//	//int arr4[][4] = {1,2,3,4,5,6,7,8};//这样初始化可以，行可以省略，列不可以省略
//	int i = 0;
//	int j = 0;
//	for(i=0;i<3;i++)
//	{
//		for(j=0;j<4;j++)
//		//printf("%d", arr[i][j]);
//		printf("&arr[%d][%d]=%p\n", i, j, &arr[i][j]);//二维数组的在内存中也是连续存放的如&arr[0][2]=02E5F958，&arr[0][3]=02E5F95C，&arr[1][0]=02E5F960，&arr[1][1]=02E5F964，&arr[1][2]=02E5F968 
//		//printf("\n");
//	} 
//}
//冒泡排序 
#include<stdio.h>
int bubble_sort(int arr[], int sz)
{
	int i = 0;
	int tmp = 0;
	int j = 0;
	int flog = 1;//优化语句 
	for(i=0;i<=sz-1;i++)//要进行sz-1次的冒泡排序 
	{
		for(j=0;j<sz-1-i;j++)//如果输入的数组是12345排好的
		{
			  if(arr[j]>arr[j+1])//arr[0]arr[1]比不满足进入j++然后arr[1]arr[2]比...... 
			{
				tmp = arr[j];
	            arr[j] = arr[j+1];
				arr[j+1] = tmp;
				flog = 0;//优化语句	 
			}
		}
		if(1==flog)//优化语句 
		    break;//比完发现都满足就直接跳出循环，不必再i++ 
	}
}
int main()
{
	int arr[] = {10,9,8,7,6,5,4,3,2,1};
	int sz = sizeof(arr)/sizeof(arr[0]);
	int i = 0;
	bubble_sort(arr,sz);
    for(i=0;i<=sz-1;i++)
    {
    	printf("%d", arr[i]);
    }
    //printf("%p\n", &arr);//此时打印的是整个数组的地址，只是只显示首元素地址
    //printf("%p\n", &arr+1);//此时打印的值跳过了arr整个数组 
	//printf("%p\n",arr);//此时只打印首元素地址
	//printf("%p\n", arr+1);//此时打印的是第二个元素的地址 
	return 0;
}
