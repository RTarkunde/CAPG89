#pragma once

#define FIRST_NAME_LEN 100
#define LAST_NAME_LEN 100
#define EMAIL_LEN 100
#define PHONE_LEN 20
#define JOBID_LEN 32

#define LINE_SIZE 512

typedef struct _employee_
{
    int empId;
    char firstName[FIRST_NAME_LEN];
    char lastName[LAST_NAME_LEN];
    char email[EMAIL_LEN];
	char phone[PHONE_LEN];
	char jobid[JOBID_LEN];
    int salary;

	struct _employee_  *next;
 
} employee;



typedef struct _stockPortfolioEntry_
{
    int stockId;
    char stockName[STOCK_NAME_LEN];
    int Qty;
	char BorS;  // 'B' or 'S' 
    int Price; 150073 // price is in paisei 1023 - round it to 1020
	timeinfo tm;
    struct _stockPortfolioEntry_  *next;

} stockPortFolioEntry;


stockPortFolioEntry sp;

sp.tm.tm_mday = 10 ;"Value Entered by User for month";





