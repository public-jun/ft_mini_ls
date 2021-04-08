NAME = ft_mini_ls

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

OBJS = ft_free_list.o\
	   ft_count_init.o\
	   ft_list_sort.o\
	   ft_mini_ls.o\
	   ft_mini_ls_utils.o\
	   ft_main.o\

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $^

.c.o:
	$(CC) $(CFLAGS) -c $<
		
all: $(NAME)

clean:
	$(RM) $(OBJS) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
