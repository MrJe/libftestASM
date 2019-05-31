/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 11:50:26 by jmichaud          #+#    #+#             */
/*   Updated: 2019/05/31 15:15:29 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"
#include "libftASM.h"
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>

static int	test(int c)
{
	int		ft_ret;
	int		sys_ret;
	int		fd_sys;
	int		fd_ft;
	int		save_out;

	fd_sys = open("test_file_sys", O_RDWR | O_TRUNC | O_CREAT, 0666);
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
	ft_ret = ft_putchar(c);
	dup2(fd_sys, STDOUT_FILENO);
	sys_ret = putchar(c);
	fflush(NULL);
	dup2(save_out, STDOUT_FILENO);
	if (sys_ret != ft_ret)
	{
		close(fd_ft);
		close(fd_sys);
		return (fperr("value: %d; _ft: |%d|; sys: |%d|\n", c, ft_ret, sys_ret));
	}
	if (cmp_files(fd_sys, fd_ft))
	{
		close(fd_ft);
		close(fd_sys);
		return (fperr("return value is fine but char not well printed, see test_file_*\n"));
	}
	close(fd_sys);
	close(fd_ft);
	return (SUCCESS);
}

static int	test_a(void)
{
	int		i;
	int		ret;

	ret = SUCCESS;
	i = -2;
	while (++i < 128)
		if (test(i) == FAILURE)
			ret = FAILURE;
	return (ret);
}

static int	test_b(void)
{
	return (test(INT_MAX));
}

static int	test_c(void)
{
	return (test(INT_MIN));
}

static int	test_d(void)
{
	return (test(256));
}

int			test_putchar(void)
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
