##
## Makefile for  in /home/gaonac_l/rendu/asm_minilibc
##
## Made by
## Login   <gaonac_l@epitech.net>
##
## Started on  Mon Mar  7 14:13:14 2016
## Last update Sun Mar 27 19:19:12 2016 
##

NAME	=	libasm.so

AS	=	nasm -f elf64

RM	=	rm -f

CC	=	gcc

CFLAGS	+=	-W -Wall -Werror -Wextra -fPIC

LDFLAGS	+=	-shared

SRC	=	memcpy.s	\
		memmove.s	\
		memset.s	\
		strcmp.s	\
		rindex.s	\
		strcasecmp.s	\
		strchr.s	\
		strcspn.s	\
		strlen.s	\
		strncmp.s	\
		strpbrk.s	\
		strstr.s

OBJ	=	$(SRC:.s=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		$(CC) $(LDFLAGS) -o $(NAME) $(OBJ)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all fclean re
