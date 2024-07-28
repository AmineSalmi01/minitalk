NAME_CLIENT = client_bonus
NAME_SERVER = server_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRC_CLIENT = client_bonus.c client_utils_bonus.c
SRC_SERVER = server_bonus.c server_utils_bonus.c

OBJC = $(SRC_CLIENT:.c=.o)
OBJS = $(SRC_SERVER:.c=.o)

all : $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT) : $(OBJC) minitalk_bonus.h
	$(CC) $(CFLAGS) $(OBJC) -o $@

$(NAME_SERVER) : $(OBJS) minitalk_bonus.h
	$(CC) $(CFLAGS) $(OBJS) -o $@

%.o : %.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJC) $(OBJS)

fclean : clean
	$(RM) $(NAME_CLIENT) $(NAME_SERVER)

re : fclean all

.PHONY : clean