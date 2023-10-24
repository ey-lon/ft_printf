# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abettini <abettini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 14:36:43 by abettini          #+#    #+#              #
#    Updated: 2023/04/02 14:59:40 by abettini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#----------------------------------------------

NOCOL = \e[0m
GREEN = \e[1;92m
RED = \e[1;31m
CYAN = \e[1;36m
TCOL = $(CYAN)
RMD = $(GREEN)successfully $(RED)removed$(NOCOL)
CMP = $(GREEN)successfully compiled$(NOCOL)

#----------------------------------------------

CC = cc

RM = /bin/rm

NAME = libftprintf.a

SRC :=	src/ft_printf.c \
	src/ft_print_chr.c \
	src/ft_print_str.c \
	src/ft_print_dec.c \
	src/ft_print_uns.c \
	src/ft_print_hex.c \
	src/ft_print_ptr.c

BNS :=	src_bonus/ft_printf_bonus.c \
	src_bonus/ft_print_chr_bonus.c \
	src_bonus/ft_print_str_bonus.c \
	src_bonus/ft_print_dec_bonus.c \
	src_bonus/ft_print_uns_bonus.c \
	src_bonus/ft_print_hex_bonus.c \
	src_bonus/ft_print_ptr_bonus.c \
	src_bonus/ft_print_unknown_bonus.c \
	src_bonus/ft_flags_bonus.c \
	src_bonus/ft_flags_set_bonus.c \
	src_bonus/ft_flags_utils_bonus.c \
	src_bonus/utils_bonus.c

OBJ_S = $(SRC:.c=.o)

OBJ_B = $(BNS:.c=.o)

CFLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ_S)
	@ar -d $(NAME) $(OBJ_B)
	@ar -rcs $@ $^
	echo "$(TCOL)$(NAME) $(CMP)"

%.o:%.c
	@$(CC) -c $(CFLAG) -I. $< -o $@

clean:
	if [ `find . -name "*.o" | wc -l` != 0 ]; then\
		$(RM) -f $(OBJ_S);\
		$(RM) -f $(OBJ_B);\
		echo "$(TCOL)object files ($(NAME)) $(RMD)";\
	fi

fclean: clean
	if [ -f $(NAME) ]; then\
		$(RM) -f $(NAME);\
		echo "$(TCOL)$(NAME) $(RMD)";\
	fi

bonus: $(OBJ_B)
	@ar -d $(NAME) $(OBJ_S)
	@ar -rcs $(NAME) $^
	echo "$(TCOL)$(NAME) w/ bonus $(CMP)"

re: fclean all

.PHONY: all clean fclean re bonus

.SILENT:
