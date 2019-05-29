/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 11:50:26 by jmichaud          #+#    #+#             */
/*   Updated: 2019/05/29 18:31:57 by gpoblon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"
#include "libftASM.h"
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

static int	test(int c)
{
	int		ft_ret;
	int		sys_ret;
	int		fd_ref;
	int		fd_ft;
	int		save_out;

	fd_ref = open("test_file_sys", O_RDWR | O_TRUNC | O_CREAT, 0666);
	fd_ft = open("test_file_stdout", O_RDWR | O_TRUNC | O_CREAT, 0666);
	if (fd_ref < 0 || fd_ft < 0)
		return (fperr("FD ERROR (fd_ref=%d, fd_ft=%d)\n", fd_ref, fd_ft));

	save_out = dup2(fd_ft, STDOUT_FILENO);
	ft_ret = ft_putchar(c);
	dup2(save_out, STDOUT_FILENO);
	save_out = dup2(fd_ref, STDOUT_FILENO);
	sys_ret = putchar(c);
	fflush(NULL);
	dup2(save_out, STDOUT_FILENO);

	if (sys_ret != ft_ret)
		return (fperr("value: %d; _ft: |%d|; sys: |%d|\n", c, ft_ret, sys_ret));
	if (cmp_files(fd_ref, fd_ft))
		return (fperr("return value is fine but char not well printed, see test_file_*\n"));
	close(fd_ref);
	close(fd_ft);
	return (SUCCESS);
}

static int	test_a(void)
{
	int		i;
	int		ret;

	ret = SUCCESS;
	i = 31;
	while (++i < 127)
		if (test(i) == FAILURE)
			ret = FAILURE;
	return (ret);
}
/*
static int	test_b(void)
{
	return (test(INT_MAX));
}

static int	test_c(void)
{
	return (test(INT_MIN));
}
*/
int			test_putchar(void)
{
	int		(*f_tab[])(void) = {
		test_a,
//		test_b,
//		test_c,
		0
	};

	return (launch_tests(f_tab));
}
