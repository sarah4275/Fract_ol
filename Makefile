NAME	=fractol

SRC	=

GNL	= getNextLine/get_next_line.c getNextLine/get_next_line_utils.c

OBJS	= ${SRC:.c=.o} ${GNL:.c=.o}

CC	= cc
CFLAGS	= -Wall -Wextra -Werror

RM	= rm -f

MLX_DIR	= ./minilibx-linux
MLX_LIB	= ${MLX_DIR}/libmlx.a
MLX_LDFLAGS	= -L${MLX_DIR} -lmlx -lXext -lX11 -lm -lz

PRINTF_DIR	= ./printf
PRINTF_LIB	= ${PRINTF_LIB} -lmlx -lXext -lX11 -lm -lz

GNL_DIR	= ./getNexLine

INCS	= -I ${MLX_DIR} ${PRINTF_DIR} ${GNL_DIR} 
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ ${INCS}

$(NAME): ${MLX_DIR} ${PRINTF_DIR} ${OBJS}
		${CC} ${CFLAGS} ${OBJS} ${MLX_LDFLAGS} ${PRINTF_LIB} -o ${NAME}
${MLX_LIB}
	${MAKE} -C ${MLX_DIR}
${PRINTF_LIB}:
	${MAKE} -C ${PRINTF_DIR}

all	: $(NAME)

clean:
	${RM} ${OBJS}
	${RM} getNextLine/*.o
	${MAKE} -C ${MLX_DIR} clean
	${MAKE} -C ${PRINTF_LIB} clean

fclean:
	${RM} ${NAME}
	${MAKE} -C ${PRINTF_DIR} fclean

re: fclean all

.PHONY: all clean fclean re