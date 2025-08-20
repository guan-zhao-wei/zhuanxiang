//计算1！+2！+.......n! 
/*
#include<stdio.h>
int game(int n)
{
	int i = 0;
	int j = 0;
	int ter = 0;
	int count = 0;
	for(i=1;i<=n;i++)
	{
	    ter = 1;
		for(j=1;j<=i;j++)
		{

			ter *= j;
		}
		count += ter;
	}
	return count;
}
int main()
{
	int n = 0;
	int tmp = 0;
	scanf("%d", &n);
	tmp = game(n);
	printf("tmp=%d\n", tmp);
	return 0;
} */
//数组何变量为什么会有无限循环 
/*
#include<stdio.h>
int main()
{
	int i = 0;//在内存栈中的地址高于arr的，因为栈中是先使用高地址再使用低地址 
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	//int i = 0;//此时i的地址就低于arr的了，就不会被死循环 
	for(i=0;i<=15;i++)//当此处i=15或比15大的数时程序会陷入死循环 
	{
		printf("赵微\n");
		printf("%p  %p\n", &i, &arr[15]);
		//发现arr[15]的地址与i的地址相同
		//原因在于局部变量是存储在栈中的，栈的存储是由先高地址后低地址的
		//当arr[i]越界访问就可能访问到变量i的地址
		//当arr[i]与i地址相同时，arr[i]=i=0;又重新陷入for循环 
		arr[i] = 0; 
	}
	return 0;
}*/
//strcpy函数的实现 
#include<stdio.h>
#include<string.h>
//第一种普通形式 
/*
void my_strcpy(char* p1, char* p2, int sz)
{
	 
	
int i = 0;
	for(i=0;i<sz;i++)
	{
		*(p1+i)=*(p2+i);
	}
	//printf("%s\n", p1);//也可以用printf(“arr1”）；语句打印 
	
}*/
//第二种更加完善高效的方法 
/*
void my_strcpy(char* p1, char* p2)
{
	if(p1 != NULL && p2 != NULL)//防止传入的参数位空 
	{
		while(*p2 != '\0')//此次拷贝不包含'\0' 
	    {
	     	*p1 = *p2;
	        p1++;
	        p2++;
	    }
	    *p1 = *p2;//将'\0'拷贝过去 
	}
} */
//第三种更加完善的方法·
/*
#include<assert.h> 

void my_strcpy(char* p1, char* p2)
{
	assert(p1 != NULL);//assert库函数是断言函数 
	assert(p2 != NULL);//如果（）内的条件满足则无事发生，如果不满足就会报错
	while(*p1++ = *p2++)//先把*p2的值赋给*p1，然后判断这个值是否不为'\0'再++ 
	{
		;
	} 
}*/
//第四种最严谨完善的方法 
/*
#include<assert.h> 
char* my_strcpy(char* p1,const char* p2)//const修饰变量*p，让*p不能被更改，防止循环条件被出错 
{
	char* ret = p1; 
	assert(p1 != NULL);//assert库函数是断言函数 
	assert(p2 != NULL);//如果（）内的条件满足则无事发生，如果不满足就会报错
	while(*p1++ = *p2++)//先把*p2的值赋给*p1，然后判断这个值是否不为'\0'再++ 
	{
		;
	} 
	return ret;//将函数类型由无返回值的void改为char*，更接近strcpy库函数 
}  
int main()
{
	char arr1[] = "############";
	int sz = sizeof(arr1)/sizeof(arr1[0]);
	char arr2[] = "weiwei";
	//用函数实现库函数strcpy
	//第一种传参 
	//my_strcpy(arr1, arr2, sz);
	//第二种传参
	//my_strcpy(arr1, arr2);
	//第三种更加完善的代码 
	//my_strcpy(arr1, NULL);//会再屏幕上报错Assertion failed: p2 != NULL, file C:\Users\管庆\Documents\C-Free\Temp\未命名1.cpp, line 87
	 //my_strcpy(arr1, arr2);
	 //第四种
	 printf("%s\n", my_strcpy(arr1, arr2)); 
	//strcpy(arr1,arr2);//把后面的字符拷贝到前面都变量中 
	printf("%s\n", arr1);
	//printf("%s\n", arr2);
	return 0;
} */

//const关键字在不同的位置修饰不同的变量
/*
#include<stdio.h>
int main()
{
	int a = 10;
	int n = 100;
	//const int a = 10;//此时const修饰了a不允许被*p改变，但一些编译器上面仍然允许被改变 
	//int* p = &a;
	//const int* p = &a;//此时const修饰的变量是*p，所以*p(a)不允许被改变,但是p可以被改变，例如p=&n这个语句是可以执行的
	//int* const p = &a;//此时const修饰的变量是p，所以*p(a)是可以被改变的，但是p不可以被改变
	const int* const p = &a;//此时const修饰的变量位*p和p一起被修饰，两个都不可以被改变 
	*p = 20;
	p = &n;  
	printf("%d\n", a);
	printf("%p %p\n", &a, p); 
	return 0;
}*/ 
