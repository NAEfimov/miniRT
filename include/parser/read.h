#ifndef READ_H
# define READ_H

# include "main.h"

int	read_int(int *num, char *word);
int	read_uint8(uint8_t *num, char *word);
int	read_uint32(uint32_t *num, char *word);
int	read_double(double *num, char *word);
int	read_color(t_color *color, char *word);
int	read_normal(t_vec *norm, char *word);
int	read_vec(t_vec *vec, char *word);

int	cheack_commas(char *str);
int	read_sign(char **pp);

#endif