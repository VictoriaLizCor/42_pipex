# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: melkholy <melkholy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/25 23:23:16 by melkholy          #+#    #+#              #
#    Updated: 2022/09/08 21:38:46 by melkholy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = libftprintf.a
CDIR = .
LIBFTDIR = ./libft/
LIBFT = ./libft/libft.a
CFLAGS = -Wall -Werror -Wextra

CFILES = ft_printf.c printf_specifiers.c printf_utils.c

BFILES = ft_printf_bonus.c alloc_width_prec_bonus.c \
			format_wandp_bonus.c hexa_and_ptr_bonus.c \
			int_and_unsigned_bonus.c speci_width_prec_bonus.c \
			string_and_char_bonus.c

OBJ = ${CFILES:.c=.o}
BOBJ = ${BFILES:.c=.o}

all : $(NAME)

$(NAME) : $(LIBFT)
	@$(CC) $(CFLAGS) -I$(CDIR) -c $(CFILES)
	@ar -rs $(NAME) $(OBJ)
	@ranlib $(NAME)

bonus : $(LIBFT)
	@$(CC) $(CFLAGS) -I$(CDIR) -c $(BFILES)
	@ar -rs $(NAME) $(BOBJ)
	@ranlib $(NAME)

$(LIBFT) :
	@make -C $(LIBFTDIR)
	@cp $(LIBFT) $(NAME)

clean :
	@make clean -C $(LIBFTDIR)
	@rm -f $(OBJ) $(BOBJ)

fclean : clean
	@make fclean -C $(LIBFTDIR)
	@rm -f $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re
