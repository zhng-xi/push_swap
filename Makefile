NAME	= push_swap
CFLAGS	= -Wall -Wextra -Werror -g
LIBFT	= cd includes/libft
PRINTF	= cd includes/libft/ft_printf
SRCS	= source/push_swap.c \
			source/ft_atol.c \
			source/fill_stack.c \
			source/find.c \
			source/check_input.c \
			source/ra_rb_rr.c \
			source/rra_rrb_rrr.c \
			source/sa_sb_ss_pa_pb.c \
			source/size.c \
			source/start_sort.c \
			source/sort_utils.c \
			source/sort_utils2.c \
			source/sort_utils3.c \
			source/sort_utils4.c

OBJS		= $(SRCS:.c=.o)

$(NAME): $(OBJS)
			@$(LIBFT) && make all
			@$(PRINTF) && make all
			cc $(CFLAGS) $(SRCS) -o $(NAME) includes/libft/ft_printf/libftprintf.a includes/libft/libft.a
			@echo "Have fun testing!"

all:	$(NAME)

clean:
			@$(LIBFT) && make clean
			@$(PRINTF) && make clean
			rm -f $(OBJS)
			@echo "Objectfiles were removed."

fclean:	clean
			@$(LIBFT) && make fclean
			@$(PRINTF) && make fclean
			rm -f $(NAME)
			@echo "Everything is clean now!"

re:		fclean all

.PHONY: all clean fclean re ft_printf libft
