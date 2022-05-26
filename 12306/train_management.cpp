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
		printf("请输入你想要的操作：");
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
	printf("(1)添加车次\n");
	printf("(2)查询站点\n");
	printf("(3)查询车次\n");
	printf("(4)清理车次\n");
	printf("(5)修改车次\n");
	printf("(6)返回上层\n");
	printf("***********************************************************************************************\n");
	printf("编号      车次      车票余数  首发站    终点站    价格\n");
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
	//修改车次号
	if (flag == 1) {
		char name[20], altered_name[20];
		printf("请输入要改变的车次号：");
		scanf("%s", name);
		printf("请输入改变后的车次号：");
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
		printf("请输入需要修改的站点：");
		scanf("%s", name);
		alter_station(name);
	}
}
void alter_station(char name[20])
{
	printf("请输入要改变车次号：");
	char id[20];
	scanf("%s", id);
	printf("请输入改后的站点为：");
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
	printf("请输入车次号：");
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
		printf("车辆号已存在\n");
		printf("(1)重新输入\t(2)清理车次\t(3)返回上级\t(4)修改站点\n");
		printf("请选择：");
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
	printf("请输入票价："); scanf("%lf", &a.price);
	printf("请输入座位数:"); scanf("%d", &a.ticketnumber);
	if (flag1) {
		printf("请输入终点站："); scanf("%s", a.end);
		fp = fopen("Train_Infor.txt", "a+");
		fprintf(fp, "%s %d %s %s %lf", a.id, a.ticketnumber, name, a.end, a.price);
		fclose(fp);
	}
	else {
		printf("请输入起点站："); scanf("%s", a.begin);
		fp = fopen("Train_Infor.txt", "a+");
		fprintf(fp, "%s %d %s %s %lf", a.id, a.ticketnumber, a.begin, name, a.price);
		fclose(fp);
	}
}
void Search_train()
{
	printf("请输入你想要查询的车次号：");
	char name[20];
	scanf("%s", name);
	bool flag = false;
	system("cls");
	printf("(1)删除该车次\n");
	printf("(2)修改该车次\n");
	printf("(3)查询该车次的详细信息\n");
	printf("(4)返回上层\n");
	read_train();
	printf("***********************************************************************************************\n");
	printf("编号      车次      车票余数  首发站    终点站    价格\n");
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
		printf("未查询到该车次！\n");
		printf("(1)添加该车次\t(2)重新输入\t");
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
		printf("请输入想要继续的操作：");
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
	printf("请输入车次号：");
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
		printf("车辆号已存在\n");
		printf("(1)重新输入\t(2)清理车次\t(3)返回上级\t(4)修改站点\n");
		printf("请选择：");
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
	printf("请输入票价："); scanf("%lf", &a.price);
	printf("请输入座位数:"); scanf("%d", &a.ticketnumber);
	printf("请输入始发站："); scanf("%s", a.begin);
	printf("请输入终点站："); scanf("%s", a.end);
	fp = fopen("Train_Infor.txt", "a+");
	fprintf(fp, "%s %d %s %s %lf\n", a.id, a.ticketnumber, a.begin, a.end, a.price);
	count++;
	fclose(fp);
}
void Search_station()
{
	char name[20];
	printf("请输入想要查询的站点：");
	scanf("%s", name);
	while (1)
	{
		system("cls");
		printf("(1)添加含有该地点的新车次\n");
		printf("(2)修改含有当前地点的车次\n");
		printf("(3)查询以下车次的详细信息\n");
		printf("(4)清理所以含有当前地点的车次\n");
		printf("(5)返回上层\n");
		read_train();
		printf("***********************************************************************************************\n");
		printf("编号      车次      车票余数  首发站    终点站    价格\n");
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
		printf("请输入想要继续的操作：");
		int choose;
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			printf("该地点是否为起始点?(YorN):");
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
	printf("请输入想要删除的车次号：");
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
		printf("确定要删除？(YorN)");
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
		printf("未查询到有此车次号！\n");
		printf("(1)重新输入(2)返回上级\t");
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