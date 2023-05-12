# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: melkholy <melkholy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/08 21:08:25 by melkholy          #+#    #+#              #
#    Updated: 2022/09/13 00:10:34 by melkholy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = pipex
CDIR = .
LIBFTDIR = ./ft_printf/
LIBFT = ./ft_printf/libftprintf.a
CFLAGS = -Wall -Werror -Wextra

CFILES = pipex.c pipex_processing.c pipex_helper.c pipex_utils.c

BFILES = pipex_bonus.c pipex_processing_bonus.c pipex_helper_bonus.c \
		 pipex_utils_bonus.c pipex_heredoc_bonus.c

all : $(NAME)

$(NAME) : $(LIBFT)
	@$(CC) $(CFLAGS) -I$(CDIR) $(CFILES) $(LIBFT) -o $(NAME)

bonus : $(LIBFT)
	@$(CC) $(CFLAGS) -I$(CDIR) $(BFILES) $(LIBFT) -o $(NAME)

$(LIBFT) :
	@make -C $(LIBFTDIR)

clean :
	@make clean -C $(LIBFTDIR)
	@rm -f $(NAME)

fclean : clean
	@make fclean -C $(LIBFTDIR)
	@rm -f $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re
