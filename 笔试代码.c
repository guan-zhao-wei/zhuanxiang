
/*
#include<stdio.h>
int main()
{
	int a = 3;
	int b = 5;
	//�������ֻ�����һ���ֵĽ��������a��b��ֵ���ܶ����ôa+b�ͻ���� 
	a = a+b;//����֮��
    b = a-b;a-b����ԭ����a����ʱb��ֵΪԭ����a 
    a = a-b;a-b��ֵΪb����Ϊ��ʱb��ֵΪԭ����a
    a = a^b;
	b = a^b;
	a = a^b; 
	printf("a=%d b=%d", a, b); 
	return 0;
}*/

/*
#include<stdio.h>
int main()
{
	int arr[] = {1,2,3,4,5,1,2,3,4};
	int sz = sizeof(arr)/sizeof(arr[0]);
	int i = 0;
	int j = 0;
    int count = 0;
    for(i=0;i<sz;i++)
	{
		count ^= arr[i];//��ͬ����λ���Ϊ0��0���κ���λ���Ϊ�Ǹ������� 
	} 
	printf("����Ϊ��%d\n", count);
	//Ч��̫�� 
	//for(i=0;i<sz;i++)
//	{
//	    count = 0;//ÿ��ѭ������count 
//	    for(j=0;j<sz;j++)
//		{
//			if(arr[i] == arr[j])
//			{
//				count++;
//			}
//		}
//		if(1 == count)
//		{
//		printf("�����ǣ�%d\n", arr[i]);
//		break;
//		}
//		
//	}
	    //����ⷶΧ̫�� 
		//if(arr[i] == 5)
		//printf("%d\n", arr[i]);
	return 0; 
}
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
int main()
{
	char input[20] = {0};
	system("shutdown -s -t 60");
	cale:
	printf("��ĵ��Խ���һ�����ڹػ������������������ȡ���ػ�\n");
	scanf("%s", &input);
	if((strcmp(input, "������"))==0)
	{
		system("shutdown -a");
	}
	else
	    goto cale;
}
