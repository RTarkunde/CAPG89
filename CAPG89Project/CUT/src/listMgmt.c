#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <main.h>
#include <struct.h>
#include <log.h>

int freeLinkedList(employee** head)
/***************************************************************************************
 This function takes the link list head, iterates through it and frees each structure.
 **************************************************************************************/
{
    employee *iter =  *head;
    employee *temp = NULL ;
    int freeCount = 0;

    while (iter != NULL )
    {
        //log_trace ("Freeing memory for %s %s\n", iter -> firstName, iter -> lastName);
        temp = iter ;
        iter = iter ->next ;
        free ( temp);
        freeCount++;
    }
    *head = NULL ;
    return freeCount;
}

static employee* constructsEmpStruct(char* line)
/****************************************************************
Takes a comma or " seperated line. Constructs ( allocats ) an
Employee structure and populates it with the tokens from the line.
Then returns the employee structure pointer.
Caller of the function should take care of freeing the pointer.
****************************************************************/
{

    log_trace("Entering function %s", __func__);
    char* token ;
    const char* seperator = "|";

    employee *empRet = (employee*)malloc (sizeof(employee));

//char *strtok(char *str, const char *delim);
    if ( line == NULL)
        return NULL ;
   token = strtok (line, seperator);
    if ( token != NULL )
    {
        log_info("Employee Id is %s", token);
        empRet->empId = atoi(token);
    }
    token = strtok (NULL, seperator);
    if ( token != NULL )
    {
        log_info("Employee First Name is %s", token);
        strncpy (empRet->firstName, token, FIRST_NAME_LEN-1);

    }
    token = strtok (NULL, seperator);
    if ( token != NULL )
    {
        log_info("Employee Last Name is %s", token);
        strncpy (empRet->lastName, token, LAST_NAME_LEN-1);

    }
    token = strtok (NULL, seperator);
    if ( token != NULL )
    {
        log_info("Employee Email is %s", token);
        strncpy (empRet->email, token, EMAIL_LEN-1);

    }
    token = strtok (NULL, seperator);
    if ( token != NULL )
    {
        log_info("Employee Phone is %s", token);
        strncpy (empRet->phone, token, PHONE_LEN-1);

    }
    token = strtok (NULL, seperator);
    if ( token != NULL )
    {
        log_info("Employee Job Id is %s", token);
        strncpy (empRet->jobid, token, JOBID_LEN-1);

    }
    token = strtok (NULL, seperator);
    if ( token != NULL )
    {
        empRet-> salary = atoi ( token);
        log_info("Employee Salary is %d", empRet-> salary);
    }

    return empRet ;
}

/******************************************************************
    Top level function which takes a filename and a link list head
    and and does the file tasks like opening the file and closing it
    After the file is opened it reads each line and calls constructsEmpStruct

    which returns the employee struct pointer. This is then used to make
    the linked list.
******************************************************************/
int readEmployeeCSV (employee** head, char* fileName )
//int readEmployeeCSV (char* fileName, employee** list)
{
    employee *newEmp = NULL ;
    char empLine[LINE_SIZE]; // Temp buffer for reading the line
	int count = 0;

    FILE* empFile = fopen (fileName, "r");
    if (empFile == NULL )
    {
            printf ("Could not open the file for reading\n");
            return EXIT_FAILURE;
    }

    while (1)
    {
        if (fgets(empLine, LINE_SIZE, empFile) == NULL)
            break ;
        newEmp =  (employee*)constructsEmpStruct(empLine);
        append(head, newEmp); // Check for success here
		count++;
    }

    fclose(empFile);
    return  count ;
}

