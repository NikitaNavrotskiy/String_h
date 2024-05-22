CC=gcc
FLAGS=-Wall -Werror -Wextra --std=c11

SRC=my*.c
NAME=my_string

all : $(NAME).a

my_string.a :
	$(CC) $(FLAGS) -c $(SRC)
	ar rcs $(NAME).a *.o
	ranlib $(NAME).a
	rm -f *.o

test : clean
	$(CC) $(FLAGS) $(SRC) test/*.c -o str_test -lcheck -lm
	./str_test


clang : 
	clang-format -i *.c *.h test/*.c test/*.h

gcov_report : clean
	$(CC) $(FLAGS) --coverage $(SRC) test/*.c -o str_test -lcheck -lm
	./str_test
	lcov -t "str_test" -o str_gcov.info -c -d .
	genhtml -o report str_gcov.info
	open report/index.html
	google-chrome report/index.html


clean : 
	rm -f $(NAME).a
	rm -f *.o
	rm -f str_test
	rm -f str_test* str_gcov.info
	rm -rf report

