#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "Admin.h"
#include "train_management.h"
#include "chenke_management.h"
void FirstPage()
{
	int choose;
	while (1)
	{
		system("cls");
		printf("(1)����Ա��¼\n");
		printf("(2)������Ϣ�鿴\n");
		printf("(3)�˳�ϵͳ\n");
		printf("��ѡ�������");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1: Admin_signin();
			break;
		case 2: 
			break;
		case 3:
			exit(0);
			break;
		}
	}
}
void welcome()
{
	
	printf("*****************************\n");
	printf("*****************************\n");
	printf("********12306��Ʊϵͳ********\n");
	printf("************v1.0*************\n");
	printf("*****************************\n");
	Sleep(1000);
	read_train();
	read_chenke();
}
int main()
{
	welcome();
	FirstPage();
	system("pause");
	return 0;
}

