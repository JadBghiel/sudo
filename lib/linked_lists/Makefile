##
## EPITECH PROJECT, 2024
## My_printf
## File description:
## Makefile
##

NAME = liblinked_lists.a

SRC = src/list_creation.c \
	src/list_parse.c
CC = gcc
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall
INCLUDE_PATH = ./include/
LDFLAGS = -I$(INCLUDE_PATH)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)
	cp $(NAME) ..
	cp $(INCLUDE_PATH)*.h ../../include/

$(TEST_BIN):
	$(CC) $(CFLAGS) -o $(TEST_BIN) $(TEST_SRC) $(TEST_LDFLAGS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

clean:
	rm -f $(OBJ)
	rm -f *.gc*

fclean: clean
	rm -f $(NAME)
	rm -f $(TEST_BIN)

re: fclean $(NAME)

compile:
	$(CC) $(CFLAGS) $(SRC) $(LDFLAGS)

tests_run: $(TEST_BIN)
	./$(TEST_BIN)

coverage: tests_run
	gcovr -r .
	gcovr -r . --branches
