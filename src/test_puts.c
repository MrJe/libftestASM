/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_puts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 11:50:26 by jmichaud          #+#    #+#             */
/*   Updated: 2019/05/31 19:04:46 by gpoblon          ###   ########.fr       */
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
	ft_ret = ft_puts(s);
	dup2(fd_sys, STDOUT_FILENO);
	sys_ret = puts(s);
	fflush(NULL);
	dup2(save_out, STDOUT_FILENO);

	if (sys_ret != ft_ret && (ft_ret == 0 || sys_ret == 0))
	{
		close(fd_ft);
		close(fd_sys);
		return (fperr("value: %s; _ft: |%d|; sys: |%d|\n", s, ft_ret, sys_ret));
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
	return (test(NULL));
}

static int	test_b(void)
{
	return (test("Pas de retour ligne"));
}

static int	test_c(void)
{
	return (test("ajout d'un retour a la ligne\n"));
}

static int	test_d(void)
{
	return (test(""));
}

int			test_puts(void)
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
