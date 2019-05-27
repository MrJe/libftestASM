/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 11:50:26 by jmichaud          #+#    #+#             */
/*   Updated: 2019/05/22 16:51:16 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"
#include "libftASM.h"
#include <string.h>
#include <stdio.h>

static int	test(char const *s)
{
	int		ft_ret;
	int		sys_ret;

	printf("\n%s: ", g_fname);
	fflush(stdout);
	ft_ret = ft_puts(s);
	printf("puts      : ");
	fflush(stdout);
	sys_ret = puts(s);
	if (ft_ret != sys_ret)
		return (fperr("value: %s; _ft: |%d|; sys: |%d|\n",
						s, ft_ret, sys_ret));
	return (SUCCESS);
}
static int	test_0(void)
{
	return (test(NULL));
}

static int	test_1(void)
{
	return (test("a b c d e f g h i j k l m n o p q r s t u v w x y z"));
}

int			test_puts(void)
{
	int		(*f_tab[])(void) = {
		test_0,
		test_1,
		0
	};

	return (launch_tests(f_tab));
}
