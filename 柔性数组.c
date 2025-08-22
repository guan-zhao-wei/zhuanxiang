//柔性数组--结构体最后一个成员变量大小是可以设置为未知大小的
#include<stdio.h>
#include<stdlib.h>
/*
struct S
{
	int a;
	int arr[];//未知大小的柔性数组--大小是可以调整的
	//int arr[0];//两种写法都可以 
};
int main()
{
	//在计算包含柔性数组的结构体大小时，不包含柔性数组 
	//printf("%d\n",sizeof(struct S));//结果为4个字节 
	struct S* p = (struct S*)malloc(sizeof(struct S)+5*sizeof(int));
	//前面开辟的4个字节就相当于struct S第一个成员变量的大小（除柔性数组外的成员变量），后面的20个字节是给柔性数组开辟的 
	int i = 0;
	p->a = 10;
	for(i=0;i<5;i++)
	{
		//p->arr[i] = i;
		*(p->arr+i) = i;
	}
	//改变柔性数组大小
	struct S* prt = (struct S*)realloc(p,(sizeof(struct S)+10*sizeof(int)));
	if(prt!=NULL)
	{
		p=prt;
	} 
	for(i=5;i<10;i++)
	{
		p->arr[i] = i;
	}
	for(i=0;i<10;i++)
	{
		printf("%d ", p->arr[i]);
	}
	//释放开辟出来的动态空间
	free(p);
	p = NULL; 
	return 0;
}*/
//另一种方法也能完成上面所需功能
/*
struct str 
{
	int n;
	int* p;
};
int main()
{
	int i = 0;
	struct str* s = malloc(sizeof(struct str));
	s->n = 100;
	s->p = malloc(10*sizeof(int));
	for(i=0;i<10;i++)
	{
		*(s->p+i) = i;
	}
	for(i=0;i<10;i++)
	{
		printf("%d ", *(s->p+i));
	}
	free(s->p);
	s->p=NULL;
	free(s);
	s = NULL;
	return 0;
} */
//当然也可以直接使用结构体，不用多申请一个动态空间
struct str 
{
	int n;
	int* p;
}s;
int main()
{
	int i = 0;
	s.n = 100;
	s.p = malloc(10*sizeof(int));
	for(i=0;i<10;i++)
	{
		*(s.p+i) = i;
	}
	for(i=0;i<10;i++)
	{
		printf("%d ", *(s.p+i));
	}
	printf("%d\n", s.n);
	free(s.p);
	s.p=NULL;
	return 0;
} 
