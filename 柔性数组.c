//��������--�ṹ�����һ����Ա������С�ǿ�������Ϊδ֪��С��
#include<stdio.h>
#include<stdlib.h>
/*
struct S
{
	int a;
	int arr[];//δ֪��С����������--��С�ǿ��Ե�����
	//int arr[0];//����д�������� 
};
int main()
{
	//�ڼ��������������Ľṹ���Сʱ���������������� 
	//printf("%d\n",sizeof(struct S));//���Ϊ4���ֽ� 
	struct S* p = (struct S*)malloc(sizeof(struct S)+5*sizeof(int));
	//ǰ�濪�ٵ�4���ֽھ��൱��struct S��һ����Ա�����Ĵ�С��������������ĳ�Ա�������������20���ֽ��Ǹ��������鿪�ٵ� 
	int i = 0;
	p->a = 10;
	for(i=0;i<5;i++)
	{
		//p->arr[i] = i;
		*(p->arr+i) = i;
	}
	//�ı����������С
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
	//�ͷſ��ٳ����Ķ�̬�ռ�
	free(p);
	p = NULL; 
	return 0;
}*/
//��һ�ַ���Ҳ������������蹦��
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
//��ȻҲ����ֱ��ʹ�ýṹ�壬���ö�����һ����̬�ռ�
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
