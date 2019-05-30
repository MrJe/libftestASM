/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 12:57:45 by jmichaud          #+#    #+#             */
/*   Updated: 2019/05/30 18:02:08 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_TEST_H
# define LIBUNIT_TEST_H

#include <stdio.h>
#include <stdarg.h>

# define SUCCESS	0
# define FAILURE	1
# define ERROR		-1
# define TEST		"--test"
# define BUFF_SIZE	1024

extern char const	*g_fname;
extern FILE			*g_fstream;

typedef struct		s_unit_test
{
	char const		*name;
	int				(*unit_test)(void);
}					t_unit_test;

/*
** print.c
*/
int					fperr(const char *str, ...);
void				print_usage(void);
void				print_header(void);
void				print_results(int ok, int total);
void				print_name(char const *name);
void				print_error(char const *name);
void				print_letter(char c, int ret);
void				print_signal(char const *signal);
void				print_nb_ok(int i, int ko);

/*
** catch_signal.c
*/
char const			*catch_signal(int signal);

int					testception_ok(void);
int					testception_ko(void);
int					testception_signal(void);
int					launch_tests(int (*unit_test[])(void));

/*
** utils.c
*/
int					cmp_files(int fd1, int fd2);
int					cmp_file_str(int fd, char const *s);

#endif
