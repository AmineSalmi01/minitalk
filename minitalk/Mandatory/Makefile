NAME_CLIENT = client
NAME_SERVER = server

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRC_CLIENT = client.c client_utils.c
SRC_SERVER = server.c server_utils.c

OBJC = $(SRC_CLIENT:.c=.o)
OBJS = $(SRC_SERVER:.c=.o)

all : $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT) : $(OBJC) minitalk.h
	$(CC) $(CFLAGS) $(OBJC) -o $@

$(NAME_SERVER) : $(OBJS) minitalk.h
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o : %.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJC) $(OBJS)

fclean : clean
	$(RM) $(NAME_CLIENT) $(NAME_SERVER)

re : fclean all

.PHONY : clean