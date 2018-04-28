NAME = fillit

SRCS += check_piece.c
SRCS += errors.c
SRCS += grid.c
SRCS += grid_print.c
SRCS += main.c
SRCS += piece.c
SRCS += reader.c
SRCS += resolver.c

LIB_FILES += ft_putchar.c
LIB_FILES += ft_putendl.c
LIB_FILES += ft_memset.c
LIB_FILES += ft_memcpy.c
LIB_FILES += ft_strlen.c

LIB_SRCS += $(addprefix libft/,$(LIB_FILES))

OBJS =  $(SRCS:.c=.o)
OBJS += $(LIB_SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(OBJS)
	gcc -o $(NAME) $(OBJS)

# $^ is the dependencies of the rule
# $@ is the name of the rule
%.o : %.c
	gcc $(FLAGS) -I libft -c $^ -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
