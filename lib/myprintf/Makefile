##
## EPITECH PROJECT, 2024
## My_printf
## File description:
## Makefile
##

NAME = libmyprintf.a
TEST_BIN = unit_tests

SRC = ./src/my_printf.c \
	./src/dprintf.c \
	./src/sprintf.c \
	./src/bprintf.c \
	./src/format_handle/format_handle1.c \
	./src/format_handle/format_handle2.c \
	./src/utils/is_num.c \
	./src/utils/my_put_nbr.c \
	./src/utils/my_strlen.c \
	./src/utils/numlen.c \
	./src/utils/my_putstr.c \
	./src/utils/my_putchar.c \
	./src/utils/my_allocs.c \
	./src/utils/decimal_len.c \
	./src/string_conversions/float_to_str.c \
	./src/utils/my_put_pos_float.c \
	./src/utils/rev_str.c \
	./src/utils/pick_shortest.c \
	./src/string_conversions/specifier_float.c \
	./src/string_conversions/specifier_hexadecimal.c \
	./src/string_conversions/spec_hex_float_up.c \
	./src/string_conversions/spec_hex_float_low.c \
	./src/string_conversions/specifier_integers.c \
	./src/string_conversions/specifier_octal.c \
	./src/string_conversions/specifier_scientific_notation.c \
	./src/string_conversions/specifier_str.c \
	./src/string_conversions/spec_unsigned.c \
	./src/string_conversions/char_to_str.c \
	./src/string_conversions/pointer_to_str.c \
	./src/utils/unlimited_power.c \
	./src/string_conversions/my_numtostr.c \
	./src/specifiers/a_spec.c \
	./src/specifiers/c_spec.c \
	./src/specifiers/cap_a_spec.c \
	./src/specifiers/cap_e_spec.c \
	./src/specifiers/cap_g_spec.c \
	./src/specifiers/cap_f_spec.c \
	./src/specifiers/cap_x_spec.c \
	./src/specifiers/d_spec.c \
	./src/specifiers/e_spec.c \
	./src/specifiers/f_spec.c \
	./src/specifiers/g_spec.c \
	./src/specifiers/n_spec.c \
	./src/specifiers/o_spec.c \
	./src/specifiers/p_spec.c \
	./src/specifiers/percent_spec.c \
	./src/specifiers/s_spec.c \
	./src/specifiers/u_spec.c \
	./src/specifiers/x_spec.c

TEST_SRC = $(SRC) \
	./tests/test_my_printf.c

CC = gcc
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall
INCLUDE_PATH = ./include/
LDFLAGS = -I$(INCLUDE_PATH)
TEST_LDFLAGS = $(LDFLAGS) --coverage -lcriterion



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
