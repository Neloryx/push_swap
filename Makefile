NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS += -I.

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = main.c \
       algo/small_algo.c \
       algo/algo1.c \
       algo/algo2.c \
       algo/algo3.c \
	   basefunction/push.c \
	   basefunction/swap.c \
	   basefunction/rotate.c \
	   basefunction/reverserotate.c \
	   utils/bench.c \
	   utils/bench_ops.c \
	   utils/disorderchecker.c \
	   utils/duplicates.c \
	   utils/indexer.c \
	   utils/parse_flags.c \
	   utils/parse_ints.c \
	   utils/listfiller.c \
	   utils/error.c \

OBJS = $(SRCS:.c=.o)

AR = ar rcs

CYAN = \033[36m
GREEN = \033[32m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@$(MAKE) --no-print-directory banner

$(LIBFT): $(LIBFT_DIR)/Makefile $(wildcard $(LIBFT_DIR)/*.c)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

banner:
	@printf "$(CYAN)\n"
	@printf '%s\n' \
		'██████╗ ██╗   ██╗███████╗██╗  ██╗        ███████╗██╗    ██╗ █████╗ ██████╗' \
		'██╔══██╗██║   ██║██╔════╝██║  ██║        ██╔════╝██║    ██║██╔══██╗██╔══██╗' \
		'██████╔╝██║   ██║███████╗███████║        ███████╗██║ █╗ ██║███████║██████╔╝' \
		'██╔═══╝ ██║   ██║╚════██║██╔══██╗        ╚════██║██║███╗██║██╔══██║██╔═══╝' \
		'██║     ╚██████╔╝███████║██║  ██║███████║███████╔╝██║ ║██║ ██║  ██║██║' \
		'╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝ ╚═╝ ╚══╝ ╚═╝  ╚═╝╚═╝'
	@printf "$(RESET)$(GREEN)push_swap compiled successfully.$(RESET)\n\n"

clean:
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all banner clean fclean re