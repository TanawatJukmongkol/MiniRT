
NAME		= miniRT
SRCS		= minirt.c \
			fixed_point.c \
			graphics.c \
			graphics_util.c \
			vec3_01.c \
			ft_destroy_display.c \
			ft_loop_end.c \
			hittable.c \
			lighting.c \
			event_hooks.c \
			o_check_file.c \
			o_check_element.c \
			o_check_inelement.c \
			o_check_other.c \
			o_count.c \
			o_count2.c \
			o_other.c \
			o_pass.c

LIBS		= mlx libft gnl

SRC_DIR		= ./src
LIB_DIR		= ./lib
BUILD_DIR	= ./build

MLX_REPO	= https://github.com/42Paris/minilibx-linux.git

CC			= gcc
CFLAGS		= -g -Wall -Werror -Wextra -Ofast

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
INCLUDE_OBJ	= ${addprefix -I,${LIBS_DIR}} \
			-I/usr/include
INCLUDE_SRC	= ${addprefix -L,${LIBS_DIR}} \
			-L/usr/lib -lXext -lX11 -lm -lz \
			-lmlx -lft -l:get_next_line.a
else ifeq ($(UNAME_S),Darwin)
	@ echo -e "\x1b[35;1m--[ INSTALLING MLX ]--\x1b[0m"
	@ echo "Downloading MLX from official CDN..."
	@ curl https://cdn.intra.42.fr/document/document/22377/minilibx_opengl.tgz -o $(LIB_DIR)/mlx.zip
	@ echo "Extracting MLX..."
	@ mkdir -p $(LIB_DIR)/mlx
	@ tar -xzvf $(LIB_DIR)/mlx.zip -C $(LIB_DIR)/mlx --strip-components 1
	@ echo "Removing MLX zip file..."
	@ rm $(LIB_DIR)/mlx.zip
	@ echo -e "\x1b[32;1m-------[ DONE ]-------\x1b[0m"
INCLUDE_OBJ	= ${addprefix -I,${LIBS_DIR}} \
			-I/usr/include
INCLUDE_SRC	= ${addprefix -L,${LIBS_DIR}} \
			-framework OpenGL -framework AppKit \
			-lmlx -lft ${LIB_DIR}/gnl/get_next_line.a
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
	@- rm -rf $(LIB_DIR)/mlx

libft:
	@ echo -e "\x1b[35;1m--[ COMPILEING LIBFT ]--\x1b[0m"
	@ make -C ${LIB_DIR}/libft

libft-clean:
	@ echo -e "\x1b[35;1m--[ CLEANING LIBFT ]--\x1b[0m"
	make clean -C $(LIB_DIR)/libft

libft-fclean:
	@ echo -e "\x1b[35;1m--[ FCLEANING LIBFT ]--\x1b[0m"
	@- make fclean -C $(LIB_DIR)/libft

gnl:
	@ echo -e "\x1b[35;1m--[ COMPILEING GNL ]--\x1b[0m"
	@ make -C ${LIB_DIR}/gnl

gnl-clean:
	@ echo -e "\x1b[35;1m--[ CLEANING GNL ]--\x1b[0m"
	make clean -C $(LIB_DIR)/gnl

gnl-fclean:
	@ echo -e "\x1b[35;1m--[ FCLEANING GNL ]--\x1b[0m"
	@- make fclean -C $(LIB_DIR)/gnl

${BUILD_DIR}:
	@ make mlx libft gnl
	mkdir -p ${BUILD_DIR}

${BUILD_DIR}/%.o:${SRC_DIR}/%.c
	$(CC) ${INCLUDE_OBJ} -c -o $@ $^ $(CFLAGS)

clean: libft-clean mlx-clean gnl-clean
	@ echo -e "\x1b[35;1m--[ CLEANING MINIRT ]--\x1b[0m"
	rm -rf $(BUILD_DIR)

fclean: libft-fclean mlx-remove gnl-fclean
	rm -rf $(BUILD_DIR)
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re mlx mlx-clean libft libft-clean

