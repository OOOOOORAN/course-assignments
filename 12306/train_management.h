#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
typedef struct train
{
	char id[20];
	double price;
	int ticketnumber;
	char begin[20];
	char end[20];
}train;
void Train_management();
void read_train();
void write_to_file();
void Insert_train();
void Search_station();
void delete_train();
void Train_management_welcome();
void delete_selected_train(char name[20]);
void alter_station(char name[20]);
void Insert_seleted_train(char name[20], int flag);
void Search_train();
void alter_train(int flag);