
NAME		= minirt
SRCS		= minirt.c graphics.c graphics_util.c
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

all: $(LIB_DIR)/mlx ${BUILD_DIR} ${NAME}

$(LIB_DIR)/mlx:
	@ echo -e "\x1b[35;1m--[ COMPILEING LIBFT ]--\x1b[0m"
	@ make -C ${LIB_DIR}/libft
ifeq ($(UNAME_S),Linux)
	@ echo -e "\x1b[35;1m--[ INSTALLING MLX ]--\x1b[0m"
	@ echo "Cloning MLX from official git repo..."
	@ git clone $(MLX_REPO) $(LIB_DIR)/mlx
	@ echo "Building MLX..."
	@ make -C ${LIB_DIR}/mlx
	@ echo -e "\x1b[32;1m-------[ DONE ]-------\x1b[0m"
	@ echo -e "\x1b[35;1m--[ TESTINGING MLX ]--\x1b[0m"
	@ echo -e "\x1b[33;1mInfo: If at any point the Makefile throws an error, you might have a missing dependency to install, or your system environment is poorly configured, thus making any evaluation in sed environment un-fitting. To close the window, if it doesn't exit properly, press escape.\x1b[0m"
	@ ${LIB_DIR}/mlx/test/run_tests.sh 1> $(LIB_DIR)/mlx/test/output.log
	@ echo -e "\x1b[32;1m-------[ DONE ]-------\x1b[0m"
else
	@ $(error "Unsupported OS detected. (${UNAME_S})")
endif

libft-re:
	@ echo -e "\x1b[35;1m--[ REBUILDING LIBFT ]--\x1b[0m"
	make re -C $(LIB_DIR)/libft

mlx-re:
	@ echo -e "\x1b[35;1m--[ REBUILDING MLX ]--\x1b[0m"
	make re -C $(LIB_DIR)/mlx

${BUILD_DIR}:
	mkdir -p ${BUILD_DIR}

${BUILD_DIR}/%.o:${SRC_DIR}/%.c
	$(CC) ${INCLUDE_OBJ} -c -o $@ $^ $(CFLAGS)

${NAME}:	${OBJ}
	$(CC) ${OBJ} ${INCLUDE_SRC} -o ${NAME} $(CFLAGS)

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	rm -f ${NAME}

re: fclean all

