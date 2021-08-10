#------------------------------------------------------------------------------
# Makefile for SortStrings.c
#------------------------------------------------------------------------------

PROGRAM_NAME = SortStrings
FLAGS        = -std=c99 -Wall
SOURCE       = $(PROGRAM_NAME).c
OBJECT       = $(PROGRAM_NAME).o
EXEBIN       = $(PROGRAM_NAME)

$(EXEBIN) : $(OBJECT)
	gcc -o $(EXEBIN) $(OBJECT)

$(OBJECT) : $(SOURCE)
	gcc -c $(FLAGS) $(SOURCE)

clean :
	rm $(EXEBIN) $(OBJECT)

memcheck : $(EXEBIN)
	valgrind --leak-check=full SortStrings in out
