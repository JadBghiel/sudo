##
## EPITECH PROJECT, 2024
## my_ls
## File description:
## Makefile
##

LIBRARIES = ./myprintf/ \
	./linked_lists/

all: make_libs

make_libs:
	$(MAKE) -C ./myprintf/
	$(MAKE) -C ./linked_lists

clean:
	$(MAKE) -C ./myprintf/ clean
	$(MAKE) -C ./linked_lists/ clean

fclean:
	$(MAKE) -C ./myprintf/ fclean
	$(MAKE) -C ./linked_lists/ fclean
	rm -f *.a
re:
	$(MAKE) -C ./myprintf/ re
	$(MAKE) -C ./linked_lists/ re
