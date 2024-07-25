/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:04:55 by sforster          #+#    #+#             */
/*   Updated: 2023/11/27 09:04:55 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *f, ...);
int		ft_print_c(int c);
int		ft_print_s(char *str);
int		ft_print_d(long n, int base);
int		ft_print_x(unsigned int n, int base);
int		ft_print_xup(unsigned int n, int base);
int		ft_print_i(long i, int base);
int		ft_print_u(unsigned int n, int base);
int		ft_print_p(void *a);

#endif