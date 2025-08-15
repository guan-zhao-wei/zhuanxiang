/*
//指针
#include<stdio.h>
int main()
{
	int a = 0x11111111;
	int* p = &a;
	//char* pc = &a;//在一些编译器里面任何类型的指针都可以存储（因为大小相同，存储的数据大小也相同
	*p = 0;
	//*pc = 0;//但是解引用中指针类型就决定了指针能访问的空间大小
	printf("%p\n", *p);
	printf("%d\n", a); 
	//printf("%s\n", pc);
	 
	return 0;
} 
*/
//strlen库函数的实现 
//递归的方法 
/*
#include<stdio.h>
int int_strlen(char* arr)
{
	if(*arr != '\0')
		return 1 + int_strlen(arr+1);
	return 0;
}
int main()
{
	char arr[]= "abcd";
	int str = 0;
	str = mytrlen(arr);
	printf("%d\n", str);
	return 0;
}*/
/*
//指针的方法
#include<stdio.h>
int my_strlen(char* str)
{
	//char* i = str;
	//char* j = str;
	//简洁写法
	char* start = str; 
	//while(*j != '\0')
	while(*str != '\0')
	{
	    //j++;
	    str++;
	}
	//return j-i;
	return str-start;//指针相减得到的是指针之间的元素个数 
}
int main()
{
	char arr[] = "abcd";
	int len = 0;
	len = my_strlen(arr);
	printf("%d\n", len);
	return 0;
}*/ 
//指针与数组
/*
#include<stdio.h>
int main()
{
	int arr[10] = {0};
	int* p = arr;
	int i = 0;
	for(i=0;i<10;i++)
	{
		printf("%p====%p\n",p+i,&arr[i]);
		*(p+i)=0;
		printf("%d====%d\n",*(p+i), arr[i]);
	}
	return 0;
} 
*/
/*
//二级指针 
#include<stdio.h>
int main()
{
	int a = 10;
	int* pa = &a;
	int** ppa=&pa;//ppa就是二级指针，用来存放pa指针地址的指针
	//int*** pppa=&ppa;//三级指针.......
	//用二级指针来打印和改变a的值 
	printf("%d\n",**ppa);//**ppa相当于*pa
	**ppa = 20;
	printf("%d\n", a); 
	return 0;
}
*/
//指针数组 
/*
#include<stdio.h>
int main()
{
	int a = 10;
	int b = 20;
	int c = 30;
	int* arr[3] = {&a, &b, &c};//指针数组--用于存放指针的数组 
	int i = 0;
	for(i=0;i<3;i++)
	printf("%d\n", *(arr[i]));
	printf("%d\n", *(arr+i)); 
	return 0;
}*/
//逆序打印数组 
/*
#include<stdio.h>
void print(int arr[], int sz)
{
	int i =0;
	for(i=0;i<sz;i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void Reverse(int arr[], int sz)
{
	int left = 0;
	int right = sz-1;
	int tmp = 0;
	for(left=0,right=sz-1;right>=left;left++,right--)
	{
		tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
	}
	
}
int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int sz = sizeof(arr)/sizeof(arr[0]);
	print(arr,sz);
	Reverse(arr, sz);
	print(arr, sz);

	return 0;
}*/

/*
#include<stdio.h>
int main()
{
	int arr[5] = {1,2,3,4,5};
	short* p = (short*)arr;
	int i = 0;
	for(i=0;i<4;i++)
	{
		*(p+i) = 0;//*p是short类型的所以+1是两个字符，四次也只改变了八个字符两个int型arr的值 
	}
	for(i=0;i<5;i++)
	{
		printf("%d",arr[i]);
	}
	return 0;
} 
*/
/*
#include<stdio.h>
int i;//全局变量没有初始化时，默认为0 
int main()
{
	i--;//10000000000000000000000000000001--原码
	 	//11111111111111111111111111111110--反码
		//11111111111111111111111111111111--补码
//当转换为无符号数时，最高位不再代表符号位，代表正常的数2^31远远大于4  
	if(i>sizeof(i))//由于sizeof返回的时一个无符号数unsigned，所以i发生了类型转换 
	{
		printf(">\n");//所以输出的是> 
	} 
	else
    {
    	printf("<\n");	
   	}
	return 0;
}*/
//计算一个整数存储在内存中的（补码）二进制中有几个1 
#include<stdio.h>
//方法1 
/*
int count_bit(unsigned int n)//unsigned将传入的数字改为无符号型就可计算负数 
{
	int str = 0;
	while(n)
	{
		if(n%2 == 1)
		{
			str++;
		}
		n = n/2;
	}
	return str;
}*/
//方法2 
/*
int count_bit(int n)
{
	int count = 0;
	int i = 0;
    for(i=0;i<32;i++)
    {
    	if(1==(1&(n>>i)))
    	{
	    	count++;
	    }
    }
    return count;
}*/
/*
//方法3最高效最精简的算法
 int count_bit(int n)
 {
     int count = 0;
	 while(n)
	 {
 		n = n&(n-1);
 		count++; 
 	}
	 return count;  
 }
 //例如13
 //00000000000000000000000000001101--n
 //00000000000000000000000000001100--n-1
 //00000000000000000000000000001100--n--前面两个n&n-1按位与后将值赋给n 
 //00000000000000000000000000001011--n-1
 //00000000000000000000000000001000--n--把新的n&n-1又赋给n
 //00000000000000000000000000000111--n-1
 //00000000000000000000000000000000--n--nwei0后退出循环 
int main()
{
	int a = 0;
	scanf("%d", &a);
	int count = 0;
	count = count_bit(a);
    printf("%d\n", count);
	return 0;
} */
//计算两个数中有几个位的数不相同
#include<stdio.h>

/*
int get_diff(int n, int m)
{
    int count = 0;
    int tmp = n^m;//按位异或不同为1 
	while(tmp)
	{
		tmp = tmp&(tmp-1);
		count++;
	}
	return count;
}*/
int main()
{
	int n = 0;
	int m = 0;
	int count = 0;
	scanf("%d%d", &n, &m);
	//int tmp = n^m;
	count = get_diff(n,m);
	//while(tmp)
//	{
//		tmp = tmp&(tmp-1);
//		count++;
//	}
	printf("count=%d\n", count);
	return 0;
} 
