/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftASM.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 12:29:19 by jmichaud          #+#    #+#             */
/*   Updated: 2019/05/29 15:34:27 by gpoblon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTASM_H
# define LIBFTASM_H

#include <strings.h>

/*
** Part 1
*/
void		ft_bzero(void *s, size_t n);
char		*ft_strcat(char *s1, const char *s2);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
int			ft_puts(const char *s);

/*
** Part 2
*/
size_t		ft_strlen(const char *s);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t n);
char		*ft_strdup(const char *s);

/*
** Part 3
*/
void		ft_cat(int fd);

/*
** Bonus part
*/
int			ft_isupper(int c);
int			ft_islower(int c);
int			ft_isspace(int c);
int			ft_putchar(int c);
int			ft_abs(int i);

#endif
