
NAME		= miniRT
SRCS		= minirt.c fixed_point.c graphics.c graphics_util.c vec3_01.c
LIBS		= mlx libft

SRC_DIR		= ./src
LIB_DIR		= ./lib
BUILD_DIR	= ./build

MLX_REPO	= https://github.com/42Paris/minilibx-linux.git

CC			= gcc
CFLAGS		= -g -Wall -Werror -Wextra
INCLUDE_OBJ	= ${addprefix -I,${LIBS_DIR}} \
			  -I/usr/include
INCLUDE_SRC	= ${addprefix -L,${LIBS_DIR}} \
			  -L/usr/lib -lXext -lX11 -lm -lz \
			  -l:libft.a \
			  -lmlx

SRC			= ${addprefix ${BUILD_DIR}/,${SRCS}}
LIBS_DIR	= ${addprefix ${LIB_DIR}/,${LIBS}}
OBJ			= ${SRC:.c=.o}
UNAME_S		= $(shell uname -s)

all: ${NAME}

${NAME}: $(LIB_DIR)/mlx ${BUILD_DIR} ${OBJ}
	@ echo -e "\x1b[35;1m--[ COMPILING MINIRT ]--\x1b[0m"
	$(CC) ${OBJ} ${INCLUDE_SRC} -o ${NAME} $(CFLAGS)

$(LIB_DIR)/mlx:
ifeq ($(UNAME_S),Linux)
	@ echo -e "\x1b[35;1m--[ INSTALLING MLX ]--\x1b[0m"
	@ echo "Cloning MLX from official git repo..."
	@ git clone $(MLX_REPO) $(LIB_DIR)/mlx
	@ echo -e "\x1b[32;1m-------[ DONE ]-------\x1b[0m"
else
	@ $(error "Unsupported OS detected. (${UNAME_S})")
endif

mlx:
	@ echo -e "\x1b[35;1m--[ COMPILING MLX ]--\x1b[0m"
	@ make -C ${LIB_DIR}/mlx

mlx-clean:
	@ echo -e "\x1b[35;1m--[ CLEANING MLX ]--\x1b[0m"
	make clean -C $(LIB_DIR)/mlx

mlx-remove:
	@ rm -rf $(BUILD_DIR)
	@ echo -e "\x1b[35;1m--[ REMOVING MLX ]--\x1b[0m"
	rm -rf $(LIB_DIR)/mlx

libft:
	@ echo -e "\x1b[35;1m--[ COMPILEING LIBFT ]--\x1b[0m"
	@ make -C ${LIB_DIR}/libft

libft-clean:
	@ echo -e "\x1b[35;1m--[ CLEANING LIBFT ]--\x1b[0m"
	make clean -C $(LIB_DIR)/libft

${BUILD_DIR}:
	@ make mlx libft
	mkdir -p ${BUILD_DIR}

${BUILD_DIR}/%.o:${SRC_DIR}/%.c
	$(CC) ${INCLUDE_OBJ} -c -o $@ $^ $(CFLAGS)

clean: libft-clean mlx-clean
	@ echo -e "\x1b[35;1m--[ CLEANING MINIRT ]--\x1b[0m"
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re mlx mlx-clean libft libft-clean

