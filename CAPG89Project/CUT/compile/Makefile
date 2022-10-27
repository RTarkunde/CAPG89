##########################################################
# Created by: rtarkunde                                  #
# Created on: Monday 10 October 2022 03:14:59 PM IST #
##########################################################


SRCDIR = ../src
TESTDIR = ../test
EXTDIR = ../external
INCLUDEDIR = ../include
OBJDIR = ../obj
BINDIR = ../bin
REPORTDIR = ../reports
CFLAGS = -c -g -Wall -I${INCLUDEDIR} -I../external/include -DLOG_USE_COLOR

# Does a CUnit test
test:

	gcc ${CFLAGS}  ${TESTDIR}/main.c -o ${OBJDIR}/main.o
	gcc ${CFLAGS}  ${SRCDIR}/crud.c -o ${OBJDIR}/crud.o
	gcc ${CFLAGS}  ${SRCDIR}/listMgmt.c -o ${OBJDIR}/listMgt.o
	gcc ${CFLAGS}  ${SRCDIR}/utility.c -o ${OBJDIR}/utility.o
	gcc ${CFLAGS}  ${EXTDIR}/log.c -o ${OBJDIR}/log.o
	gcc ${OBJDIR}/main.o ${OBJDIR}/log.o ${OBJDIR}/crud.o ${OBJDIR}/utility.o ${OBJDIR}/listMgt.o -lcunit -o ${BINDIR}/TestLinkedList.bin

	${BINDIR}/TestLinkedList.bin > ${REPORTDIR}/unitReport.txt 2>&1 

all:

	gcc ${CFLAGS}  ${SRCDIR}/main.c -o ${OBJDIR}/main.o
	gcc ${CFLAGS}  ${SRCDIR}/crud.c -o ${OBJDIR}/crud.o
	gcc ${CFLAGS}  ${SRCDIR}/listMgmt.c -o ${OBJDIR}/listMgt.o
	gcc ${CFLAGS}  ${SRCDIR}/utility.c -o ${OBJDIR}/utility.o
	gcc ${CFLAGS}  ${EXTDIR}/log.c -o ${OBJDIR}/log.o
	gcc ${OBJDIR}/main.o ${OBJDIR}/log.o ${OBJDIR}/crud.o ${OBJDIR}/utility.o ${OBJDIR}/listMgt.o -o ${BINDIR}/LinkedList.bin

memcheck:
	valgrind ${BINDIR}/LinkedList.bin > ${REPORTDIR}/memcheck.txt 2>&1

clean:

	rm ${OBJDIR}/main.o ${BINDIR}/LinkedList.bin ${OBJDIR}/log.o ${OBJDIR}/crud.o ${OBJDIR}/listMgt.o ${OBJDIR}/utility.o


#################### End of Makefile #####################
