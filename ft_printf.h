/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:30:00 by mmarti            #+#    #+#             */
/*   Updated: 2019/10/21 17:30:03 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <float.h>
# define LG2 0.301
# define LG5 0.7

typedef struct		s_flags
{
	int				plus;
	int				minus;
	int				null;
	int				sharp;
	int				space;
}					t_flags;

typedef struct		s_mod
{
	int				h;
	int				l;
	int				hh;
	int				ll;
	int				lb;
}					t_mod;

typedef struct		s_format
{
	char			*prev;
	char			*post;
	char			type;
	t_mod			mod;
	int				length;
	int				precision;
	t_flags			fl;
	struct s_format *next;
}					t_format;

typedef struct		s_pow
{
	char			*num;
	int				size;
	struct s_pow	*next;
}					t_pow;

typedef struct		s_res
{
	char			*num;
	int				entirelen;
	int				sign;
}					t_res;

typedef struct		s_vars
{
	int				ret;
	int				exp;
	int				tmp;
	t_pow			*entire;
	t_pow			*frac;
}					t_vars;

t_format			*fladd(char *vaptr, t_format *list);
int					ft_printf(char *format, ...);
int					dtoi(long double a, t_format *format);
t_pow				*get_entire(char *mantissa, int exp);
void				carry(char *num, int size);
void				tutu(char *num, int size, int pow);
t_pow				*division(char *num, int divider, int size);
t_pow				*get_frac(char *mantissa, int exp);
t_pow				*get_last(t_pow *lst);
int					ft_putnum(t_res res, int precision, t_format *format);
int					entlen(char *num);
char				*ft_numjoin(t_pow *entire, t_pow *frac);
char				*entirestr(t_pow *entire);
char				*fracstr(t_pow *frac);
void				*ft_ncpy(void *destination, const void *source, size_t n);
void				ft_round(char *num, int precision);
void				ft_free_pow(t_pow *lst);
void				ft_free_format(t_format *lst);
void				ft_free_vars(t_vars vars);
int					ft_parse(t_format *list, va_list vaptr);
int					ft_parse_float(va_list vaptr, t_format *list);
t_format			*fladd(char *format, t_format *list);
t_format			*new_format();
t_format			*get_last_format(t_format *list);
char				*get_mod(t_format *list, char *s);
void				handle_fl_spec(t_format *format, char c, int *len);
void				handle_w_spec(t_format *format, int len);
char				*check(char *str);
t_format			*new_format(void);

#endif
