CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC = libft.h
SRC = ft_putchar.c ft_putstr.c ft_strcmp.c \
	  ft_strlen.c ft_swap.c
OBJECTS = $(SRC:.c=.o)
NAME = libft.a

all : $(NAME)

$(OBJECTS) : $(SRC)
	$(CC) $(CFLAGS) -c -o $@ $< -I $(INC)

$(NAME) : $(OBJECTS)
	$(AR) rcs $@ $(OBJECTS)

clean :
	rm -rf $(OBJECTS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
