# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/30 13:32:36 by lilizarr          #+#    #+#              #
#    Updated: 2023/05/02 16:52:26 by lilizarr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Target
NAME = libft.a

#compiling
FLAGS := -Wall -Wextra -Werror
#source files
SRC_LIBFT :=	ft_atoi.c					\
				ft_atol.c					\
				ft_bzero.c					\
				ft_calloc.c					\
				ft_isalnum.c				\
				ft_isalpha.c				\
				ft_isascii.c				\
				ft_isdigit.c				\
				ft_isprint.c				\
				ft_itoa.c					\
				ft_memchr.c					\
				ft_memcmp.c					\
				ft_memcpy.c					\
				ft_memmove.c				\
				ft_memset.c					\
				ft_putchar_fd.c				\
				ft_putendl_fd.c				\
				ft_putnbr_fd.c				\
				ft_putstr_fd.c				\
				ft_split.c					\
				ft_strchr.c					\
				ft_strdup.c					\
				ft_striteri.c				\
				ft_strjoin.c				\
				ft_strlcat.c				\
				ft_strlcpy.c				\
				ft_strlen.c					\
				ft_strmapi.c				\
				ft_strncmp.c				\
				ft_strnstr.c				\
				ft_strrchr.c				\
				ft_strtrim.c				\
				ft_substr.c					\
				ft_tolower.c				\
				ft_toupper.c				\
				get_next_line_bonus.c 		\
				get_next_line_utils_bonus.c \
				ft_printf_type.c			\
				ft_printf_utils.c			\
				ft_printf.c					\
				ft_utils.c

OBJS_LIBFT_DIR = obj/
OBJS_LIBFT = $(addprefix $(OBJS_LIBFT_DIR), $(SRC_LIBFT:.c=.o))

# Make sure these aren't treated as files
.PHONY: all fclean re clean

# Make desired targets
all: $(OBJS_LIBFT_DIR) $(NAME)

#creating *.o directory
$(OBJS_LIBFT_DIR) : 
	@mkdir -p $@
	@echo mkdir -p $(shell pwd | awk -F / '{print $$(NF-1)"/"$$(NF)}')/$(OBJS_LIBFT_DIR)
#echoes : 
#	echo $(addprefix $(OBJ_DIR), $(SRC_LIBFT:.c=.o))

# Make the object files
$(addprefix $(OBJS_LIBFT_DIR), %.o): %.c
	@cc -c $(FLAGS) $^ -o $@

# Make standard libft archive
$(NAME): $(OBJS_LIBFT)
	ar -rcs $@ $^
	ar -t $@
#	chmod 777 $(NAME)

# Clean intermediary files
clean:
	@rm -rf $(OBJS_LIBFT_DIR)
	@echo rm -f $(shell pwd | awk -F / '{print $$(NF-1)"/"$$(NF)}')/$(OBJS_LIBFT_DIR)
# Clean all non-source files
fclean: clean
	@rm -f $(NAME)
	@echo rm -f $(shell pwd | awk -F / '{print $$(NF-1)"/"$$(NF)}')/$(NAME)
 
# Wipe all and make again
re: fclean all

#pwd | awk -F / '{print $(NF-2)"/"$(NF-1)"/"$(NF)}'