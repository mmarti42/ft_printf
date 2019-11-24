/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gerenfor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 22:21:22 by gerenfor          #+#    #+#             */
/*   Updated: 2019/11/21 00:05:38 by gerenfor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_LIB_H
# define MY_LIB_H
# include "ft_printf.h"
# include "libft/libft.h"

typedef struct				s_varo
{
	int						len;
	int						base;
	int						ret;
	int						per;
	unsigned long long int	number;
}							t_varo;

int							ft_write_alot(int nom, char c);
int							ft_write_char(void *data, t_format *list);
int							ft_write_s(void *data, t_format *list);
int							ft_int_lon_base(long long int nom, int base);
void						ft_print_lli_base(long long int a,
		int b, int c, int d);
long long int				ft_int_reforge(void *data,
		t_format *list, int *nega);
int							ft_write_i(void *data, t_format *list);
void						ft_sign(int nega, t_format *list);
void						ft_add(int len, int nega, t_format *list);
int							ft_uadd(int l, t_format *li,
		unsigned long long int n);
int							ft_ulli_lon_base(unsigned long long int num,
		int base);
void						ft_ulli(unsigned long long int a,
		int b, int c, int d);
void						ft_hash(t_format *list,
		unsigned long long int number);
unsigned long long int		ft_un_i_reforge(void *data, t_format *list);
int							ft_write_u(void *data, t_format *list);
int							ft_write_per(t_format *list);
int							ft_upper(t_format *list);
int							ft_base(t_format *list);

#endif
