NAME	=	libftprintf.a
SRCDIR	=	./srcs
SRCLIST	=	ft_printf.c \
			ft_printf_utils.c \
			ft_load_format.c \
			ft_format_typec.c \
			ft_format_types.c
SRCS	=	$(addprefix $(SRCDIR)/, $(SRCLIST))
OBJS	=	$(SRCS:.c=.o)
INCLUDE	=	-I ./includes
LIBDIR	=	./libft
LIBFT	=	$(LIBDIR)/libft.a
CC		=	gcc
CFLAG	=	-Wall -Wextra -Werror

%.o: %.c
	$(CC) $(CFLAG) $(INCLUDE) -o $@ -c $<

$(NAME): $(OBJS)
	make bonus -C $(LIBDIR)
	cp $(LIBFT) $(NAME)
	ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
	make clean -C $(LIBDIR)
	rm -f $(OBJS)

fclean:
	make fclean -C $(LIBDIR)
	rm -f $(OBJS)
	rm -f $(NAME)

re: fclean $(NAME)

bonus: $(NAME)

.PHONY: all clean fclean re bonus
