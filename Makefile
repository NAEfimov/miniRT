NAME	:= minirt
CFLAGS	:= -Wextra -Wall -Werror -O3
LIBMLX	:= ./lib/MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

SRCS_D	:= ./src
# list source files relative to $(SRCS_D), for example:
# SRCS := main.c utils/vec3.c scenes/scene1.c
SRCS	:= main.c

OBJS_D	:= ./build
# map the SRCS list to object files under OBJS_D (preserves subdirs from SRCS entries)
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
# 	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx