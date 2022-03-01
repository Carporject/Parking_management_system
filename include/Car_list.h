#ifndef CARLIST_H
#define CARLIST_H
typedef struct Car_list{
   char enter_date[100];
   char car_phone[40];
   char car_num[40];
   int car_pos;
   Car_list *next;
} current;
#endif