#ifndef VECTOR_H
# define VECTOR_H

# include "main.h"

t_vec	vec_add(t_vec a, t_vec b);
t_vec	vec_assign(double x, double y, double z);
void	vec_copy(t_vec *dist, const t_vec *source);
t_vec	vec_scl(t_vec a, double s);
t_vec	vec_mul(t_vec a, t_vec b);
t_vec	vec_nrm(t_vec v);
t_vec	vec_crs(t_vec a, t_vec b);
t_vec	vec_sub(t_vec a, t_vec b);
double	vec_dot(t_vec a, t_vec b);
double	vec_sq_len(t_vec v);
double	vec_len(t_vec v);

#endif