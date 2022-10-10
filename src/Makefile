OS := $(shell uname -s)
SRC =  s21_check.c s21_credit.c s21_deposit.c s21_Engine.c s21_Stack.c 
SRC_FOR_TEST =   s21_check.c s21_credit.c s21_deposit.c s21_Engine.c s21_Stack.c  
OBJ = $(SRC:%.c=%.o)
MAIN = main.c

CC = gcc -std=c11

CFLAGS	= -Wall -Wextra -Werror
FLAGS_PLATFORM = -lcheck

TEST = s21_testest.c
FLAGS_PLATFORM = -lcheck

GCOVFLAGS = -fprofile-arcs -ftest-coverage
REPORT = GcovReport

ifeq ($(OS), Darwin)
	FLAGS_PLATFORM = -lcheck
else
	FLAGS_PLATFORM = -lcheck -lsubunit -lrt -lm -lpthread -g
endif

all: install

.PHONY: all, install, uninstall, clean, dvi, dist, tests, gcov_report

dvi:
	open dvi.html

test:
	@$(CC) $(CFLAGS) $(TEST) $(SRC_FOR_TEST) $(FLAGS_PLATFORM) -o tests.out
	@./tests.out

clean:
	@rm -rf *.{a,o,dSYM,out}
	@rm -rf $(EXECUTABLE)
	@rm -rf gcov_report
	@rm -rf report
	@rm -rf CPPLINT.cfg
	@rm -rf *.gcda
	@rm -rf *.gcno
	@rm -rf *.info
	@rm -rf test
	@rm -rf Archive_SmartCalc_v1.0
	@rm -rf *tgz
	@rm -rf build
	@rm -rf gcov_test

check: $(NAME)
	@echo ---------------------CPPCHECK---------------------
	@cppcheck *.h $(SRC)
	@echo ---------------------CPPLINT----------------------
	@cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	@python3 ../materials/linters/cpplint.py --extension=c $(SRC) $(TEST) *.h *.c
	@rm CPPLINT.cfg
	@make leaks

leaks:
	@echo -------------------MEMORY_LEAKS-------------------
	$(CC) -g $(TEST) $(SRC) $(FLAGS_PLATFORM) -o unit.out
	CK_FORK=no leaks --atExit -- ./unit.out

gcov_report:
	gcc $(GCOVFLAGS) $(TEST) $(SRC) $(FLAGS_PLATFORM) -o $(REPORT)
	chmod +x *
	./GcovReport
	lcov -t "$(REPORT)" -o $(REPORT).info -c -d .
	genhtml -o report $(REPORT).info
	rm -rf ./*.gcno ./*.gcda ./$(REPORT).*
	open ./report/index.html
	rm $(REPORT)
	rm -rf *.dSYM


install:
	make clean
	mkdir build
        cd ../SmartCalc && qmake && make && make clean && rm Makefile && cd ../ && mv SmartCalc/SmartCalc.app build
        cd ../build/Contents/MacOS && open SmartCalc

open:
        cd ../build/Contents/MacOS && open SmartCalc

uninstall:
	@rm -rf ../build*
dist:
	rm -rf ../Archive_SmartCalc_v1.0/
	mkdir ../Archive_SmartCalc_v1.0/
	mkdir ../Archive_SmartCalc_v1.0/src
	cp ../build/Contents/MacOS/SmartCalc ../Archive_SmartCalc_v1.0/src/
	cd .. && tar cvzf Archive_SmartCalc_v1.0.tgz ../Archive_SmartCalc_v1.0 && mv Archive_SmartCalc_v1.0 src/
cl:
	rm -rf ../Archive_SmartCalc_v1.0
	
bist:
	rm -rf ../Archive_SmartCalc_v1.0/
	mkdir ../Archive_SmartCalc_v1.0/
	mkdir ../Archive_SmartCalc_v1.0/src
	cp ../build/Contents/MacOS/SmartCalc ../Archive_SmartCalc_v1.0/src/
	mv ../Archive_SmartCalc_v1.0/ .
	tar cvzf Archive_SmartCalc_v1.0.tgz Archive_SmartCalc_v1.0
	open .
