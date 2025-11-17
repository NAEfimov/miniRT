NAME	:= minirt
CFLAGS	:= -Wextra -Wall -Werror -O3
LIBMLX	:= ./lib/MLX42
LIBFT	:= ./lib/libft

HEADERS	:= -I ./include \
		   -I $(LIBMLX)/include \
		   -I $(LIBFT)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a $(LIBFT)/libft.a -ldl -lglfw -pthread -lm

SRCS_D	:= ./src
SRCS	:= main.c \
		   scene_clean.c \
		   scene_draw.c \
		   scene_read.c \
		   scene_trace.c

OBJS_D	:= ./build
OBJS	:= $(patsubst %.c,$(OBJS_D)/%.o,$(SRCS))

all: libmlx libft $(NAME)

libmlx:
	@echo "Building lbmlx..."
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	@echo "Building libft..."
	$(MAKE) -C $(LIBFT)

$(OBJS_D)/%.o: $(SRCS_D)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@echo "Linking miniRT..."
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)
	@echo "miniRT built successfully!"

clean:
	@rm -rf $(OBJS_D)
	$(MAKE) -C $(LIBFT) clean

fclean: clean mlxclean
	@rm -rf $(NAME)
	$(MAKE) -C $(LIBFT) fclean

mlxclean:
	@rm -rf $(LIBMLX)/build

re: clean all

.PHONY: all, clean, fclean, re, libmlx, mlxclean