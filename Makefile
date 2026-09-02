CC = cc

student: stud_main.o stud_add.o stud_del.o stud_show.o stud_mod.o stud_sort.o stud_save.o stud_reverse.o
	$(CC) -o student $^

stud_main.o: stud_main.c
	$(CC) -c $^

stud_add.o: stud_add.c
	$(CC) -c $^

stud_del.o: stud_del.c
	$(CC) -c $^

stud_show.o: stud_show.c
	$(CC) -c $^

stud_mod.o: stud_mod.c
	$(CC) -c $^

stud_sort.o: stud_sort.c
	$(CC) -c $^

stud_save.o: stud_save.c
	$(CC) -c $^

stud_reverse.o: stud_reverse.c
	$(CC) -c $^

clean:
	@echo "Cleaning up..."
	rm -v *.o student
