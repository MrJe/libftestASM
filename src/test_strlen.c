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
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

static int	test(char *s)
{
	size_t	ft_ret = 1;
	size_t	sys_ret = strlen(s);
	if (s && ft_ret != sys_ret)
		return(fperr("value: %s; _ft: %lu; sys: %lu\n",
					s, ft_ret, sys_ret));
	return (SUCCESS);
}

static int	test_a(void)
{
	return (test(""));
}

static int	test_b(void)
{
	return (test("c"));
}

static int	test_c(void)
{
	return (test("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nullam quis euismod sapien. Sed id felis arcu. Aenean nunc dolor, volutpat vitae felis non, finibus dictum metus. Duis non mi quis purus varius sodales vitae at sem. Praesent vel ante semper, imperdiet augue sed, mattis tortor. Praesent elementum lacinia purus. Nunc convallis turpis ornare viverra faucibus."));
}

static int	test_d(void)
{
	return (test("ひらがな unicode"));
}

static int	test_e(void)
{
	char	*s;
	int		ret;

	s = malloc(INT_MAX);
	memset(s, 'a', INT_MAX);
	s[INT_MAX - 1] = '\0';
	ret = test(s);
	free(s);
	return (ret);
}

static int	test_f(void)
{
	return (test("\t\n\r\t _isspace_\n"));
}

int			test_strlen(void)
{
	int		(*f_tab[])(void) = {
		test_a,
		test_b,
		test_c,
		test_d,
		test_e,
		test_f,
		0
	};

	return (launch_tests(f_tab));
}
