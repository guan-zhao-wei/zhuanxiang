/*
//ָ��
#include<stdio.h>
int main()
{
	int a = 0x11111111;
	int* p = &a;
	//char* pc = &a;//��һЩ�����������κ����͵�ָ�붼���Դ洢����Ϊ��С��ͬ���洢�����ݴ�СҲ��ͬ
	*p = 0;
	//*pc = 0;//���ǽ�������ָ�����;;�����ָ���ܷ��ʵĿռ��С
	printf("%p\n", *p);
	printf("%d\n", a); 
	//printf("%s\n", pc);
	 
	return 0;
} 
*/
//strlen�⺯����ʵ�� 
//�ݹ�ķ��� 
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
//ָ��ķ���
#include<stdio.h>
int my_strlen(char* str)
{
	//char* i = str;
	//char* j = str;
	//���д��
	char* start = str; 
	//while(*j != '\0')
	while(*str != '\0')
	{
	    //j++;
	    str++;
	}
	//return j-i;
	return str-start;//ָ������õ�����ָ��֮���Ԫ�ظ��� 
}
int main()
{
	char arr[] = "abcd";
	int len = 0;
	len = my_strlen(arr);
	printf("%d\n", len);
	return 0;
}*/ 
//ָ��������
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
//����ָ�� 
#include<stdio.h>
int main()
{
	int a = 10;
	int* pa = &a;
	int** ppa=&pa;//ppa���Ƕ���ָ�룬�������paָ���ַ��ָ��
	//int*** pppa=&ppa;//����ָ��.......
	//�ö���ָ������ӡ�͸ı�a��ֵ 
	printf("%d\n",**ppa);//**ppa�൱��*pa
	**ppa = 20;
	printf("%d\n", a); 
	return 0;
}
*/
//ָ������ 
/*
#include<stdio.h>
int main()
{
	int a = 10;
	int b = 20;
	int c = 30;
	int* arr[3] = {&a, &b, &c};//ָ������--���ڴ��ָ������� 
	int i = 0;
	for(i=0;i<3;i++)
	printf("%d\n", *(arr[i]));
	printf("%d\n", *(arr+i)); 
	return 0;
}*/
//�����ӡ���� 
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
		*(p+i) = 0;//*p��short���͵�����+1�������ַ����Ĵ�Ҳֻ�ı��˰˸��ַ�����int��arr��ֵ 
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
int i;//ȫ�ֱ���û�г�ʼ��ʱ��Ĭ��Ϊ0 
int main()
{
	i--;//10000000000000000000000000000001--ԭ��
	 	//11111111111111111111111111111110--����
		//11111111111111111111111111111111--����
//��ת��Ϊ�޷�����ʱ�����λ���ٴ������λ��������������2^31ԶԶ����4  
	if(i>sizeof(i))//����sizeof���ص�ʱһ���޷�����unsigned������i����������ת�� 
	{
		printf(">\n");//�����������> 
	} 
	else
    {
    	printf("<\n");	
   	}
	return 0;
}*/
//����һ�������洢���ڴ��еģ����룩���������м���1 
#include<stdio.h>
//����1 
/*
int count_bit(unsigned int n)//unsigned����������ָ�Ϊ�޷����;Ϳɼ��㸺�� 
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
//����2 
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
//����3���Ч�����㷨
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
 //����13
 //00000000000000000000000000001101--n
 //00000000000000000000000000001100--n-1
 //00000000000000000000000000001100--n--ǰ������n&n-1��λ���ֵ����n 
 //00000000000000000000000000001011--n-1
 //00000000000000000000000000001000--n--���µ�n&n-1�ָ���n
 //00000000000000000000000000000111--n-1
 //00000000000000000000000000000000--n--nwei0���˳�ѭ�� 
int main()
{
	int a = 0;
	scanf("%d", &a);
	int count = 0;
	count = count_bit(a);
    printf("%d\n", count);
	return 0;
} */
//�������������м���λ��������ͬ
#include<stdio.h>

/*
int get_diff(int n, int m)
{
    int count = 0;
    int tmp = n^m;//��λ���ͬΪ1 
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
