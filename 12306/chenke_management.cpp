#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "Admin.h"
#include "train_management.h"
#include "chenke_management.h"
extern train trainInformation[100];
extern int count;
chenke chenkeInformation[100];
int count1 = 0;
void Ticket_sale_welcome()
{
	while (1) {
		system("cls");
		printf("(1)查询车次\n");
		printf("(2)查询站点\n");
		printf("(3)查询已定的车票\n");
		printf("(4)退订已定的车票\n");
		printf("(5)返回上级\n");
		read_chenke();
		read_train();
		int choose;
		printf("请输入想要的操作：");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			find_train();
			break;
		case 2:Search_station_chenke();
			break;
		case 3:find_booked_ticket();
			break;
		case 4:
			delete_chenke_welcome();
			break;
		case 5:
			return;
			break;
		}
	}
}
void find_train()
{
	printf("请输入你想要查询的车次号：");
	char name[20];
	scanf("%s", name);
	bool flag = false;
	system("cls");
	printf("(1)为乘客订票\n");
	printf("(2)查询该车次的详细信息\n");
	printf("(3)返回上层\n");
	read_train();
	printf("***********************************************************************************************\n");
	printf("编号                车次                车票余数            首发站              终点站              价格\n");
	int number = 1;
	for (int i = 0; i < count; i++)
	{
		if (!strcmp(trainInformation[i].id, name)) {
			flag = true;
			printf("%-20d%-20s%-20d%-20s%-20s%-20.2lf\n", number++, trainInformation[i].id, trainInformation[i].ticketnumber, trainInformation[i].begin, trainInformation[i].end, trainInformation[i].price);
			break;
		}
	}
	printf("***********************************************************************************************\n");
	if (!flag) {
		printf("未查询到该车次！\n");
		printf("(1)重新输入\t(2)返回上层\t");
		int choose;
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:find_train();
			break;
		case 2:return;
			break;
		}
	}
	else {
		printf("请输入想要继续的操作：");
		int choose;
		scanf("%d", &choose);
		switch (choose)
		{
		case 1: book_ticket();
			break;
		case 2://
			break;
		case 3:return;
		}
	}
}
void book_ticket()
{
	chenke a;
	char name[20];
	int  flag = 0;
	printf("请输入乘客身份证号：");
	scanf("%s", a.id);
	printf("请输入乘客的姓名：");
	scanf("%s", a.name);
	printf("请输入乘客的性别：");
	scanf("%s", a.sex);
	printf("请输入车次号：");
	scanf("%s", name);
	for (int i = 0; i < count; i++)
	{
		if (!strcmp(trainInformation[i].id, name))
		{
			if (trainInformation[i].ticketnumber == 0) {
				flag = 2;
				break;
			}
			trainInformation[i].ticketnumber--;
			write_to_file();
			a.total_price = trainInformation[i].price;
			strcpy(a.booked_train_id, trainInformation[i].id);
			strcpy(a.booked_train_begin, trainInformation[i].begin);
			strcpy(a.booked_train_end, trainInformation[i].end);
			flag = 1;
			break;
		}
	}
	if (!flag) {
		printf("未找到该车次，订票失败!\n");
		Sleep(1000);
		return;
	}
	else if (flag == 2)
	{
		printf("车辆座位数不足，订票失败！\n");
		Sleep(1000);
		return;
	}
	else {
		printf("订票成功！\n");
		write_to_file_chenke(a);
		Sleep(1000);
		return;
	}
}
void read_chenke()
{
	count1 = 0;
	FILE* fp;
	fp = fopen("chenke_Infor.txt", "r");
	while (fscanf(fp, "%s %s %s %s %s %s %lf ", chenkeInformation[count1].id, chenkeInformation[count1].name, chenkeInformation[count1].sex, chenkeInformation[count1].booked_train_id, chenkeInformation[count1].booked_train_begin, chenkeInformation[count1].booked_train_end, &chenkeInformation[count1].total_price) != -1)
	{
		count1++;
	}
	fclose(fp);
}
void write_to_file_chenke(chenke a)
{

	FILE* fp;
	fp = fopen("chenke_Infor.sub.txt", "a+");
	for (int i = 0; i < count1; i++) {
		fprintf(fp, "%s %s %s %s %s %s %lf\n", chenkeInformation[i].id, chenkeInformation[i].name, chenkeInformation[i].sex, chenkeInformation[i].booked_train_id, chenkeInformation[i].booked_train_begin, chenkeInformation[i].booked_train_end, &chenkeInformation[i].total_price);
	}
	count1++;
	fprintf(fp, "%s %s %s %s %s %s %lf\n", a.id, a.name, a.sex, a.booked_train_id, a.booked_train_begin, a.booked_train_end, a.total_price);
	fclose(fp);
	remove("chenke_Infor.txt");
	rename("chenke_Infor.sub.txt", "chenke_Infor.txt");
}
void Search_station_chenke()
{
	char name[20];
	printf("请输入想要查询的站点：");
	scanf("%s", name);
	system("cls");
	printf("(1)为乘客订票\n");
	printf("(2)查询以下车次的详细信息\n");
	printf("(3)返回上层\n");
	read_train();
	printf("***********************************************************************************************\n");
	printf("编号                车次                车票余数            首发站              终点站              价格\n");
	int number = 1;
	for (int i = 0; i < count; i++)
	{
		if (!strcmp(trainInformation[i].begin, name))
			printf("%-20d%-20s%-20d%-20s%-20s%-20.2lf\n", number++, trainInformation[i].id, trainInformation[i].ticketnumber, trainInformation[i].begin, trainInformation[i].end, trainInformation[i].price);
	}
	for (int i = 0; i < count; i++)
	{
		if (!strcmp(trainInformation[i].end, name))
			printf("%-20d%-20s%-20d%-20s%-20s%-20.2lf\n", number++, trainInformation[i].id, trainInformation[i].ticketnumber, trainInformation[i].begin, trainInformation[i].end, trainInformation[i].price);
	}
	printf("***********************************************************************************************\n");
	printf("请输入想要继续的操作：");
	int choose;
	scanf("%d", &choose);
	switch (choose)
	{
	case 1:book_ticket();
		break;
	case 2: //
		break;
	case 3: return;
		break;
	}
}
void find_booked_ticket()
{
	printf("请输入你想要查询的姓名：");
	char name[20];
	int num = 1;
	scanf("%s", name);
	system("cls");
	printf("(1)预定车票\n");
	printf("(2)退订车票\n");
	printf("(3)查看火车详细信息\n");
	printf("(4)返回上级\n");
	printf("***********************************************************************************************\n");
	printf("编号      身份证号  姓名      性别      车次      始发站    终点站    票价      \n");
	for (int i = 0; i < count1; i++, num++)
	{
		if (!strcmp(chenkeInformation[i].name, name))
			printf("%-10d%-10s%-10s%-10s%-10s%-10s%-10s%-10.2lf\n", num, chenkeInformation[i].id, chenkeInformation[i].name, chenkeInformation[i].sex, chenkeInformation[i].booked_train_id, chenkeInformation[i].booked_train_begin, chenkeInformation[i].booked_train_end, chenkeInformation[i].total_price);
	}
	printf("***********************************************************************************************\n");
	printf("请输入你想要的操作：");
	int choose;
	scanf("%d", &choose);
	switch (choose)
	{
	case 1: book_ticket();
		break;
	case 2: refund_ticket(name);
		break;
	case 3://
		break;
	case 4: return;
		break;
	}
}
void refund_ticket(char id[20])
{
	char name[20];
	int num = 1;
	system("cls");
	printf("(1)预定车票\n");
	printf("(2)退订车票\n");
	printf("(3)查看火车详细信息\n");
	printf("(4)返回上级\n");
	printf("***********************************************************************************************\n");
	printf("编号      身份证号  姓名      性别      车次      始发站    终点站    票价      \n");
	for (int i = 0; i < count1; i++, num++)
	{
		if (!strcmp(chenkeInformation[i].name, id))
			printf("%-10d%-10s%-10s%-10s%-10s%-10s%-10s%-10.2lf\n", num, chenkeInformation[i].id, chenkeInformation[i].name, chenkeInformation[i].sex, chenkeInformation[i].booked_train_id, chenkeInformation[i].booked_train_begin, chenkeInformation[i].booked_train_end, chenkeInformation[i].total_price);
	}
	printf("***********************************************************************************************\n");
	printf("请输入你想要退订的车次号：");
	scanf("%s", name);
	int flag = 0;
	read_train();
	for (int i = 0; i < count; i++)
	{
		if (!strcmp(trainInformation[i].id, name)) {
			flag = 1;
			break;
		}
	}
	for (int i = 0; i < count1; i++)
	{
		if (!strcmp(id, chenkeInformation[i].id) && !strcmp(name, chenkeInformation[i].booked_train_id))
		{
			flag = 2;
			break;
		}
	}
	if (!flag) {
		printf("未查询到该车次！\n");
		printf("(1)重新输入\t(2)返回上级\t");
		int choose;
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:refund_ticket(id);
			break;
		case 2:return;
			break;
		}
	}
	else if (flag == 1)
	{
		printf("旅客尚未订购此车票！\n");
		int choose = 0;
		printf("\t(1)重新输入\t(2)返回上层\t");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:refund_ticket(id);
			break;
		case 2:return;
			break;
		}
	}
	else {
		printf("确定要退订吗？(YorN)\t");
		char choose[2];
		scanf("%s", choose);
		if (!strcmp(choose, "Y")) delete_chenke(id, name);
		else {
			printf("取消退订，正在返回上级\n");
			return;
		}
	}
}
void delete_chenke(char id[20], char train_id[20])
{
	FILE* fp;
	fp = fopen("chenke_Infor.sub.txt", "a+");
	for (int i = 0; i < count1; i++) {
		if (!strcmp(id, chenkeInformation[i].name) && !strcmp(train_id, chenkeInformation[i].booked_train_id))
		{
			for (int i = 0; i < count; i++)
			{
				if (!strcmp(train_id, trainInformation[i].id)) {
					trainInformation[i].ticketnumber++;
					write_to_file();
					break;
				}
			}
		}
		else fprintf(fp, "%s %s %s %s %s %s %lf\n", chenkeInformation[i].id, chenkeInformation[i].name, chenkeInformation[i].sex, chenkeInformation[i].booked_train_id, chenkeInformation[i].booked_train_begin, chenkeInformation[i].booked_train_end, &chenkeInformation[i].total_price);
	}
	count1--;
	fclose(fp);
	remove("chenke_Infor.txt");
	rename("chenke_Infor.sub.txt", "chenke_Infor.txt");
}
void delete_chenke_welcome()
{
	int num = 1;
	printf("请输入你想要退订人的姓名:");
	char id[20];
	scanf("%s", id);
	system("cls");
	printf("***********************************************************************************************\n");
	printf("编号      身份证号  姓名      性别      车次      始发站    终点站    票价      \n");
	for (int i = 0; i < count1; i++, num++)
	{
		if (!strcmp(chenkeInformation[i].name, id))
			printf("%-10d%-10s%-10s%-10s%-10s%-10s%-10s%-10.2lf\n", num, chenkeInformation[i].id, chenkeInformation[i].name, chenkeInformation[i].sex, chenkeInformation[i].booked_train_id, chenkeInformation[i].booked_train_begin, chenkeInformation[i].booked_train_end, chenkeInformation[i].total_price);
	}
	printf("***********************************************************************************************\n");
	printf("请输入想要退订的车次号：");
	char name[20];
	scanf("%s", name);
	bool flag = false;
	for (int i = 0; i < count1; i++, num++)
	{
		if (!strcmp(chenkeInformation[i].name, id))
			if (!strcmp(chenkeInformation[i].booked_train_id, name))
				flag = true;
	}
	if (!flag) {
		printf("未找到该车次，请重新选择操作！");
		int choose;
		printf("\t(1)重新输入\t(2)返回上层\t");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:delete_chenke_welcome();
			break;
		case 2:return;
			break;
		}
	}
	else {
		printf("删除成功，即将返回上层!\n");
		delete_chenke(id, name);
		return;
	}
}