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
		   vector.c \
		   ray.c \
		   scene_clean.c \
		   scene_draw.c \
		   scene_read.c \
		   scene_trace.c \
		   check_args.c \
		   parser/parse_ambient_light.c \
		   parser/parse_camera.c \
		   parser/parse_cylinder.c \
		   parser/parse_light.c \
		   parser/parse_line.c \
		   parser/parse_plane.c \
		   parser/parse_scene_element.c \
		   parser/parse_utils.c \
		   parser/parse_sphere.c \
		   parser/read_color.c \
		   parser/read_double.c \
		   parser/read_int.c \
		   parser/read_uint8.c \
		   parser/read_uint32.c \
		   parser/read_normal.c \
		   parser/read_vec.c \
		   parser/read_utils.c \
		   utils/print/print_scene.c \
		   utils/print/print_ambient_light.c \
		   utils/print/print_camera.c \
		   utils/print/print_light.c \
		   utils/print/print_sphere.c \
		   utils/print/print_plane.c \
		   utils/print/print_cylinder.c \
		   utils/print/print_vec.c \
		   utils/print/print_color.c \
		   utils/print/print_double.c \
		   utils/print/print_uint32.c \
		   utils/copy_struct/copy_color.c \
		   utils/copy_struct/copy_vec.c \
		   utils/copy_struct/copy_amb_light.c \
		   utils/copy_struct/copy_camera.c \
		   utils/copy_struct/copy_light.c \
		   utils/copy_struct/copy_sphere.c \
		   utils/copy_struct/copy_plane.c \
		   utils/copy_struct/copy_cylinder.c \
		   utils/copy_struct/copy_scene.c

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