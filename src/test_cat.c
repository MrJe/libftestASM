/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 11:50:26 by jmichaud          #+#    #+#             */
/*   Updated: 2019/05/31 12:22:11 by jmichaud         ###   ########.fr       */
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
	int		fd_sys;
	int		fd_ft;
	int		save_out;

	fd_sys = open(s, O_RDWR);
	if (fd_sys < 0)
		return (fperr("FD ERROR (fd_sys=%d)\n", fd_sys));
	fd_ft = open("test_file_stdout", O_RDWR | O_TRUNC | O_CREAT, 0666);
	if (fd_ft < 0)
	{
		close(fd_sys);
		return (fperr("FD ERROR (fd_sys=%d, fd_ft=%d)\n", fd_sys, fd_ft));
	}

	save_out = dup(STDOUT_FILENO);
	dup2(fd_ft, STDOUT_FILENO);
	ft_cat(fd_sys);
	dup2(save_out, STDOUT_FILENO);
	if (cmp_files(fd_sys, fd_ft))
	{
		close(fd_ft);
		close(fd_sys);
		return (fperr("file to check: |%s|\n", s));
	}
	close(fd_sys);
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
