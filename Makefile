##
## EPITECH PROJECT, 2024
## my_sudo
## File description:
## Makefile
##

SRC = src/main.c \
	src/sudoers.c

NAME = my_sudo
TEST_BIN = unit_tests

CC = gcc
CFLAGS = -Wall
LDFLAGS = -I./include/ -L./lib/ -llinked_lists -lcrypt
TEST_LDFLAGS = $(LDFLAGS) --coverage -lcriterion

all: $(NAME)

$(NAME): make_libs
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(LDFLAGS)

$(TEST_BIN): make_libs
	$(CC) $(CFLAGS) -o $(TEST_BIN) $(TEST_SRC) $(TEST_LDFLAGS)

clean:
	rm -f *.gc*
	$(MAKE) -C ./lib/ clean

fclean: clean
	rm -f $(NAME)
	rm -f $(TEST_BIN)
	$(MAKE) -C ./lib/ fclean

set_perm:
	sudo chown root $(NAME)
	sudo chmod u+s $(NAME)

re: fclean $(NAME)

compile:
	$(CC) $(CFLAGS) $(SRC) $(LDFLAGS)

tests_run: $(TEST_BIN)
	./$(TEST_BIN)

make_libs:
	$(MAKE) -C ./lib/ make_libs
