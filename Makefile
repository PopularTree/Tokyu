SRCS = main.c siritori.c find_end_of_word.c check_vowel.c
CC = gcc
CFLAG = -Wall -Wextra -Werror

all:
	$(CC) $(CFLAG) -o siritori $(SRCS)

act:
	./siritori data.txt

clean:
	rm siritori

re: clean all

.PHONEY: all clean re