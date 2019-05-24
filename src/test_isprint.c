/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 11:50:26 by jmichaud          #+#    #+#             */
/*   Updated: 2019/05/23 14:50:23 by gpoblon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"
#include "libftASM.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <limits.h>

static int	test(int n)
{
	int		sys_ret;
	int		ft_ret;

	ft_ret = ft_isprint(n);
	sys_ret = isprint(n);
	if (ft_ret != sys_ret)
		return (fperr("value = |%d|; _ft: |%d|; sys: |%d|\n",
						n, ft_ret, sys_ret));
	return (SUCCESS);
}

static int	test_a(void)
{
	int		i;
	int		ret;

	ret = SUCCESS;
	i = -11;
	while (++i < 257)
	{
			if(test(i) == FAILURE)
				ret = FAILURE;
	}
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

int			test_isprint(void)
{
	int		(*f_tab[])(void) = {
		test_a,
		test_b,
		test_c,
		0
	};

	return (launch_tests(f_tab));
}
