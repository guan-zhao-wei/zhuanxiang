/*
#include<stdio.h>
int a;//全局变量没有初始化时，默认为0 
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
/*
#include<stdio.h>

int get_diff(int n, int m)
{
    int count = 0;
    int tmp = n^m;//将不同的都化为1，相同的都化为0 
	while(tmp)
	{
		tmp = tmp&(tmp-1);
		count++;
	}
	return count;
}
int main()
{
	int n = 0;
	int m = 0;
	int count = 0;
	int tmp = n^m;
	scanf("%d%d", &n, &m);
	count = get_diff(n,m);
	printf("count=%d\n", count);
	return 0;
} */
//打印出一个数二进制的奇数位和偶数位
/*
#include<stdio.h>
// 0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0  0 0 0 0 0 0 0 0 0 0
//32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1
void print(int n)
{
	int i =0;
	//打印奇数位 
	printf("奇数：\n"); 
	for(i=30;i>0;i-=2)//第31位是奇数移动30位就可以计算第31位的数了 
	{
		printf("%d ", (n>>i)&1);
	}
	printf("\n");
	//打印偶数位 
	printf("偶数：\n"); 
	for(i=31;i>0;i-=2)//第32位是偶数所以移动31位 
	{
		printf("%d ", (n>>i)&1);
	}
	printf("\n");
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	print(n);
	return 0;
}*/
//用指针解引用的方法打印一个数组 
/*
#include<stdio.h>
int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int* p = arr;
	int sz = sizeof(arr)/sizeof(arr[0]);
	int i = 0;
	for(i=0;i<sz;i++)
	{
		printf("%d ", *(p+i));
	}
	return 0;
} */
//打印一个你输入进去的数的乘法表 
/*
#include<stdio.h>
void print(int x)
{
	int i = 0;
	int j = 0;
	for(j=1;j<=x;j++)
	{
		for(i=1;i<=j;i++)
	{
		printf("%d*%d=%-2d ", i, j, i*j);
	}
	printf("\n");
	}
	//for(i=1;i<=x;i++)
//	{
//		printf("%d*%d=%-2d ", i, x, i*x);
//	}
//	printf("\n");
}
int main()
{
	int a = 0;
	scanf("%d", &a);
	print(a);
	return 0;
} */
//打印素数 
/*
#include<stdio.h>
#include<math.h>
void print(int i)
{
	int j = 0;
	for(j=3;j<=sqrt(i);j++)
	{
		if(i%j==0)
		{
			break;
		}
	}
	if(j>sqrt(i))
	{
		printf("素数是%d  ", i);
	}
}
int main()
{
	int i =0;
	for(i=101;i<200;i+=2)
	{
        print(i);
	}
	return 0;
}*/

//打印出一个数的每一位--递归的方法 
/*
#include<stdio.h>
void print(int n)
{
	int tmp = n%10;
	if(n/10!=0)
	{
		print(n/10);
	}
	printf("%d ", tmp);
}
int main()
{
	int n = 0;
	scanf("%d",&n);
	print(n); 
	return 0;
} */
//递归实现n的阶乘 
/*
#include<stdio.h>
int print(int n)
{
	if(n>=2)
	{
		return n*print(n-1); 
	}
	return 1;
}
int main()
{
	int n = 0;
	int tmp = 0;
	scanf("%d", &n);
	tmp = print(n);
	printf("tmp=%d\n", tmp);
	return 0;
} 
*/
//递归实现strlen函数 
/*
#include<stdio.h>
int sy_strlen(char* p)
{
	if((*p)!='\0')
	{
	    return 1+sy_strlen(p+1);		
	}
	return 0; 
}
int main()
{
	char arr[] = "abcdefuysj";
	int count = 0;
	count = sy_strlen(arr);
	 printf("count=%d\n", count);
	return 0;
} 
*/
//交换字符串中字符的位置 
#include<stdio.h>
//void reverse_string(char arr[], int sz)
//{
//    int left = 0;
//    int right = sz-1;
//    char tmp = 0;
//    while(left<right)
//    {
//    	tmp = arr[left];
//    	arr[left] = arr[right];
//    	arr[right] = tmp;
//    	left++;
//    	right--;
//    }
//}
/*
void reverse_string(char arr[])
{
    char tmp = arr[0];
    int len = sy_strlen(arr);
	arr[0] = arr[len-1];
	arr[len-1] = '\0';
	if(sy_strlen(arr+1)>=2)
	    reverse_string(arr+1);
	arr[len-1] = tmp;
}
int main()
{
	char arr[] = "abcdef";
	int sz = sy_strlen(arr);
	//reverse_string(arr,sz);
	reverse_string(arr);
	printf("%s\n", arr);
	return 0;
}*/
//一个数的每一位相加 
/*
#include<stdio.h>
int Digitsum(unsigned int n)
{
	if(n/10!=0)
	{
		return n%10+Digitsum(n/10);
	}
	else
	 return n%10;
}
int main()
{
	int n = 0;
	int tmp = 0;
	scanf("%d", &n);
    tmp = Digitsum(n);
	printf("%d\n", tmp);
	return 0;
} */
/*
//n的k次方 
#include<stdio.h>
double Pow(int n, int k)
{
	if(k>0)
	{
		return n*Pow(n,k-1);
	}
	else if(k == 0)
	{
	    return 1;
	}
	else
	    return (1.0/(Pow(n, -k)));//求解负数的  
}
int main()
{
	int n = 0;
	int k = 0;
	double ret = 0;
	scanf("%d%d", &n, &k);
	ret = Pow(n, k);
	printf("ret=%lf\n", ret);
	return 0;
} */
//斐波那契数列//1 1 2 3 5 8 13 21 34 55  
/*
#include<stdio.h>
int sy_Add(int n)
{
	if(n==1 || n==2)
	{
		return 1;
	}
	else if(n>2)
	{
		return sy_Add(n-1)+sy_Add(n-2);
	}
	else
	    return 0;
} 
int main()
{
	int n = 0;
	int ret = 0;
	scanf("%d", &n);
	ret = sy_Add(n);
	printf("ret=%d\n", ret);
	return 0;
} */
//打印出100-100000的水仙花数    
#include<stdio.h>
int power(int x, int n)
{
	int i = 0;
	int tmp = 1;
	for(i=1;i<=n;i++)
	{
		tmp *= x;
	}
	return tmp;
}
void sy_Add(int num)
{
	int i = num;
	int n = 0;
	int tmp = 0;
	int temp = i;
	while(temp)
	{
		n++;
		temp /= 10;
	}
	temp = i;
	while(temp)
	{
		tmp += power(temp%10, n);
		temp /= 10;
	}
    if(tmp == i)
    {
    	printf("%d是水仙花数\n", i);
    }
}
int main()
{
	int i = 0;
	for(i=100;i<100000;i++)
	{
		sy_Add(i);
	} 
	return 0;
} 
