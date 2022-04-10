TARGET	=	philo

DEBUG	=	philo_d
CC		=	clang

CFLAGS		=	-Wall -Wextra -Werror
DEBUGFLAG	= -fsanitize=address -g3

SRCS		=	main.c\
				parsing.c\
				error.c\
				libft.c\
				philo.c\
				fork.c\
				action.c\
				util.c

SRCS_DIR	=	./
OBJS		=	$(SRCS:.c=.o)
# MAKEFLAGS	+=	--silent

all		:	$(TARGET)

d		:	$(DEBUG)

$(TARGET)	:	$(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

.c.o	:
	$(CC) $(CFLAGS) -c $< -o $@


$(DEBUG)	:	$(OBJS)
	$(CC) $(CFLAGS) $(DEBUGFLAG) -o $@ $^

fclean	:	clean
	rm -f $(TARGET)

dclean	:	fclean
	rm -f $(DEBUG)

clean	:
	rm -f $(OBJS)

re		:	fclean all

.PHONY	: clean fclean dclean d all re
