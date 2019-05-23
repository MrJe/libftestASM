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

static int	test_x(void)
{
	int	i = -1;
	int sys_ret;
	int	ft_ret;

	while (i < 256)
	{
		ft_ret = ft_isprint(i);
		sys_ret = isprint(i);
		if (ft_ret != sys_ret)
			return (fperr("value = |%d|; _ft: |%d|; sys: |%d|\n",
				i, ft_ret, sys_ret));
		++i;
	}
	return (SUCCESS);
}

static int	test_0(void)
{
	return (test_x());
}

int			test_isprint(void)
{
	int		(*f_tab[])(void) = {
		test_0,
		0
	};

	return (launch_tests(f_tab));
}