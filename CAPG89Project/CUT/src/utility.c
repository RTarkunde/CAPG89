#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <main.h>
#include <struct.h>
#include <log.h>

void printEmpStruct(employee* emp)
/******************************************************************************
 * Takes input an employee structure ( pointer) and prints it contents on screen.
 * Logs are commented as they mess up with formatting
 */
{
 //   log_trace("Entering function %s", __func__);
 //   employee* emp_struct = NULL ;
 //   employeeReportTableHeaderFormatter();

    printf("%p | %3d | %11s %11s | %11s | %12s | %10s | %5d |\n", emp->next, emp->empId, emp->firstName, emp->lastName, emp->email, emp->phone, emp -> jobid,  emp->salary);

  //  log_trace("Exiting function %s\n", __func__);
  //  employeeReportFormatter();
}

