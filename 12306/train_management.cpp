#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "Admin.h"
#include "train_management.h"
train trainInformation[100];
int count;
void Train_management()
{
	int choose;
	while (1)
	{
		Train_management_welcome();
		printf("����������Ҫ�Ĳ�����");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1: Insert_train();
			break;
		case 2: Search_station();
			break;
		case 3: Search_train();
			break;
		case 4: delete_train();
			break;
		case 6: return;
			break;
		}
	}
}

void Train_management_welcome()
{
	read_train();
	system("cls");
	printf("(1)��ӳ���\n");
	printf("(2)��ѯվ��\n");
	printf("(3)��ѯ����\n");
	printf("(4)������\n");
	printf("(5)�޸ĳ���\n");
	printf("(6)�����ϲ�\n");
	printf("***********************************************************************************************\n");
	printf("���      ����      ��Ʊ����  �׷�վ    �յ�վ    �۸�\n");
	for (int i = 0; i < count; i++)
	{
		printf("%-10d%-10s%-10d%-10s%-10s%-10.2lf\n", i + 1, trainInformation[i].id, trainInformation[i].ticketnumber, trainInformation[i].begin, trainInformation[i].end, trainInformation[i].price);
	}
	printf("***********************************************************************************************\n");
}

void delete_selected_train(char name[20])
{
	int flag = 0;
	FILE* fp;
	fp = fopen("Train_Infor_sub.txt", "a+");
	for (int i = 0; i < count; i++)
	{
		if (!strcmp(trainInformation[i].begin, name) || !strcmp(trainInformation[i].end, name)) {
			flag++;
			continue;
		}
		else fprintf(fp, "%s %d %s %s %lf\n", trainInformation[i].id, trainInformation[i].ticketnumber, trainInformation[i].begin, trainInformation[i].end, trainInformation[i].price);
	}
	count -= flag;
	fclose(fp);
	remove("Train_Infor.txt");
	rename("Train_Infor_sub.txt", "Train_Infor.txt");
}
void alter_train(int flag)
{
	//�޸ĳ��κ�
	if (flag == 1) {
		char name[20], altered_name[20];
		printf("������Ҫ�ı�ĳ��κţ�");
		scanf("%s", name);
		printf("������ı��ĳ��κţ�");
		scanf("%s", altered_name);
		FILE* fp;
		fp = fopen("Train_Infor_sub.txt", "a+");
		for (int i = 0; i < count; i++)
		{
			if (!strcmp(trainInformation[i].id, name))
				fprintf(fp, "%s %d %s %s %lf\n", altered_name, trainInformation[i].ticketnumber, trainInformation[i].begin, trainInformation[i].end, trainInformation[i].price);
			else fprintf(fp, "%s %d %s %s %lf\n", trainInformation[i].id, trainInformation[i].ticketnumber, trainInformation[i].begin, trainInformation[i].end, trainInformation[i].price);
		}
		fclose(fp);
		remove("Train_Infor.txt");
		rename("Train_Infor_sub.txt", "Train_Infor.txt");
	}
	if (flag == 2)
	{
		char name[20];
		printf("��������Ҫ�޸ĵ�վ�㣺");
		scanf("%s", name);
		alter_station(name);
	}
}
void alter_station(char name[20])
{
	printf("������Ҫ�ı䳵�κţ�");
	char id[20];
	scanf("%s", id);
	printf("������ĺ��վ��Ϊ��");
	char altered_name[20];
	scanf("%s", altered_name);
	FILE* fp;
	fp = fopen("Train_Infor_sub.txt", "a+");
	for (int i = 0; i < count; i++)
	{
		if (!strcmp(trainInformation[i].id, id)) {
			if (!strcmp(trainInformation[i].begin, name))
				fprintf(fp, "%s %d %s %s %lf\n", trainInformation[i].id, trainInformation[i].ticketnumber, altered_name, trainInformation[i].end, trainInformation[i].price);
			else if (!strcmp(trainInformation[i].end, name)){
				fprintf(fp, "%s %d %s %s %lf\n", trainInformation[i].id, trainInformation[i].ticketnumber, trainInformation[i].begin, altered_name, trainInformation[i].price);
			}
		}
		else fprintf(fp, "%s %d %s %s %lf\n", trainInformation[i].id, trainInformation[i].ticketnumber, trainInformation[i].begin, trainInformation[i].end, trainInformation[i].price);
	}
	fclose(fp);
	remove("Train_Infor.txt");
	rename("Train_Infor_sub.txt", "Train_Infor.txt");
}
void Insert_seleted_train(char name[20], int flag1)
{
	FILE* fp;
	train a;
	printf("�����복�κţ�");
	scanf("%s", a.id);
	bool flag = false;
	for (int i = 0; i < count; i++)
	{
		if (!strcmp(a.id, trainInformation[i].id))
		{
			flag = true;
			break;
		}
	}
	if (flag)
	{
		printf("�������Ѵ���\n");
		printf("(1)��������\t(2)������\t(3)�����ϼ�\t(4)�޸�վ��\n");
		printf("��ѡ��");
		int choose;
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			Train_management_welcome();
			Insert_train();
			break;
		default:
			break;
		}
	}
	count++;
	printf("������Ʊ�ۣ�"); scanf("%lf", &a.price);
	printf("��������λ��:"); scanf("%d", &a.ticketnumber);
	if (flag1) {
		printf("�������յ�վ��"); scanf("%s", a.end);
		fp = fopen("Train_Infor.txt", "a+");
		fprintf(fp, "%s %d %s %s %lf", a.id, a.ticketnumber, name, a.end, a.price);
		fclose(fp);
	}
	else {
		printf("���������վ��"); scanf("%s", a.begin);
		fp = fopen("Train_Infor.txt", "a+");
		fprintf(fp, "%s %d %s %s %lf", a.id, a.ticketnumber, a.begin, name, a.price);
		fclose(fp);
	}
}
void Search_train()
{
	printf("����������Ҫ��ѯ�ĳ��κţ�");
	char name[20];
	scanf("%s", name);
	bool flag = false;
	system("cls");
	printf("(1)ɾ���ó���\n");
	printf("(2)�޸ĸó���\n");
	printf("(3)��ѯ�ó��ε���ϸ��Ϣ\n");
	printf("(4)�����ϲ�\n");
	read_train();
	printf("***********************************************************************************************\n");
	printf("���      ����      ��Ʊ����  �׷�վ    �յ�վ    �۸�\n");
	int number = 1;
	for (int i = 0; i < count; i++)
	{
		if (!strcmp(trainInformation[i].id, name)) {
			flag = true;
			printf("%-10d%-10s%-10d%-10s%-10s%-10.2lf\n", number++, trainInformation[i].id, trainInformation[i].ticketnumber, trainInformation[i].begin, trainInformation[i].end, trainInformation[i].price);
			break;
		}
	}
	printf("***********************************************************************************************\n");
	if (!flag) {
		printf("δ��ѯ���ó��Σ�\n");
		printf("(1)��Ӹó���\t(2)��������\t");
		int choose;
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:Insert_train();
			break;
		case 2:Search_train();
			break;
		}
	}
	else {
		printf("��������Ҫ�����Ĳ�����");
		int choose;
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			FILE * fp;
			fp = fopen("Train_Infor_sub.txt", "a+");
			for (int i = 0; i < count; i++)
			{
				if (!strcmp(trainInformation[i].id, name)) continue;
				else fprintf(fp, "%s %d %s %s %lf\n", trainInformation[i].id, trainInformation[i].ticketnumber, trainInformation[i].begin, trainInformation[i].end, trainInformation[i].price);
			}
			count--;
			fclose(fp);
			remove("Train_Infor.txt");
			rename("Train_Infor_sub.txt", "Train_Infor.txt");
			break;
		case 2:alter_train(1);
			break;
		}
	}
}
void read_train()
{
	count = 0;
	FILE* fp;
	fp = fopen("train_Infor.txt", "r");
	while (fscanf(fp, "%s %d %s %s %lf\n", trainInformation[count].id, &trainInformation[count].ticketnumber, trainInformation[count].begin, trainInformation[count].end, &trainInformation[count].price) != -1)
	{
		count++;
	}
	fclose(fp);
}
void Insert_train()
{
	FILE* fp;
	train a;
	printf("�����복�κţ�");
	scanf("%s", a.id);
	bool flag = false;
	for (int i = 0; i < count; i++)
	{
		if (!strcmp(a.id, trainInformation[i].id))
		{
			flag = true;
			break;
		}
	}
	if (flag)
	{
		printf("�������Ѵ���\n");
		printf("(1)��������\t(2)������\t(3)�����ϼ�\t(4)�޸�վ��\n");
		printf("��ѡ��");
		int choose;
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			Train_management_welcome();
			Insert_train();
			break;
		default:
			break;
		}
	}
	printf("������Ʊ�ۣ�"); scanf("%lf", &a.price);
	printf("��������λ��:"); scanf("%d", &a.ticketnumber);
	printf("������ʼ��վ��"); scanf("%s", a.begin);
	printf("�������յ�վ��"); scanf("%s", a.end);
	fp = fopen("Train_Infor.txt", "a+");
	fprintf(fp, "%s %d %s %s %lf\n", a.id, a.ticketnumber, a.begin, a.end, a.price);
	count++;
	fclose(fp);
}
void Search_station()
{
	char name[20];
	printf("��������Ҫ��ѯ��վ�㣺");
	scanf("%s", name);
	while (1)
	{
		system("cls");
		printf("(1)��Ӻ��иõص���³���\n");
		printf("(2)�޸ĺ��е�ǰ�ص�ĳ���\n");
		printf("(3)��ѯ���³��ε���ϸ��Ϣ\n");
		printf("(4)�������Ժ��е�ǰ�ص�ĳ���\n");
		printf("(5)�����ϲ�\n");
		read_train();
		printf("***********************************************************************************************\n");
		printf("���      ����      ��Ʊ����  �׷�վ    �յ�վ    �۸�\n");
		int number = 1;
		for (int i = 0; i < count; i++)
		{
			if (!strcmp(trainInformation[i].begin, name))
				printf("%-10d%-10s%-10d%-10s%-10s%-10.2lf\n", number++, trainInformation[i].id, trainInformation[i].ticketnumber, trainInformation[i].begin, trainInformation[i].end, trainInformation[i].price);
		}
		for (int i = 0; i < count; i++)
		{
			if (!strcmp(trainInformation[i].end, name))
				printf("%-10d%-10s%-10d%-10s%-10s%-10.2lf\n", number++, trainInformation[i].id, trainInformation[i].ticketnumber, trainInformation[i].begin, trainInformation[i].end, trainInformation[i].price);
		}
		printf("***********************************************************************************************\n");
		printf("��������Ҫ�����Ĳ�����");
		int choose;
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			printf("�õص��Ƿ�Ϊ��ʼ��?(YorN):");
			char op[2];
			scanf("%s", op);
			if (!strcmp(op, "Y")) Insert_seleted_train(name, 1);
			else Insert_seleted_train(name, 0);
			break;
		case 2: alter_station(name);
			break;
		case 3: Search_train();
			break;
		case 4: delete_selected_train(name);
			break;
		case 5: return;
			break;
		}
	}
}
void delete_train()
{
	printf("��������Ҫɾ���ĳ��κţ�");
	char name[20];
	scanf("%s", name);
	bool flag = false;
	for (int i = 0; i < count; i++)
	{
		if (!strcmp(trainInformation[i].id, name)) {
			flag = true;
			break;
		}
	}
	if (flag) {
		printf("ȷ��Ҫɾ����(YorN)");
		char choose[2];
		scanf("%s", choose);
		if (!strcmp(choose, "Y")) {
			FILE* fp;
			fp = fopen("Train_Infor_sub.txt", "a+");
			for (int i = 0; i < count; i++)
			{
				if (!strcmp(trainInformation[i].id, name)) continue;
				else fprintf(fp, "%s %d %s %s %lf\n", trainInformation[i].id, trainInformation[i].ticketnumber, trainInformation[i].begin, trainInformation[i].end, trainInformation[i].price);
			}
			count--;
			fclose(fp);
			remove("Train_Infor.txt");
			rename("Train_Infor_sub.txt", "Train_Infor.txt");
		}
		else return;
	}
	else {
		printf("δ��ѯ���д˳��κţ�\n");
		printf("(1)��������(2)�����ϼ�\t");
		int choose;
		scanf("%d", &choose);
		switch (choose)
		{
		case1:Train_management_welcome();
			delete_train();
			break;
		case2:return;
			break;
		}
	}
}
void write_to_file()
{
	FILE* fp;
	fp = fopen("Train_Infor_sub.txt", "a+");
	for (int i = 0; i < count; i++)
		fprintf(fp, "%s %d %s %s %lf\n", trainInformation[i].id, trainInformation[i].ticketnumber, trainInformation[i].begin, trainInformation[i].end, trainInformation[i].price);
	fclose(fp);
	remove("Train_Infor.txt");
	rename("Train_Infor_sub.txt", "Train_Infor.txt");
}