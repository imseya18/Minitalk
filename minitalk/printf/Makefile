LIBFT = libft/libft.a

NAME = libftprintf.a

SOURCES =	ft_printf.c \
			ft_list.c \
			ft_itoa_u.c \
			ft_hexa_maj.c \
			ft_hexa.c \
			ft_list_s.c \
			ft_address.c \
			ft_format.c \
			ft_format_free.c 


OBJECTS = $(SOURCES:.c=.o)
FLAGS = -Wall -Wextra -Werror
CC = cc $(FLAGS)

all: $(NAME)

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJECTS)
fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)
re: fclean $(NAME)

$(NAME): $(SOURCES) $(OBJECTS)
	$(MAKE) bonus -C ./libft
	cp $(LIBFT) $(NAME)
	ar -rcs $(NAME) $(OBJECTS)
