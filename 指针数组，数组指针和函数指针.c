/*
#include<stdio.h>
int main()
{
	char arr[] = "abcdefg";
	char* pc = arr;//��������ʾ��Ԫ�ص�ַ������pc=arr������������ͬ 
	printf("%s\n", arr);//printf������������ʱ������Ԫ�ؿ�ʼ��ӡֱ������\0 
	printf("%s\n", pc);
	return 0;
}*/
/*
#include<stdio.h>
int main()
{
	const char* pc = "abcdef";//"abcdef"��һ�������ַ����������ǽ��ַ����浽ָ��pc�У��ǰ���Ԫ�ص�ַ�浽ָ��pc��
	//*pc = 'w'; ��������ַ����ǳ����ַ��������ܸ��ģ�������ǰ�����const 
	printf("%c\n", *pc);//��ӡ���Ϊa�������������������˼�ǰ��ַ�����Ԫ�ص�ַ�浽pc�� 
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
	if(arr1 == arr2)//arr1��arr2��������ͬ�����飬���ǵ��׵�ַҲ��Ȼ��ͬ 
	{
		printf("zhaozhao\n");
	}
	else{
		printf("weiwei\n");
	}
	if(p1==p2)//p1 p2���õ���ͬһ�������ַ�����ͬһ���ַ������ַ��ĵ�ַ���������ǵĵ�ַ��ͬ 
	 
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
//ָ������--���ָ������� 
#include<stdio.h>
int main()
{
	int arr1[] = {1, 2, 3, 4, 5};
	int arr2[] = {2, 3, 4, 5, 6};
	int arr3[] = {3, 4, 5, 6, 7};
	int* parr[] = {arr1, arr2, arr3};
	//��ʱ��parr���൱��һ����λ���� 
	int i = 0;
	int j = 0;
	for(i=0;i<3;i++)//parr[0]�ľ���arr1�ļ�arr1����Ԫ�ص�ַ 
	{
		for(j=0;j<5;j++)
		{
			printf("%d", *(parr[i]+j));//+j��ʾ�����еĵ�j��Ԫ��--�൱��parr[i][j]
			//printf("%d ", parr[i][j]); 
		}
		printf("\n");
	}
	return 0;
} */
//����ָ��--��������ַ��ָ��
/*
#include<stdio.h>
 int main()
 {
 	int arr1[10] = {1,2,3,4,5,6,7,8,9,10};
 	//int* p[10];//ָ������ 
 	int (*p)[10] = &arr1;//����ָ��--���ָ����������ĵ�ַ 
    int i = 0;
    for(i=0;i<10;i++)
    {
    	printf("%d\n", *(*p+i));//*p==arr1
    	printf("%d\n", (*p)[i]);//��ӡ�����ȫ��ͬ 
    }
 	return 0;
 }*/

/*
#include<stdio.h>
int main()
{
    char* arr[5]; 
    char* (*pa)[5];//pa�Ǳ�����*pa˵��������һ��ָ�룬[5]˵��ָ��ָ��������鼰Ԫ�ظ�����char* ��ʾָ��������Ԫ�ص�����
	int (*arr[5])[5];//arr��һ�����飬�����е�ÿ��Ԫ�ض���һ��ָ�룬ÿ��ָ�붼ָ����һ�����飬���������5��Ԫ�أ�Ԫ��������int�� 
    return 0;
 }
*/

//����ָ��--��ź�����ַ��ָ�� 

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
	//int (*p)[10] = &arr;//����ָ�� 
	int (*p)(int, int) = Add;//����Ǻ���ָ�룬���;��Ǻ���ȥ�������������������� 
	printf("%p\n%p\n", p, Add);//004012F0,004012F0������ַ��ȫ��ͬ//�������������һ����ַ������������ 
	printf("%d\n", (*p)(3, 2));//��Ҳ�Ǻ������ã�*p==Add
	printf("%d\n", p(2, 3)); //��Ҳ�Ǻ������ã�������������ǵ�ַ������p==Add 
	printf("%d\n", sum);
	return 0;
}*/
//������ 
/*
#include<stdio.h>
int main()
{
	(*(void(*)())0)();//void(*)()��һ������ָ������
	//(void(*)())0�ǽ�0ǿ������ת��Ϊvoid(*)()����,��һ������ָ�����ͣ�Ȼ��������������ָ�� 
	//����(*(void(*)())0)����һ��������(*(void(*)())0)()����һ�κ������ã��޲���0��ַ����������
	 
	 void (*signal(int, void (*)(int)))(int);//signal()��һ�����������Ĳ���������һ�������ͣ�һ���Ǻ���ָ�����ͣ��������ָ�������int���ͣ�����ֵ��void���� 
	 //signal�����ķ��������ǰѺ���ȥ��֮��ʣ�µ�void(*)(int),Ҳ��һ������ָ�룬���Ĳ���Ҳ��int���ͣ�����ֵҲ��void����
	 typedef void(*pfun_t)(int);//typedef�ؼ��ֵ����������������ͣ���void (*)(int)��������Ϊpfun_t��������������һ��Ҫд��*�Ա� 
	 pfun_t signal(int, pfun_t);//������������򻯵���� 
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
	//����һ��ָ������洢�ĸ������ĵ�ַ
	int(*parr[4])(int, int) = {Add, Sub, Mul, Div};//����Ǻ���ָ������飬��ס������һ��Ҫ����*�Ա� 
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
	//�����������ã��󷵻�ֵ 
	char* p = my_strcpy(arr1,arr2);
	//����ָ�� 
	char* (*pf)(char*,const char*) = my_strcpy;
	char* (*pfarr[4])(char*,const char*) = {my_strcpy,my_strcpy,my_strcpy,my_strcpy};
	char* ps = pf(arr1, arr2);
	char* pd = pfarr[1](arr1,arr2); 
	printf("%s\n", p);
	printf("%s\n", ps);
	printf("%s\n", pd);
	return 0;
} */

//����ָ�����͵�Ӧ��--������

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
	//��������ָ��pfArr[]��ʱ��һ��ת�Ʊ�ͨ���±�ֱ����ת����Ӧ�Ĺ��ܴ���λ�� 
	int (*pfArr[])(int, int) = {0, Add, Sub, Mul, Div, Xor};
	do
	{
		menu();
	    printf("��ѡ��:>");
	    scanf("%d", &input);
		if(input>=1 && input<6)
		{
			printf("��������������:>");
			scanf("%d%d", &x, &y); 
			red = pfArr[input](x, y);
			printf("%d\n", red);
		}
		else if(input == 0)
		{
			printf("�˳�\n");
		}
		else
		{
			printf("ѡ�����"); 
		}
	}while(input);
	return 0;
} */
//������ͨ��switchʵ�֣����ǱȽ��鷳����������Լ�дһ��
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
	printf("����������������:>");
	scanf("%d%d", &x, &y);
	return parr(x, y);
}
int main() 
{
	int input = 0;
	do{
		menu();
		printf("��ѡ��:>");
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
            printf("�˳�\n");
            default:
                printf("ѡ�����\n");
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
	int (*parr)(int, int) = &Div;//����ָ�� 
    int (*pfArr[4])(int, int) = {&Xiv};//����ָ������
	int(*(*ppfArr)[4])(int, int) = &pfArr;//ָ����ָ�������ָ��
	printf("%d\n", (pfArr[0])(6, 2));
	printf("%d\n", ((*ppfArr)[0])(6, 2)); 
	//ppfArr��һ������ָ�룬��ָ��һ�����ĸ�Ԫ�ص����飬Ԫ�ص������Ǻ���ָ������int(*)(int, int)���� 
	return 0;
}
*/
/*
//ֻ���������� 
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
//qsort�⺯��--��������Ĺ��ܣ��κ����Ͷ����� 
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
int stu_qsort(const void* e1, const void* e2)//����qsort�����ĵ��ĸ�������ע����������Ĳ���һ����const void*ָ������ 
{
	//return strcmp (((struct Stu*)e1)->name, ((struct Stu*)e2)->name);//�Լ�����������ǿ��ת��Ϊ��������
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
	//qsort�⺯�����ĸ�����
	//��һ����������Ԫ�ص�ַ
	//�ڶ���������Ԫ�ظ���
	//������������һ��Ԫ�ش�С
	//���ĸ������Ǻ���ָ�룬���������Ҫ�Լ������������������������������Ƚϲ������ĵ�ַ
	//void qsort (void* base, size_t num, size_t size,
    //        int (*compar)(const void*,const void*)); 
	//for(i=0;i<sz;i++)
	//{
		//printf("%f ", f[i]);
		printf("%s %s %s\n",s[0].name, s[1].name, s[2].name);
	//}
	return 0;
}*/
//qsort�⺯����ʵ��--bubble_sort2
/*
#include<stdio.h>
int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}
void Swap(char* e1, char* e2, int width)//�������Ĳ�����֪����ʲô���͵ģ������޷���֤������������ȫ������������Ҫ֪��������С 
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
	for(i=0;i<sz-1;i++)//һ�˵����� 
	{
		for(j=0;j<sz-1-i;j++)//��һ�˵����� 
		{
			if(cmp((char*)base + j*width,(char*)base + (j+1)*width) > 0)//�����ص� 
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
	 test1();//�������齻�� 
} 
*/
/*
#include<stdio.h>
int main()
{
//	int a[] = {1,2,3,4};
//	printf("%d\n", sizeof(a));//16--sizedf(������)������ֻ���������ǲŴ����������飬��������������ֻ������Ԫ�ص�ַ 
//	printf("%d\n", sizeof(a+0));//4/8--������Ԫ�ص�ַ 
//	printf("%d\n", sizeof(*a));//4--��һ��Ԫ�ش�С 
//	printf("%d\n", sizeof(a+1));//4/8--�ڶ���Ԫ�ص�ַ 
//	printf("%d\n", sizeof(a[1]));//4--�ڶ���Ԫ�ش�С 
//	printf("%d\n", sizeof(&a));//4/8//&aȡ����������ĵ�ַ����Ȼ��һ����ַ����С��Ȼ��4/8 
//	printf("%d\n", sizeof(*&a));//16--&a������ĵ�ַ�������÷��ʵ����������� 
//	printf("%d\n", sizeof(&a+1));//4/8--&a��һ������ĵ�ַ��&a+1������һ������ĵ�ַ������Ȼ��һ������ 
//	printf("%d\n", sizeof(&a[0]));//4/8--��һ��Ԫ�صĵ�ַ 
//	printf("%d\n", sizeof(&a[0]+1));//4/8--�ڶ���Ԫ�صĵ�ַ
char cf[] = {'a', 'b', 'c', 'd', 'e', 'f'};
//    printf("%d\n", sizeof(cf));6
//    printf("%d\n", sizeof(cf+0));4/8
//    printf("%d\n", sizeof(*cf));1
//	printf("%d\n", sizeof(cf[0]));1
//	printf("%d\n", sizeof(&cf));4/8
//	printf("%d\n", sizeof(&cf+1));4/8
//	printf("%d\n", sizeof(&cf[0]));4/8
//	printf("%d\n", sizeof(&cf[0]+1));//4/8
    printf("%d\n", strlen(cf));//���ֵ 
    printf("%d\n", strlen(cf+0));//���ֵ 
    //printf("%d\n", strlen(*cf));//err,�Ƿ����ʣ����� 
	//printf("%d\n", strlen(cf[0]));//err 
	printf("%d\n", strlen(&cf));//���ֵ 
	printf("%d\n", strlen(&cf+1));//���ֵ-6 
	printf("%d\n", strlen(&cf[0]));//���ֵ 
	printf("%d\n", strlen(&cf[0]+1));//���ֵ-1 
	return 0;
}
*/