//����1��+2��+.......n! 
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
//����α���Ϊʲô��������ѭ�� 
/*
#include<stdio.h>
int main()
{
	int i = 0;//���ڴ�ջ�еĵ�ַ����arr�ģ���Ϊջ������ʹ�øߵ�ַ��ʹ�õ͵�ַ 
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	//int i = 0;//��ʱi�ĵ�ַ�͵���arr���ˣ��Ͳ��ᱻ��ѭ�� 
	for(i=0;i<=15;i++)//���˴�i=15���15�����ʱ�����������ѭ�� 
	{
		printf("��΢\n");
		printf("%p  %p\n", &i, &arr[15]);
		//����arr[15]�ĵ�ַ��i�ĵ�ַ��ͬ
		//ԭ�����ھֲ������Ǵ洢��ջ�еģ�ջ�Ĵ洢�����ȸߵ�ַ��͵�ַ��
		//��arr[i]Խ����ʾͿ��ܷ��ʵ�����i�ĵ�ַ
		//��arr[i]��i��ַ��ͬʱ��arr[i]=i=0;����������forѭ�� 
		arr[i] = 0; 
	}
	return 0;
}*/
//strcpy������ʵ�� 
#include<stdio.h>
#include<string.h>
//��һ����ͨ��ʽ 
/*
void my_strcpy(char* p1, char* p2, int sz)
{
	 
	
int i = 0;
	for(i=0;i<sz;i++)
	{
		*(p1+i)=*(p2+i);
	}
	//printf("%s\n", p1);//Ҳ������printf(��arr1����������ӡ 
	
}*/
//�ڶ��ָ������Ƹ�Ч�ķ��� 
/*
void my_strcpy(char* p1, char* p2)
{
	if(p1 != NULL && p2 != NULL)//��ֹ����Ĳ���λ�� 
	{
		while(*p2 != '\0')//�˴ο���������'\0' 
	    {
	     	*p1 = *p2;
	        p1++;
	        p2++;
	    }
	    *p1 = *p2;//��'\0'������ȥ 
	}
} */
//�����ָ������Ƶķ�����
/*
#include<assert.h> 

void my_strcpy(char* p1, char* p2)
{
	assert(p1 != NULL);//assert�⺯���Ƕ��Ժ��� 
	assert(p2 != NULL);//��������ڵ��������������·��������������ͻᱨ��
	while(*p1++ = *p2++)//�Ȱ�*p2��ֵ����*p1��Ȼ���ж����ֵ�Ƿ�Ϊ'\0'��++ 
	{
		;
	} 
}*/
//���������Ͻ����Ƶķ��� 
/*
#include<assert.h> 
char* my_strcpy(char* p1,const char* p2)//const���α���*p����*p���ܱ����ģ���ֹѭ������������ 
{
	char* ret = p1; 
	assert(p1 != NULL);//assert�⺯���Ƕ��Ժ��� 
	assert(p2 != NULL);//��������ڵ��������������·��������������ͻᱨ��
	while(*p1++ = *p2++)//�Ȱ�*p2��ֵ����*p1��Ȼ���ж����ֵ�Ƿ�Ϊ'\0'��++ 
	{
		;
	} 
	return ret;//�������������޷���ֵ��void��Ϊchar*�����ӽ�strcpy�⺯�� 
}  
int main()
{
	char arr1[] = "############";
	int sz = sizeof(arr1)/sizeof(arr1[0]);
	char arr2[] = "weiwei";
	//�ú���ʵ�ֿ⺯��strcpy
	//��һ�ִ��� 
	//my_strcpy(arr1, arr2, sz);
	//�ڶ��ִ���
	//my_strcpy(arr1, arr2);
	//�����ָ������ƵĴ��� 
	//my_strcpy(arr1, NULL);//������Ļ�ϱ���Assertion failed: p2 != NULL, file C:\Users\����\Documents\C-Free\Temp\δ����1.cpp, line 87
	 //my_strcpy(arr1, arr2);
	 //������
	 printf("%s\n", my_strcpy(arr1, arr2)); 
	//strcpy(arr1,arr2);//�Ѻ�����ַ�������ǰ�涼������ 
	printf("%s\n", arr1);
	//printf("%s\n", arr2);
	return 0;
} */

//const�ؼ����ڲ�ͬ��λ�����β�ͬ�ı���
/*
#include<stdio.h>
int main()
{
	int a = 10;
	int n = 100;
	//const int a = 10;//��ʱconst������a������*p�ı䣬��һЩ������������Ȼ�����ı� 
	//int* p = &a;
	//const int* p = &a;//��ʱconst���εı�����*p������*p(a)�������ı�,����p���Ա��ı䣬����p=&n�������ǿ���ִ�е�
	//int* const p = &a;//��ʱconst���εı�����p������*p(a)�ǿ��Ա��ı�ģ�����p�����Ա��ı�
	const int* const p = &a;//��ʱconst���εı���λ*p��pһ�����Σ������������Ա��ı� 
	*p = 20;
	p = &n;  
	printf("%d\n", a);
	printf("%p %p\n", &a, p); 
	return 0;
}*/ 
