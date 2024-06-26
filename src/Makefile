CC := g++
CFLAGS := -Wall -Werror -Wextra -std=c++17

.PHONY: all clean test

all: s21_matrix_oop.a

build: s21_matrix_oop.cpp
	$(CC) -c $(CFLAGS) -lstdc++ -std=c++17 s21_matrix_oop.cpp -o s21_matrix_oop.o

s21_matrix_oop.a: build
	ar rcs s21_matrix_oop.a s21_matrix_oop.o
	ranlib s21_matrix_oop.a

clean:
	rm -rf *.o *.out *.a test
	rm -rf *.gcda *.gcno report gcov_report.* gcov_report *.info

rebuild:
	make clean
	make build

leaks: test
	valgrind --leak-check=full ./test

test: s21_matrix_oop.a test.cpp
	$(CC) $(CFLAGS) --coverage s21_matrix_oop.cpp test.cpp -o test -lgtest -lgmock -pthread
	./test

gcov_report: clean test
	lcov -t "test" -o s21_test.info --no-external -c -d .
	genhtml -o report s21_test.info
	open ./report/index.html