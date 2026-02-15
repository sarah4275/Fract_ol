NAME    = libftprintf.a

SRC     = ft_atoi ft_bzero ft_calloc ft_isalnum ft_isalpha ft_isascii \
          ft_isdigit ft_isprint ft_itoa ft_memchr ft_memcmp ft_memcpy \
          ft_memmove ft_memset ft_putchar_fd ft_putendl_fd ft_putnbr_fd \
          ft_putstr_fd ft_strchr ft_strdup ft_striteri ft_strjoin \
          ft_strlcat ft_strlcpy ft_strlen ft_strmapi ft_strncmp ft_split \
          ft_strnstr ft_strrchr ft_strtrim ft_substr ft_tolower ft_toupper

SRCS    = $(addsuffix .c, $(SRC))
OBJS    = $(SRCS:.c=.o)

CC      = cc
CFLAGS  = -Wall -Wextra -Werror

AR      = ar rcs
RM      = rm -f

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	$(RANLIB) $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
