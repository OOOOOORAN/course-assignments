#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "Admin.h"
#include "train_management.h"
#include "chenke_management.h"
extern train trainInformation[100];
extern int count1;
extern int count;
typedef struct ADM
{
	char name[20];
	char passwd[20];
}ADM;
extern chenke chenkeInformation[100];
void Admin_signin()
{
	ADM Admin_User,Admin_Current;
	FILE* fp;
	fp = fopen("AdminInfor.txt", "r");
	if (fp == NULL) return;
	fscanf(fp, "%s\t%s", Admin_User.name, Admin_User.passwd);
	fclose(fp);
	printf("���������Ա�˺ţ�>");
	scanf("%s", Admin_Current.name);
	printf("���������Ա���룺>");
	scanf("%s", Admin_Current.passwd);
	if (strcmp(Admin_Current.name, Admin_User.name) || strcmp(Admin_Current.passwd, Admin_User.passwd))
	{
		printf("�˺Ż��������\n");
		Sleep(1000);
		system("cls");
		return;
	}
	else {
		Admin_Page();
	}
}
void Admin_Page()
{
	int choose;
	while (1)
	{
		system("cls");
		printf("(1)��������ϵͳ\n");
		printf("(2)�˿͹�Ʊϵͳ\n");
		printf("(3)������ҳ\n");
		printf("��ѡ�������");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1: Train_management();
			break;
		case 2: Ticket_sale_welcome();
			break;
		case 3: return;
			break;
		}
	}
}
