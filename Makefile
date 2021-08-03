NAME	=	libftprintf.a
SRCDIR	=	./srcs
SRCLIST	=	ft_printf.c \
			ft_format_utils.c
SRCS	=	$(addprefix $(SRCDIR)/, $(SRCLIST))
OBJS	=	$(SRCLIST:.c=.o)
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

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

bonus: $(NAME)

.PHONY: all clean fclean re bonus

