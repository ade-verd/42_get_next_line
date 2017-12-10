# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 16:30:07 by ade-verd          #+#    #+#              #
#    Updated: 2017/12/10 15:19:13 by ade-verd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
CC = gcc

INC_DIR = ./
SRC_DIR = ./
SRC_1 = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c\
		ft_memchr.c ft_memcmp.c\
		\
		ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c\
		ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c\
		ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c\
		\
		ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
		ft_toupper.c ft_tolower.c

SRC_2 = ft_memalloc.c ft_memdel.c\
		\
		ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c\
		ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c\
		ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c\
		\
		ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c\
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRC_BONUS = ft_lstnew.c ft_lstadd.c\
			ft_lstdelone.c ft_lstdel.c\
			ft_lstiter.c ft_lstmap.c

SRC_EXTRA = ft_abs.c ft_intlen.c ft_power.c ft_sqrt.c ft_int_sqrt.c\
			ft_countwords.c ft_swap.c ft_memccpy_src.c

SRC = $(SRC_1) $(SRC_2) $(SRC_BONUS) $(SRC_EXTRA)
OBJ = $(SRC:.c=.o)

C_NO = "\033[00m"
C_DONE = "\033[35m"
C_GOOD = "\033[32m"
C_ERROR = "\033[31m"
C_WARN = "\033[33m"

SUCCESS = $(C_GOOD)SUCCESS$(C_NO)
DONE = $(C_DONE)DONE$(C_NO)
ERROR = $(C_ERROR)ERROR$(C_NO)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -c $(SRC) -I $(INC_DIR)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "Compiling & Indexing -> " $(NAME) $(SUCCESS)

clean:
	@rm -f $(OBJ)
	@echo "Deleting object files -> " $(SUCCESS)

fclean: clean
	@rm -f $(NAME)
	@echo "Deleting library -> " $(NAME) $(SUCCESS)

clean_only_lib:
	@rm -f $(NAME)
	@echo "Deleting library -> " $(NAME) $(SUCCESS)

re: fclean all
