NAME1		:= server
NAME2		:= client
CFLAGS		:= -Wextra -Wall -Werror
FTPRINTF	:= ./printf

#HEADERS	:= -I ./include
LIBS	:= $(FTPRINTF)/libftprintf.a
SRCS1	:= server.c
SRCS2	:= client.c
OBJS1	:= $(SRCS1:.c=.o)
OBJS2	:= $(SRCS2:.c=.o)
CC 		= gcc $(CFLAGS)

all: ftprintf $(NAME1) $(NAME2)

ftprintf:
	@$(MAKE) -C $(FTPRINTF)

#%.o: %.c
#	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME1): $(SRCS1) $(OBJS1) 
	@$(CC) $(OBJS1) $(LIBS) -o $(NAME1)

$(NAME2): $(SRCS2) $(OBJS2) 
	@$(CC) $(OBJS2) $(LIBS) -o $(NAME2)

clean:
	@rm -f $(OBJS1) $(OBJS2)
	@$(MAKE) -C $(FTPRINTF) clean

fclean: clean
	@rm -f $(NAME1) $(NAME2)
	@$(MAKE) -C $(FTPRINTF) fclean

re: clean all
