#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <main.h>
#include <struct.h>
#include <log.h>

int append ( employee** head, employee* newEmp )
// Time complexity is O(n)
// Time complexity for reading the list is O(n*(n+1)/2) = O(n^2)
{
	employee* iter = *head ;
	if (*head == NULL)
		*head =  newEmp ;
	else
	{
		while ( iter -> next != NULL)
		{
			iter = iter -> next ;
		}
		iter -> next = newEmp ;
		newEmp -> next = NULL ;
	}			

	return EXIT_SUCCESS;
}

int prepend ( employee** head, employee* newEmp )
// Time complexity is O(1)
// Time complexity for reading the list is O(n)
{
	employee* temp = NULL ;
    if (*head != NULL)
    {
		temp = *head;
		*head = newEmp ;
		(*head) -> next = temp;
    }
    return EXIT_SUCCESS ;
}

int changeNode ( employee** head, int empId, char* newFirstName)
// Time complexity O(n) we are doing search so single while
{
    if (*head == NULL)
        return EXIT_FAILURE ;

    employee *iter = *head ;
    while ( iter != NULL )
    {
        if ( iter->empId == empId )
        {
            strncpy (iter -> firstName, newFirstName, FIRST_NAME_LEN -1 );
            printf ("One node changed\n");
            log_info ("%s", "One node changed\n");
            break; // No need to traverse the rest of the list as we are done with the only single change.
        }
        iter = iter -> next;
    }
    return EXIT_SUCCESS ;
}

int changeFirstNameAllNode ( employee** head, char* oldFirstName, char* newFirstName)
{
	int returnValue = EXIT_SUCCESS ;
    if (head == NULL || *head == NULL)
        return EXIT_FAILURE ;

    employee *iter = *head ;
    while ( iter != NULL )
    {
        if ( strcmp (iter->firstName, oldFirstName) == 0 )
        {
            strncpy (iter -> firstName, newFirstName, FIRST_NAME_LEN -1 );
            printf ("One node changed\n");
            log_info ("%s", "One node changed\n");
			returnValue ++;
        }
        iter = iter -> next;
    }
    return returnValue ; //EXIT_SUCCESS ;
}

int deleteNode ( employee** head, int empId)
{
    if (head == NULL || *head == NULL)
        return EXIT_FAILURE ;
    employee *iter = *head ;
    employee *temp = NULL ;
    while ( iter != NULL )
    {
        if ( iter -> empId == empId )
        {
            *head = (*head) -> next;
            free ( iter );
            printf ("Start Node deleted\n");
            log_info ("%s", "Start Node deleted\n");
            break;
        }

        if ( iter->next != NULL && iter->next->empId == empId )
        {
            temp = iter->next->next ;
            free (iter->next);
            iter->next = temp ;
            printf ("One node deleted\n");
            log_info ("%s", "One node deleted\n");
            break;
        }
        iter = iter -> next;
    }
    return EXIT_SUCCESS ;
}

/* Treasure hunt   */
int insertAfter (employee** head, int empId, employee* empNew)
/* This funtion takes the address of single linked list and searches for the empId in the list
 * and then adds the empNew structure after the structure which has empId.
 */

//Inserts the empNew employee record in the linked list after the empId
{
    if (head == NULL || *head == NULL)
        return EXIT_FAILURE ;

    employee *iter = *head ;
	while( iter != NULL )
	{
		if ( empNew -> empId == iter -> empId )
		{
			printf ("Already the employee present in the list, Can't add another one.\n");
			return EXIT_FAILURE;
		}
		iter = iter -> next;
	}

	iter = *head ; //  start at the begining of the list.

    while ( iter != NULL )
    {
        if ( iter -> empId == empId )
        {
            empNew -> next = iter -> next;
            iter -> next = empNew ;
    		log_info ("%s", "New employee record inserted.\n");
			break;
        }
        iter = iter->next;
    }
    return EXIT_SUCCESS ;
}

int insertAfterOrAppend (employee** head, int empId, employee* empNew)
//Inserts a new employee record in the linked list after the empId or at the last
{
    if (head == NULL || *head == NULL)
        return EXIT_FAILURE ;
    employee *iter = *head ;
    while ( iter != NULL )
    {
        if ( iter -> empId == empId )
        {
            empNew -> next = iter -> next;
            iter -> next = empNew ;
            log_info ("%s", "New employee record inserted.\n");
            break;
        }
        // Following condition takes care of the append as search failed.
        if ( iter -> next == NULL)
        {
            iter -> next = empNew;
            iter -> next -> next = NULL ; // This is same as empnew -> next = NULL ;
            log_info ("%s", "New employee record appended at last.\n");
        }
        iter = iter->next;
    }

    return EXIT_SUCCESS ;
}

