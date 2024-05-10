# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryusukeyashiro <ryusukeyashiro@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/07 19:13:47 by ryusukeyash       #+#    #+#              #
#    Updated: 2024/05/09 21:36:31 by ryusukeyash      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = srcs/ft_printf.c \
			srcs/ft_print_hex.c \
			srcs/ft_print_int.c \
			srcs/ft_print_percent.c \
			srcs/ft_print_pointa.c \
			srcs/ft_print_str.c \
			srcs/ft_print_unit.c \

OBJS = $(SRCS:.c=.o)

LIBFT_PATH = ./Libft

LIBFT_NAME = Libft.a

INCLUDES = include 

CC = cc

CFLAGS = -Wall -Wextra -Werror

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(INCLUDES)

all : ${NAME}

$(NAME):$(OBJS)
		make -C $(LIBFT_PATH) all
		ar -rcs  $(NAME) $(OBJS)
		ranlib $(NAME)

clean:
		rm -f $(OBJS)
		@make -C $(LIBFT_PATH) clean 

fclean: clean 
		rm -f $(NAME)
		rm -f $(LIBFT_PATH)/$(LIBFT_NAME)
		
re:  fclean all

.PHONY: all clean fclean re
