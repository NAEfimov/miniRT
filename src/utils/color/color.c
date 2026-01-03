#include "main.h"
#include "math.h"

/**
 * Clamps a double value between 0.0 and 1.0.
 *
 * @param value The value to clamp
 *
 * @return The clamped value
 */
static double clamp(double value)
{
    if (value < 0.0) return 0.0;
    if (value > 1.0) return 1.0;
    return value;
}

/**
 * Converts RGB color values (0.0-1.0) to MLX42 uint32_t RGBA format.
 *
 * @param color Pointer to vector containing RGB values (x=r, y=g, z=b)
 *
 * @return MLX42 color in uint32_t format
 */
uint32_t to_mlx_color(t_vec *color)
{
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;

    r = (uint8_t)round(clamp(color->x) * 255.0);
    g = (uint8_t)round(clamp(color->y) * 255.0);
    b = (uint8_t)round(clamp(color->z) * 255.0);
    a = 255;

    // Pack bytes: R G B A
    return ((r << 24) | (g << 16) | (b << 8) | a);
}

/**
 * Converts RGB color values (0.0-1.0) to t_rgb_color structure.
 *
 * @param color Pointer to vector containing RGB values (x=r, y=g, z=b)
 *
 * @return RGB color structure with uint8_t components
 */
t_rgb_color to_rgb_color(t_vec *color)
{
    t_rgb_color rgb_color;

    rgb_color.r = (uint8_t)round(clamp(color->x) * 255.0);
    rgb_color.g = (uint8_t)round(clamp(color->y) * 255.0);
    rgb_color.b = (uint8_t)round(clamp(color->z) * 255.0);
    return (rgb_color);
}
