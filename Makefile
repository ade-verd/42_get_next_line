# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-verd <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/05 13:46:57 by ade-verd          #+#    #+#              #
#    Updated: 2017/12/08 20:24:18 by ade-verd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line

SRC_PATH = src/
SRC_NAME = main.c get_next_line.c

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_PATH = obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

CPPFLAGS = -Iinclude -Ilibft
LDFLAGS = -L libft
LDLIBS = -lft
LIB_PATH = libft
INC_PATH = include/

CC = gcc

ifeq ($(UNAME), Darwin)
	CC := gcc
	CFLAGS += -Werror -Wall -Wextra
endif
ifeq ($(UNAME), Linux)
	ifeq (, $(shell which clang))
		CC := gcc
	else
		CC := clang
	endif
	CFLAGS += -Wno-unused-result
endif
ifeq ($(UNAME), CYGWIN_NT-6.3)
	CC := gcc
	CFLAGS += -I./libft/inc
endif

#Colors font
C_NO = "\033[00m"
C_DONE = "\033[35m"
C_GOOD = "\033[32m"
C_ERROR = "\033[31m"
C_WARN = "\033[33m"

SUCCESS = $(C_GOOD)SUCCESS$(C_NO)
DONE = $(C_DONE)DONE$(C_NO)
ERROR = $(C_ERROR)ERROR$(C_NO)
WARNING = $(C_WARN)WARNING$(C_NO)

#Rules
.PHONY: all, clean, fclean, re, norme

all: $(NAME)

$(NAME): lib obj $(OBJ) $(INC_PATH)
	$(CC) $(LDFLAGS) $(LDLIBS) $(OBJ) -o $(NAME)
	@echo "Compiling -> " $(NAME) $(SUCCESS)

lib:
	@make -C $(LIB_PATH)

obj:
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
	@echo "Linking -> " $< $(DONE)

clean:
	rm -fv $(OBJ)
	@rm -Rf $(OBJ_PATH)
	@echo "Cleaning all the Fillit objects -> " $(SUCCESS)
	@make -C $(LIB_PATH) clean

fclean: clean
	rm -fv $(NAME)
	@make -C $(LIB_PATH) clean_only_lib
	@echo "Deleting -> " $(NAME) $(SUCCESS)

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h

# **************************************************************************** #
# Personal notes :
#
# $@ : rule's name
# $^ : all dependencies after ':'
# $< : corresponding dependency
# || : if there is an error, execute the command after the double pipe
#
# **************************************************************************** #
