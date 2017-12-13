##
## Makefile for makefile  in /home/gadrat_r/delivery/PSU/PSU_2016_malloc
## 
## Made by Romain Gadrat
## Login   <gadrat_r@epitech.net>
## 
## Started on  Wed Jan 25 11:40:05 2017 Romain Gadrat
## Last update Sun Feb 12 19:14:29 2017 Romain Gadrat
##

CC	=	gcc

NAME	=	libmy_malloc.so

SRC	=	src/myMalloc.c	\
		src/myFree.c	\
		src/myRealloc.c	\
		src/myShowAllocMem.c

LINK	=	libmy_malloc.so

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-I./include -W -Wall -Wextra -Werror -fPIC

RM	=	rm -fr

$(NAME)	:	$(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -shared -o $(NAME)

all	:	$(NAME)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re

