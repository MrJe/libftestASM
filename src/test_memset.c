/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 11:50:26 by jmichaud          #+#    #+#             */
/*   Updated: 2019/05/29 11:26:50 by gpoblon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"
#include "libftASM.h"
#include <stdlib.h>
#include <stdio.h>

static int	test(void *b, int c, size_t len)
{
	char	*ft_ret;
	char	*sys_ret;

	ft_ret = strndup(b, len);
	sys_ret = memset(b, c, len);
	if ((ft_ret != ft_memset(ft_ret, c, len)) ||
		(memcmp(ft_ret, sys_ret, len) != 0))
	{
		free(ft_ret);
		return(fperr("value: %s; _ft: %s; sys: %s\n",
					b, ft_ret, sys_ret));
	}
	free(ft_ret);
	return (SUCCESS);
}

static int	test_a(void)
{
	return (test("", 'a', 0));
}

static int	test_b(void)
{
	char	str[100] = "Hello World!";

	return (test(str, 'c', 1));
}

static int	test_c(void)
{
	char	str[100] = "Hello World!";

	return (test(str, 'a', 100));
}

static int	test_d(void)
{
	char	str[100] = "\t\n\r\f _isspace_\n";

	return (test(str, '\0', 100));
}

static int	test_e(void)
{
	char	str[100] = "\t\n\r\f _isspace_\n";

	return (test(str, '\0', 5));
}

static int	test_f(void)
{
	char	str[100] = { 0 };

	return (test(str, 0, 42));
}


int			test_memset(void)
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
