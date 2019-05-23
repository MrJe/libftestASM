/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 11:50:26 by jmichaud          #+#    #+#             */
/*   Updated: 2019/05/23 14:45:42 by gpoblon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"
#include "libftASM.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

static int	test_x(const char *str)
{
	char	*s;

	s = strdup(str);
	if (s && ft_strlen(s) != strlen(s))
		return(fperr("value: %s; _ft: %lu; sys: %lu\n", s, ft_strlen(s), strlen(s)));
	if (s)
		free(s);
	return (SUCCESS);
}

static int	test_0(void)
{
	return (test_x(""));
}

static int	test_1(void)
{
	return (test_x("c"));
}

static int	test_2(void)
{
	return (test_x("coucou comment vas tu ? longer size"));
}

static int	test_3(void)
{
	return (test_x("ひらがな unicode"));
}

int			test_strlen(void)
{
	int		(*f_tab[])(void) = {
		test_0,
		test_1,
		test_2,
		test_3,
		0
	};

	return (launch_tests(f_tab));
}
