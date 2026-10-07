phonebook: main.o create.o print.o delete.o find.o edit.o file.o utils.o new.o find_name.o print_one.o free.o
	gcc main.o create.o print.o delete.o find.o edit.o file.o utils.o new.o find_name.o print_one.o free.o -o phonebook

main.o: main.c phonebook.h
	gcc -c main.c

create.o: create.c phonebook.h
	gcc -c create.c

print.o: print.c phonebook.h
	gcc -c print.c

delete.o: delete.c phonebook.h
	gcc -c delete.c

find.o: find.c phonebook.h
	gcc -c find.c

edit.o: edit.c phonebook.h
	gcc -c edit.c

file.o: file.c phonebook.h
	gcc -c file.c

utils.o: utils.c phonebook.h
	gcc -c utils.c

new.o: new.c phonebook.h
	gcc -c new.c

find_name.o: find_name.c phonebook.h
	gcc -c find_name.c

print_one.o: print_one.c phonebook.h
	gcc -c print_one.c

free.o: free.c phonebook.h
	gcc -c free.c

clean:
	rm -f *.o phonebook
