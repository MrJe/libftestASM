/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 11:50:26 by jmichaud          #+#    #+#             */
/*   Updated: 2019/05/27 15:54:43 by gpoblon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"
#include "libftASM.h"
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

static int	test(int s)
{
	int		ft_ret;
	int		sys_ret;

	int	save_out = dup(STDOUT_FILENO);
	close(STDOUT_FILENO);
	ft_ret = ft_putchar(s);
	sys_ret = putchar(s);
	dup2(save_out, STDOUT_FILENO);
	if (sys_ret != ft_ret)
		return (fperr("value: %d; _ft: |%d|; sys: |%d|\n",
						s, ft_ret, sys_ret));
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
