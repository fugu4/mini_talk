/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnogi <hnogi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:50:09 by hnogi             #+#    #+#             */
/*   Updated: 2025/10/05 14:29:28 by hnogi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

/* ===============================
** ft_printf
** =============================== */

int		ft_printf(const char *format, ...);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		print_pointer(unsigned long long ptr);
int		print_decimal(int n);
int		print_unsigned(unsigned int n);
int		print_hex(unsigned int num, const char format);
int		print_percent(void);

/* ===============================
** util functions
** =============================== */

int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
char	*itoa_base(long long n, int base);
char	*utoa_base(unsigned long long n, int base);

#endif
