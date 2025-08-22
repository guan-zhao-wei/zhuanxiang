/*
#include<stdio.h>
int main()
{
	char arr[] = "abcdefg";
	char* pc = arr;//数组名表示首元素地址，所以pc=arr，它两现在相同 
	printf("%s\n", arr);//printf函数调用数组时，从首元素开始打印直到遇到\0 
	printf("%s\n", pc);
	return 0;
}*/
/*
#include<stdio.h>
int main()
{
	const char* pc = "abcdef";//"abcdef"是一个常量字符串，他不是将字符串存到指针pc中，是把首元素地址存到指针pc中
	//*pc = 'w'; 上面这个字符串是常量字符串，不能更改，所以在前面加上const 
	printf("%c\n", *pc);//打印结果为a，所以上面这个语句的意思是把字符串首元素地址存到pc中 
	printf("%s\n", pc);
	return 0;
} */
/*
#include<stdio.h>
int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "abcdef";
	const char* p1 = "abcdef";
	const char* p2 = "abcdef";
	if(arr1 == arr2)//arr1和arr2是两个不同的数组，他们的首地址也必然不同 
	{
		printf("zhaozhao\n");
	}
	else{
		printf("weiwei\n");
	}
	if(p1==p2)//p1 p2调用的是同一个常量字符串即同一个字符串首字符的地址，所以他们的地址相同 
	 
	{
		printf("zhaozhao\n");
	}
	else{
		printf("weiwei\n");
	}
	printf("%p %p\n", p1, p2);
	return 0;
}*/

/*
//指针数组--存放指针的数组 
#include<stdio.h>
int main()
{
	int arr1[] = {1, 2, 3, 4, 5};
	int arr2[] = {2, 3, 4, 5, 6};
	int arr3[] = {3, 4, 5, 6, 7};
	int* parr[] = {arr1, arr2, arr3};
	//此时的parr就相当于一个二位数组 
	int i = 0;
	int j = 0;
	for(i=0;i<3;i++)//parr[0]的就是arr1的即arr1的首元素地址 
	{
		for(j=0;j<5;j++)
		{
			printf("%d", *(parr[i]+j));//+j表示数组中的第j个元素--相当于parr[i][j]
			//printf("%d ", parr[i][j]); 
		}
		printf("\n");
	}
	return 0;
} */
//数组指针--存放数组地址的指针
/*
#include<stdio.h>
 int main()
 {
 	int arr1[10] = {1,2,3,4,5,6,7,8,9,10};
 	//int* p[10];//指针数组 
 	int (*p)[10] = &arr1;//数组指针--这个指针存放着数组的地址 
    int i = 0;
    for(i=0;i<10;i++)
    {
    	printf("%d\n", *(*p+i));//*p==arr1
    	printf("%d\n", (*p)[i]);//打印结果完全相同 
    }
 	return 0;
 }*/

/*
#include<stdio.h>
int main()
{
    char* arr[5]; 
    char* (*pa)[5];//pa是变量，*pa说明变量是一个指针，[5]说明指针指向的是数组及元素个数，char* 表示指向的数组的元素的类型
	int (*arr[5])[5];//arr是一个数组，数组中的每个元素都是一个指针，每个指针都指向了一个数组，这个数组有5个元素，元素类型是int型 
    return 0;
 }
*/

//函数指针--存放函数地址的指针 

/*
#include<stdio.h>
int Add(int x, int y)
{
	int z = 0;
	z = x + y;
	return z;
} 
int main()
{
	int sum = 0;
	sum = Add(3, 2);
	//int (*p)[10] = &arr;//数组指针 
	int (*p)(int, int) = Add;//这就是函数指针，类型就是函数去掉函数名，与数组相似 
	printf("%p\n%p\n", p, Add);//004012F0,004012F0两个地址完全相同//函数名本身就是一个地址，与数组相似 
	printf("%d\n", (*p)(3, 2));//这也是函数调用，*p==Add
	printf("%d\n", p(2, 3)); //这也是函数调用，函数名本身就是地址，所以p==Add 
	printf("%d\n", sum);
	return 0;
}*/
//语句分析 
/*
#include<stdio.h>
int main()
{
	(*(void(*)())0)();//void(*)()是一个函数指针类型
	//(void(*)())0是将0强制类型转换为void(*)()类型,即一个函数指针类型，然后解引用这个函数指针 
	//所以(*(void(*)())0)就是一个函数，(*(void(*)())0)()就是一次函数调用，无参数0地址处函数调用
	 
	 void (*signal(int, void (*)(int)))(int);//signal()是一个函数，他的参数有两个一个是整型，一个是函数指针类型，这个函数指针参数是int类型，返回值是void类型 
	 //signal函数的返回类型是把函数去掉之后剩下的void(*)(int),也是一个函数指针，它的参数也是int类型，返回值也是void类型
	 typedef void(*pfun_t)(int);//typedef关键字的作用是重命名类型，将void (*)(int)类型命名为pfun_t。重命名的名称一定要写在*旁边 
	 pfun_t signal(int, pfun_t);//类型重命名后简化的语句 
	return 0;
} 
*/
/*
#include<stdio.h>
int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}
int main()
{
	//创建一个指针数组存储四个函数的地址
	int(*parr[4])(int, int) = {Add, Sub, Mul, Div};//这就是函数指针的数组，记住数组名一定要放在*旁边 
	int i = 0;
	for(i=0;i<4;i++)
	{
		printf("%d\n", parr[i](2, 3));//5,-1,6,0
	} 
	return 0;
} */

/*
#include<stdio.h>
char* my_strcpy(char* dest, const char* src)
{
	char* str = dest;
	while(*dest++ = *src++)
	{
		;
	}
	return str;
}
int main()
{
    char arr1[] = "######";
	char arr2[] = "abcdef";
	//正常函数调用，后返回值 
	char* p = my_strcpy(arr1,arr2);
	//函数指针 
	char* (*pf)(char*,const char*) = my_strcpy;
	char* (*pfarr[4])(char*,const char*) = {my_strcpy,my_strcpy,my_strcpy,my_strcpy};
	char* ps = pf(arr1, arr2);
	char* pd = pfarr[1](arr1,arr2); 
	printf("%s\n", p);
	printf("%s\n", ps);
	printf("%s\n", pd);
	return 0;
} */

//函数指针类型的应用--计算器

/*
#include<stdio.h> 
void menu()
{
	printf("##############################\n");
	printf("#####  1.add    2.sub    #####\n");
	printf("#####  3.mul    4.div    #####\n");
	printf("#####  5.xor    0.extl   #####\n");
	printf("##############################\n");
}
int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
} 
int Mul(int x, int y)
{
	return x * y;
} 
int Div(int x, int y)
{
	return x / y;
}
int Xor(int x, int y)
{
	return x ^ y;
} 
int main()
{
	int input = 0;
	int x = 0;
	int y = 0;
	int red = 0;
	//函数数组指针pfArr[]此时是一个转移表，通过下标直接跳转到相应的功能代码位置 
	int (*pfArr[])(int, int) = {0, Add, Sub, Mul, Div, Xor};
	do
	{
		menu();
	    printf("请选择:>");
	    scanf("%d", &input);
		if(input>=1 && input<6)
		{
			printf("请输入两个数字:>");
			scanf("%d%d", &x, &y); 
			red = pfArr[input](x, y);
			printf("%d\n", red);
		}
		else if(input == 0)
		{
			printf("退出\n");
		}
		else
		{
			printf("选择错误："); 
		}
	}while(input);
	return 0;
} */
//还可以通过switch实现，就是比较麻烦，明天可以自己写一下
/*
#include<stdio.h>
void menu()
{
	printf("##############################\n");
	printf("#####  1.add    2.sub    #####\n");
	printf("#####  3.mul    4.div    #####\n");
	printf("#####  5.xor    0.extl   #####\n");
	printf("##############################\n");
}
int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
} 
int Mul(int x, int y)
{
	return x * y;
} 
int Div(int x, int y)
{
	return x / y;
}
int Xor(int x, int y)
{
	return x ^ y;
}
int gal(int (*parr)(int, int))
{
	int x = 0;
	int y = 0;
	printf("请输入两个操作数:>");
	scanf("%d%d", &x, &y);
	return parr(x, y);
}
int main() 
{
	int input = 0;
	do{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch(input)
		{
			case 1:
			    printf("%d\n",gal(Add));
			    break;
			case 2:
			    printf("%d\n", gal(Sub));
			    break;
            case 3:
			    printf("%d\n", gal(Mul));
			    break;
            case 4:
			        printf("%d\n", gal(Div));
			        break;
            case 5:
                printf("%d\n", gal(Xor));
                break;
            case 0:
            printf("退出\n");
            default:
                printf("选择错误\n");
		} 
	}while(input);
	return 0;
}*/
/*
#include<stdio.h>
int Div(int x, int y)
{
	return x / y;
}
int main()
{
	int arr[10] = {0};
	int (*p)[10] = &arr;
	//printf("%d\n", *(*p+1));
	int (*parr)(int, int) = &Div;//函数指针 
    int (*pfArr[4])(int, int) = {&Xiv};//函数指针数组
	int(*(*ppfArr)[4])(int, int) = &pfArr;//指向函数指针的数组指针
	printf("%d\n", (pfArr[0])(6, 2));
	printf("%d\n", ((*ppfArr)[0])(6, 2)); 
	//ppfArr是一个数组指针，它指向一个有四个元素的数组，元素的类似是函数指针类型int(*)(int, int)类型 
	return 0;
}
*/
/*
//只能排序整型 
#include<stdio.h>
void bubble_sort(int arr[], int sz)
{
	int i = 0;
	int j = 0;
	int red = 0;
	int count = 1;
	for(i=0;i<sz;i++)  
	{
		for(j=0;j<sz-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				red = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = red;
				count = 0;
			}
		}
		if(1==count)
			{
				break;
			}
	}
}
int main()
{
	int arr[10] = {10,1,2,3,4,5,6,7,8,9};
	int sz = sizeof(arr)/sizeof(arr[0]);
	int i = 0;
	bubble_sort(arr,sz);
	for(i=0;i<sz;i++) 
	{
	    printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
*/
/*
//qsort库函数--快速排序的功能，任何类型都可以 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int test_qsort(const void* e1, const void* e2)
{
	return (int)*(float*)e1 - *(float*)e2;
}
struct Stu
{
	char name[10];
	int age;
	char ID[20];
};
int stu_qsort(const void* e1, const void* e2)//这是qsort函数的第四个参数，注意这个函数的参数一定是const void*指针类型 
{
	//return strcmp (((struct Stu*)e1)->name, ((struct Stu*)e2)->name);//自己将两个参数强制转换为整数类型
	return strcmp(((struct Stu*)e1)->ID, ((struct Stu*)e2)->ID);
}
int main()
{
	int i = 0;
	//float f[] = {9.0, 8.0,7.0, 6.0,5.0};
	//int sz = sizeof(f)/sizeof(f[0]);
	//qsort(f, sz, sizeof(f[0]), test_qsort);
	struct Stu s[3] = {{"zhao",20,"18385261105"},{"guan",21,"17756134682"},{"chen",21,"13785244378"}};
	int sz = sizeof(s)/sizeof(s[0]);
	qsort(s,sz,sizeof(s[0]),stu_qsort);
	//qsort库函数有四个参数
	//第一个参数是首元素地址
	//第二个参数是元素个数
	//第三个参数是一个元素大小
	//第四个参数是函数指针，这个函数需要自己创建，函数的两个参数是两个待比较操作数的地址
	//void qsort (void* base, size_t num, size_t size,
    //        int (*compar)(const void*,const void*)); 
	//for(i=0;i<sz;i++)
	//{
		//printf("%f ", f[i]);
		printf("%s %s %s\n",s[0].name, s[1].name, s[2].name);
	//}
	return 0;
}*/
//qsort库函数的实现--bubble_sort2
/*
#include<stdio.h>
int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}
void Swap(char* e1, char* e2, int width)//传过来的参数不知道是什么类型的，所以无法保证这两个参数完全交换，所以需要知道参数大小 
{
	int i = 0;
	char temp = 0;
	for(i=0;i<width;i++)
	{
//      temp = *e1;
//		*e1 = *e2;
//		*e2 = temp;
//		e1++;
//		e2++;
        temp = *(e1+i);
        *(e1+i) = *(e2+i);
        *(e2+i) = temp;
	}
}
void bubble_qsort2(void* base, int sz, int width, int (*cmp)(const void* e1, const void* e2))
{
	int i = 0;
	int j = 0;
	for(i=0;i<sz-1;i++)//一趟的排序 
	{
		for(j=0;j<sz-1-i;j++)//这一趟的排序 
		{
			if(cmp((char*)base + j*width,(char*)base + (j+1)*width) > 0)//函数回调 
			{
				Swap((char*)base + j * width,(char*)base + (j+1)*width, width); 
			}
		}
	}
}
void test1()
{
	int arr[] = {10,9,8,7,6,5,4,3,2,1};
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	bubble_sort2(arr, sz, sizeof(arr[0]), cmp_int);
    for(i=0;i<sz;i++)
    {
    	printf("%d ", arr[i]);
    }
} 
void test2()
{
	
}
int main()
{
	 test1();//整形数组交换 
} 
*/
/*
#include<stdio.h>
int main()
{
//	int a[] = {1,2,3,4};
//	printf("%d\n", sizeof(a));//16--sizedf(数组名)，参数只有数组名是才代表整个数组，加上其它东西都只代表首元素地址 
//	printf("%d\n", sizeof(a+0));//4/8--代表首元素地址 
//	printf("%d\n", sizeof(*a));//4--第一个元素大小 
//	printf("%d\n", sizeof(a+1));//4/8--第二个元素地址 
//	printf("%d\n", sizeof(a[1]));//4--第二个元素大小 
//	printf("%d\n", sizeof(&a));//4/8//&a取出的是数组的地址但仍然是一个地址，大小仍然是4/8 
//	printf("%d\n", sizeof(*&a));//16--&a是数组的地址，解引用访问的是整个数组 
//	printf("%d\n", sizeof(&a+1));//4/8--&a是一个数组的地址，&a+1跳过了一个数组的地址，但仍然是一个数组 
//	printf("%d\n", sizeof(&a[0]));//4/8--第一个元素的地址 
//	printf("%d\n", sizeof(&a[0]+1));//4/8--第二个元素的地址
char cf[] = {'a', 'b', 'c', 'd', 'e', 'f'};
//    printf("%d\n", sizeof(cf));6
//    printf("%d\n", sizeof(cf+0));4/8
//    printf("%d\n", sizeof(*cf));1
//	printf("%d\n", sizeof(cf[0]));1
//	printf("%d\n", sizeof(&cf));4/8
//	printf("%d\n", sizeof(&cf+1));4/8
//	printf("%d\n", sizeof(&cf[0]));4/8
//	printf("%d\n", sizeof(&cf[0]+1));//4/8
    printf("%d\n", strlen(cf));//随机值 
    printf("%d\n", strlen(cf+0));//随机值 
    //printf("%d\n", strlen(*cf));//err,非法访问，错误 
	//printf("%d\n", strlen(cf[0]));//err 
	printf("%d\n", strlen(&cf));//随机值 
	printf("%d\n", strlen(&cf+1));//随机值-6 
	printf("%d\n", strlen(&cf[0]));//随机值 
	printf("%d\n", strlen(&cf[0]+1));//随机值-1 
	return 0;
}
*/