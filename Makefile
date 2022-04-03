TARGET	=	philo

DEBUG	=	philo_d
CC		=	clang

INC_DIR		=	./includes
LIB_NAME	=	Libft
LIB_DIR		=	./includes/Libft

AR			= 	ar rc
CFLAGS		=	-Wall -Wextra -Werror
DEBUGFLAG	= -fsanitize=address -g3
LDFLAGS		=	-lc

SRCS		=	./src/main.c\
				./src/parsing.c\
				./src/error.c\
				./src/create.c\
				./src/philo.c\
				./src/fork.c\
				./src/action.c\
				./src/util.c
SRCS_DIR	=	./src
OBJS		=	$(SRCS:.c=.o)
ARFS		=	$(LIB_DIR)/Libft.a
MAKEFLAGS	+=	--silent

all		:	$(TARGET)

d		:	$(DEBUG)

$(TARGET)	:	$(OBJS)
	make -C $(LIB_DIR)
	$(CC) $(CFLAGS) $(LDFLAGS) $(ARFS) -o $@ $^

.c.o	:
	$(CC) $(CFLAGS) -I $(LIB_DIR) -I $(INC_DIR) -c $< -o $@


$(DEBUG)	:	$(OBJS)
	make -C $(LIB_DIR)
	$(CC) $(CFLAGS) $(LDFLAGS) $(ARFS) $(DEBUGFLAG) -o $@ $^

fclean	:	clean
	rm -f $(TARGET)
	rm -f *.a
	make -C $(LIB_DIR) fclean

dclean	:	fclean
	rm -f $(DEBUG)

clean	:
	rm -f $(OBJS)
	make -C $(LIB_DIR) clean

re		:	fclean all


.PHONY	: clean fclean dclean d all re Libft philo
