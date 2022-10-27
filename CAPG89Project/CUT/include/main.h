#ifndef __MAIN_H__
#define __MAIN_H__
#include <struct.h>

// Forward declarations of the functions
extern int readEmployeeCSV (employee** head, char* fileName);
extern int prepend ( employee** head, employee* newEmp );
extern int append ( employee** head, employee* newEmp );
extern int deleteNode ( employee** head, int empId);
extern int changeNode ( employee** head, int empId, char* newFirstName);
extern int changeFirstNameAllNode ( employee** head, char* oldFirstName, char* newFirstName);
extern int insertAfter (employee** head, int empId, employee* empNew);
extern int insertAfterOrAppend (employee** head, int empId, employee* empNew);
extern int changeFirstNameAllNode ( employee** head, char* oldFirstName, char* newFirstName);
extern int freeLinkedList(employee** head);
extern void printEmpStruct(employee* emp);

//

#endif
