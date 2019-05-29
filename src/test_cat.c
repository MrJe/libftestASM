/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 11:50:26 by jmichaud          #+#    #+#             */
/*   Updated: 2019/05/29 18:34:21 by gpoblon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"
#include "libftASM.h"
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

static int	test(char const *s)
{
	int		fd_ref;
	int		fd_ft;
	int		save_out;

	fd_ref = open(s, O_RDWR);
	fd_ft = open("test_file_stdout", O_RDWR | O_TRUNC | O_CREAT, 0666);
	if (fd_ref < 0 || fd_ft < 0)
		return (fperr("FD ERROR (fd_ref=%d, fd_ft=%d)\n", fd_ref, fd_ft));
	save_out = dup2(fd_ft, STDOUT_FILENO);
	ft_cat(fd_ref);
	dup2(save_out, STDOUT_FILENO);
	if (cmp_files(fd_ref, fd_ft))
		return (fperr("file to check: |%s|\n", s));
	close(fd_ref);
	close(fd_ft);
	return (SUCCESS);
}

static int	test_a(void)
{
	return (test("libfts.a"));
}

static int	test_b(void)
{
	return (test("Makefile"));
}

static int	test_c(void)
{
	return (test("/dev/null"));
}

static int	test_d(void)
{
	ft_cat(-42);
	return (SUCCESS);
}

int			test_cat(void)
{
	int		(*f_tab[])(void) = {
		test_a,
		test_b,
		test_c,
		test_d,
		0
	};

	return (launch_tests(f_tab));
}
