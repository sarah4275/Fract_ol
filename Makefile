NAME	= fractol

SRC	= ./src/main.c ./src/controle.c ./src/complexe.c ./src/fractol.c 

OBJS	= ${SRC:.c=.o} 

CC	= cc
CFLAGS	= -Wall -Wextra -Werror

RM	= rm -f

MLX_DIR	= ./includes/minilibx-linux
MLX_LIB	= ${MLX_DIR}/libmlx.a
MLX_LDFLAGS = -L${MLX_DIR} -lmlx -lXext -lX11 -lm -lz

PRINTF_DIR	= ./includes/printf
PRINTF_LIB	= ${PRINTF_DIR}/libftprintf.a

INCS	= -I ${MLX_DIR} -I ${PRINTF_DIR} 
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): ${MLX_DIR} ${PRINTF_DIR} ${OBJS}
		${CC} ${CFLAGS} ${OBJS} ${MLX_LDFLAGS} ${PRINTF_LIB} -o ${NAME}
${MLX_LIB}:
	make -C ${MLX_DIR}

${PRINTF_LIB}:
	make -C ${PRINTF_DIR} 

all	: $(NAME)

clean:
	${RM} ${OBJS}
	${RM} getNextLine/*.o
	make -C ${MLX_DIR} clean
	make -C ${PRINTF_DIR} clean

fclean:
	${RM} ${NAME}
	make -C ${PRINTF_DIR} fclean

re: fclean all

.PHONY: all clean fclean re
