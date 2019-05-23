/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 11:50:26 by jmichaud          #+#    #+#             */
/*   Updated: 2019/05/23 17:47:51 by gpoblon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"
#include "libftASM.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

static int	test_x(char *s)
{
	size_t	ft_ret = 1;
	size_t	sys_ret = strlen(s);
	if (s && ft_ret != sys_ret)
		return(fperr("value: %s; _ft: %lu; sys: %lu\n", s, ft_ret, sys_ret));
	if (s)
		free(s);
	return (SUCCESS);
}

static int	test_0(void)
{
	return (test_x(strdup("")));
}

static int	test_1(void)
{
	return (test_x(strdup("c")));
}

static int	test_2(void)
{
	return (test_x(strdup("coucou comment vas tu ? longer size")));
}

static int	test_3(void)
{
	return (test_x(strdup("ひらがな unicode")));
}

static int	test_4(void)
{
	char *s = malloc(__INT_MAX__);
	memset(s, 'a', __INT_MAX__);
	s[__INT_MAX__ - 1] = '\0';
	return(test_x(s));
}

int			test_strlen(void)
{
	int		(*f_tab[])(void) = {
		test_0,
		test_1,
		test_2,
		test_3,
		test_4,
		0
	};

	return (launch_tests(f_tab));
}
