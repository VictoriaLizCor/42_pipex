NAME = pipex

SRCS_DIR := src/
SRCS =	src/pipex.c		\
		src/utils.c		\

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address
CINCLUDES += -I include/

LIBFT_DIR = lib/libft/
LIBFT =  $(LIBFT_DIR)libft.a

LIBFT_FLAGS = -L./$(LIBFT_DIR) -lft
CINCLUDES += -I $(LIBFT_DIR)

all: $(NAME)

$(NAME): $(SRCS) | $(LIBFT)
	@echo $(GREEN)
	cc $(CFLAGS) $(CINCLUDES) $^ -o $@ $(LIBFT_FLAGS)
	$(BANNER_FDF)

$(LIBFT):
	@echo $(BLUE)
	@make -C $(LIBFT_DIR)

cleaks: $(NAME)
	leaks --atExit -- ./pipex infile "/bin/cat" "wc" oufile
	@echo "---"
	cat oufile

cval: $(NAME)
	valgrind  --leak-check=full --track-fds=yes --trace-children=yes -s -q ./pipex infile "cat"  "tr a-z A-Z"  outfile
	@echo "----"
	cat outfile

pval: $(NAME)
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all --track-fds=yes --trace-children=yes -s -q <infile cat | tr a-z A-Z >outfile
	@echo "----"
	cat outfile

pleaks: $(NAME)
	leaks --atExit -- <infile cat | tr a-z A-Z >outfile
	@echo "---"
	cat oufile

clean:
	@echo $(RED)
	@echo "\n************  CLEAN LIBFT ************" 
	@make -C $(LIBFT_DIR) clean

fclean:	clean
	@echo "\n************  FCLEAN LIBFT  ************"
	@make -C $(LIBFT_DIR) fclean
	@echo "\n************  FCLEAN ROOT   ************"
	rm -f $(NAME)
	@echo "\n"

re: fclean all

.PHONY: all clean fclean re

define PIPEX_IMG

			▒▒▒▒▒▒▒▒▒▄▄▄▄▒▒▒▒▒▒▒
			▒▒▒▒▒▒▄▀▀▓▓▓▀█▒▒▒▒▒▒
			▒▒▒▒▄▀▓▓▄██████▄▒▒▒▒
			▒▒▒▄█▄█▀░░▄░▄░█▀▒▒▒▒
			▒▒▄▀░██▄░░▀░▀░▀▄▒▒▒▒
			▒▒▀▄░░▀░▄█▄▄░░▄█▄▒▒▒
			▒▒▒▒▀█▄▄░░▀▀▀█▀▒▒▒▒▒
			▒▒▒▄▀▓▓▓▀██▀▀█▄▀▀▄▒▒
			▒▒█▓▓▄▀▀▀▄█▄▓▓▀█░█▒▒
			▒▒▀▄█░░░░░█▀▀▄▄▀█▒▒▒
			▒▒▒▄▀▀▄▄▄██▄▄█▀▓▓█▒▒
			▒▒█▀▓█████████▓▓▓█▒▒
			▒▒█▓▓██▀▀▀▒▒▒▀▄▄█▀▒▒
			▒▒▒▀▀▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒

	██╗  ██╗██████╗     ██████╗ ██╗██████╗ ███████╗██╗  ██╗
	██║  ██║╚════██╗    ██╔══██╗██║██╔══██╗██╔════╝╚██╗██╔╝
	███████║ █████╔╝    ██████╔╝██║██████╔╝█████╗   ╚███╔╝ 
	╚════██║██╔═══╝     ██╔═══╝ ██║██╔═══╝ ██╔══╝   ██╔██╗ 
	     ██║███████╗    ██║     ██║██║     ███████╗██╔╝ ██╗
	     ╚═╝╚══════╝    ╚═╝     ╚═╝╚═╝     ╚══════╝╚═╝  ╚═╝
	

endef
export PIPEX_IMG

CROSS = "\033[8m"
RED = "\033[0;1;91m"
GREEN = "\033[0;1;32m"
BLUE = "\033[0;1;34m"
NOCOLOR	= "\033[m"
BANNER_FDF = @echo $(GREEN) "$$PIPEX_IMG"
