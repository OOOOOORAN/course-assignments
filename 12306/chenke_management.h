#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
typedef struct chenke
{
	char id[20];
	char name[20];
	char booked_train_id[10];
	char booked_train_begin[10];
	char booked_train_end[10];
	char sex[2];
	double total_price;
}chenke;
void Ticket_sale_welcome();
void find_train();
void book_ticket();
void read_chenke();
void write_to_file_chenke(chenke a);
void Search_station_chenke();
void find_booked_ticket();
void refund_ticket(char id[20]);
void delete_chenke(char id[20], char train_id[20]);
void delete_chenke_welcome();