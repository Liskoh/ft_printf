# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hjordan <hjordan@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/14 11:03:02 by hjordan           #+#    #+#              #
#    Updated: 2021/02/03 13:35:27 by hjordan          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
CC=gcc
CFLAGS= -Wall -Wextra -Werror
SRCS_PATH= srcs
CONVERTERS_PATH= $(SRCS_PATH)/converters
BONUS_PATH= $(SRCS_PATH)/bonus
RM=rm -f
SRCS= ft_printf.c \
	  $(SRCS_PATH)/flag_utils.c \
	  $(SRCS_PATH)/ft_itoa.c \
	  $(SRCS_PATH)/ft_unsigned_itoa.c \
	  $(SRCS_PATH)/ft_putstr.c \
	  $(SRCS_PATH)/ft_strdup.c \
	  $(SRCS_PATH)/ft_strlen.c \
	  $(SRCS_PATH)/ft_atoi.c \
	  $(SRCS_PATH)/ft_addr_del.c \
	  $(SRCS_PATH)/ft_putchar.c \
	  $(SRCS_PATH)/pf_utils.c \
	  $(SRCS_PATH)/pf_parser.c \
	  $(SRCS_PATH)/pf_conversion.c \
	  $(SRCS_PATH)/ft_itoa_base.c \
	  $(SRCS_PATH)/ft_str_del.c \
	  $(SRCS_PATH)/ft_ltoa_base.c \
	  $(SRCS_PATH)/ft_strjoin_free.c \
	  $(CONVERTERS_PATH)/ft_convert_percentage.c \
	  $(CONVERTERS_PATH)/ft_convert_char.c \
	  $(CONVERTERS_PATH)/ft_convert_int.c \
	  $(CONVERTERS_PATH)/ft_convert_string.c \
	  $(CONVERTERS_PATH)/ft_convert_unsigned_int.c \
	  $(CONVERTERS_PATH)/ft_convert_hexadecimal.c \
	  $(CONVERTERS_PATH)/ft_convert_pointer.c \
	  $(CONVERTERS_PATH)/extra_converters.c \
	  $(BONUS_PATH)/ft_apply_size_converter.c
OBJS=$(SRCS:.c=.o)
INC=includes/ft_printf.h

%.c%.o:
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

all:	$(NAME)

$(OBJS):	$(INC)

$(NAME): 	$(INC) $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: 	$(INC) $(BONUS_OBJS)
	ar rcs $(NAME) $(BONUS_OBJS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: 	clean
	$(RM) $(NAME)

re:		fclean all
