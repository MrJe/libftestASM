/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putchar_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 13:00:53 by jmichaud          #+#    #+#             */
/*   Updated: 2019/05/31 13:11:12 by jmichaud         ###   ########.fr       */
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

	fd_ft = open("test_file_stdout", O_RDWR | O_TRUNC | O_CREAT, 0666);
	if (fd_ft < 0)
		return (fperr("FD ERROR (fd_ft=%d)\n", fd_ft));

	ft_ret = ft_putchar_fd(c, fd_ft);

	lseek(fd_ft, 0, SEEK_SET);
	unsigned char		f1_buff[BUFF_SIZE + 1] = { 0 };
	int					f1_ret = read(fd_ft, f1_buff, BUFF_SIZE);
	if (f1_ret >= 0 && f1_buff[0] != (unsigned char)c)
	{
		close(fd_ft);
		return (fperr("%c not well printed, see test_file_*\n", c));
	}
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

int			test_putchar_fd(void)
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
