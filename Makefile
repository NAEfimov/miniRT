NAME	:= minirt
CFLAGS	:= -Wextra -Wall -Werror -O3
LIBMLX	:= ./lib/MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

SRCS_D	:= ./src
SRCS	:= main.c			\
		   scene_clean.c	\
		   scene_draw.c 	\
		   scene_read.c		\
		   scene_trace.c

OBJS_D	:= ./build
OBJS	:= $(patsubst %.c,$(OBJS_D)/%.o,$(SRCS))

all: $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(OBJS_D)/%.o: $(SRCS_D)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS_D)

fclean: clean
	@rm -rf $(NAME)

mlxclean:
	@rm -rf $(LIBMLX)/build

re: clean all

.PHONY: all, clean, fclean, re, libmlx, mlxclean