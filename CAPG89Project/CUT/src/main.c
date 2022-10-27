#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <main.h>
#include <struct.h>
#include <log.h>

int main(int argc, char** argv)
{

	employee **head = NULL , *iter = NULL ;
	int count = 0;
	head = (employee**)malloc (sizeof(employee*));
	*head = NULL ;

	//if(readEmployeeCSV("../data/employees.csv", &employee_single_linked_list) == EXIT_FAILURE)
	count = readEmployeeCSV(head, "../data/employees.csv") ;
	if( *head  == NULL || count == 0)
    {
        printf("Could not read the employee file.\n");
    }
	else
		printf ("%d records read from the csv file\n", count);

   /* part 2 of the main is to print the linked list read and constructed from the CSV file */


	while (1)
	{
		sleep(60000); // 10 minutes
		
		iter = *head ;
		while (iter != NULL )
		{
			int match = comapreSchedule(iter);
			if (match == 1)
				sendReminder(iter);
		//printEmpStruct(iter);
			iter = iter -> next;
		}
	
	//head = deleteNode (head, 140);
	//head = changeNode (head, 103, "Alex");
	int nodes_changed = changeFirstNameAllNode ( head, "Alexander", "Alex");
	printf ("%d nodes were changed\n", nodes_changed);

   /* part 2 of the main is to print the linked list read and constructed from the CSV file */
	iter = *head ;
	while (iter != NULL && iter->priority == 'T')
	{
		printEmpStruct(iter);
		iter = iter -> next;
	}

	employee* newEmp = (employee*)calloc (1, sizeof(employee));
	newEmp -> empId = 207;
	strncpy (newEmp -> firstName, "Nikola", FIRST_NAME_LEN -1);
	strncpy (newEmp -> lastName, "Tesla", LAST_NAME_LEN -1);
	strncpy (newEmp -> email, "NTESLA", EMAIL_LEN -1);
	strncpy (newEmp -> phone, "212.123.456", PHONE_LEN -1);
	strncpy (newEmp -> jobid, "SR_SCIENTIST", PHONE_LEN -1);
	newEmp -> salary = 5000;

	//insertAfter (head, 199, newEmp );
	prepend (head, newEmp);
    log_info("After prepend the head employee is %s %s", (*head) -> firstName, (*head) -> lastName);

	employee* newEmp2 = (employee*)calloc (1, sizeof(employee));
	newEmp2 -> empId = 207;
	strncpy (newEmp2 -> firstName, "Albert", FIRST_NAME_LEN -1);
	strncpy (newEmp2 -> lastName, "Einstein", LAST_NAME_LEN -1);
	strncpy (newEmp2 -> email, "AEINSTEIN", EMAIL_LEN -1);
	strncpy (newEmp2 -> phone, "212.123.457", PHONE_LEN -1);
	strncpy (newEmp2 -> jobid, "SR_SCIENTIST", PHONE_LEN -1);
	newEmp2 -> salary = 5000;

	append (head, newEmp2);

    log_info("After append the head employee is %s %s", (*head) -> firstName, (*head) -> lastName);
	
   /* part 2 of the main is to print the linked list read and constructed from the CSV file */
	iter = *head ;
	while (iter != NULL )
	{
		printEmpStruct(iter);
		iter = iter -> next;
	}

	int freedStructures = freeLinkedList(head);
    log_info("%d Structres freed", freedStructures);

    log_trace("Exiting function %s", __func__);
	return EXIT_SUCCESS;
}

