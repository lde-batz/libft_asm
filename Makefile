# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-batz <lde-batz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/25 20:50:34 by lde-batz          #+#    #+#              #
#    Updated: 2020/10/19 17:52:56 by lde-batz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLEAR_LINE	= \033[2K
BEGIN_LINE	= \033[A
COL_END		= \033[0m
COL_RED		= \033[1;31m
COL_GREEN	= \033[1;32m
COL_YELLOW	= \033[1;33m
COL_BLUE	= \033[1;34m
COL_VIOLET	= \033[1;35m
COL_CYAN	= \033[1;36m
COL_WHITE	= \033[1;37m

NAME :=	libasm.a

SRC :=	ft_strlen.s \
		ft_strcpy.s \
		ft_strcmp.s \
		ft_write.s \
		ft_read.s \
		ft_strdup.s \

SRCB :=	ft_bzero.s \
		ft_tolower.s \
		ft_toupper.s \
		ft_list_push_front.s \
		ft_list_size.s \

SRC_DIR := srcs/
SRCB_DIR := bonus/

SRC := $(addprefix $(SRC_DIR), $(SRC))
SRCB := $(addprefix $(SRCB_DIR), $(SRCB))

SRC += $(SRCB)

OBJ := 	$(SRC:.s=.o)

PWD :=	$(shell pwd)

OBJDIR := 	obj

OBJP :=		$(addprefix $(OBJDIR)/, $(SRC:.s=.o))
ONLYDIR :=	$(foreach dir, $(OBJP), $(shell dirname $(dir)))

FLAG :=	-f macho64
CC :=	nasm $(FLAG)

TOTAL_FILES := $(shell echo $(SRC) | wc -w | sed -e 's/ //g')
CURRENT_FILES = $(shell ls $(PWD)/obj/ 2> /dev/null | wc -l | sed -e 's/ //g')

.SILENT:

all : $(NAME)

$(NAME) : $(OBJP)
	ar rc $(NAME) $(OBJP)
	ranlib $(NAME)
	echo "$(CLEAR_LINE)$(COL_BLUE)[$(NAME)] $(COL_YELLOW)Finished compilation. Output file : $(COL_VIOLET)$(PWD)/$(NAME)$(COL_END)"

$(OBJDIR)/%.o: %.s libfts.h
	mkdir -p $(ONLYDIR)
	$(CC) $< -o $@
	echo "$(CLEAR_LINE)$(COL_BLUE)[$(NAME)] $(COL_YELLOW)Compiling file [$(COL_VIOLET)$<$(COL_YELLOW)]. ($(CURRENT_FILES) / $(TOTAL_FILES))$(COL_END)$(BEGIN_LINE)"

clean :
	rm -rf $(OBJDIR)
	echo "$(COL_BLUE)[$(NAME)] $(COL_YELLOW)Removed $(COL_VIOLET)compiled objects.$(COL_END)"

fclean : clean
	rm -rf $(NAME)
	echo "$(COL_BLUE)[$(NAME)] $(COL_YELLOW)Removed $(COL_VIOLET)$(NAME)$(COL_END)"

re : fclean all

main : $(NAME)
	gcc -Wall -Wextra main.c -I libfts.h -L ./ -lasm -o main_test

main2 : $(NAME)
	gcc -Wall -Wextra main2.c -I libfts.h -L ./ -lasm -o main_test


mclean :
	rm -rf main_test

.PHONY: all clean fclean re
