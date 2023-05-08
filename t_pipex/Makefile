NAME = pipex

SRCS_DIR := src/
SRCS =	src/pipex.c		\
		src/utils.c		\

CFLAGS = -Wall -Wextra #-Werror
CINCLUDES += -I include/

LIBFT_DIR = lib/libft/
LIBFT =  $(LIBFT_DIR)libft.a

LIBFT_FLAGS = -L./$(LIBFT_DIR) -lft
CINCLUDES += -I $(LIBFT_DIR)

ifeq ($(shell uname), Darwin)
	MSG = MacOS
else
	MSG = Linux
endif

all: $(NAME)

$(NAME): $(SRCS) | $(LIBFT)
	@echo $(GREEN) 
	cc $(CFLAGS) $(CINCLUDES) $^ -o $@ $(LIBFT_FLAGS)
	$(BANNER_FDF)

$(LIBFT):
	@echo $(BLUE)
	@make -C $(LIBFT_DIR)

cmd1: $(NAME)
	@echo $(NOCOLOR) 
	./pipex infile "ls" "grep" outfile

cmd2: $(NAME)
	@echo $(NOCOLOR) 
	./pipex infile "ls -la" "wc" outfile

cmd3: $(NAME)
	@echo $(NOCOLOR) 
	./pipex infile "cat" "wc -w" outfile

cmd4: $(NAME)
	@echo $(NOCOLOR) 
	./pipex infile "" "wc" outfile
	cat ./outfile

pipe: $(NAME)
	@echo $(NOCOLOR) 
	@rm -f outfile
	$(shell  <infile l| wc )
	cat ./outfile
# < infile ls | wc -w > outfile

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

#sudo apt-get update && sudo apt-get install xorg libxext-dev zlib1g-dev libbsd-dev
#export DISPLAY=$(cat /etc/resolv.conf | grep nameserver | awk '{print $2}'):0.0