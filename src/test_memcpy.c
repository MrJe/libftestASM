/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcpy.c                                      :+:      :+:    :+:   */
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

static int	test(void *src,  size_t n)
{
	char	*ft_ret;

	ft_ret = malloc(n + 1);
	bzero(ft_ret, n + 1);
	if ((ft_ret != ft_memcpy(ft_ret, src, n)) ||
		(memcmp(ft_ret, src, n) != 0))
	{
		free(ft_ret);
		return(fperr("value: %s; _ft: %s\n",
					src, ft_ret));
	}
	free(ft_ret);
	return (SUCCESS);
}

static int	test_a(void)
{
	return (test("", 0));
}

static int	test_b(void)
{
	char	str[100] = "Hello World!";

	return (test(str, 100));
}

static int	test_c(void)
{
	char	str[100] = "\t\n\r\f _isspace_\n";

	return (test(str, 100));
}

static int	test_d(void)
{
	char	str[100] = "\t\n\r\f _isspace_\n";

	return (test(str, 5));
}

static int	test_e(void)
{
	char	str[100] = { 'A' };

	return (test(str, 42));
}

int			test_memcpy(void)
{
	int		(*f_tab[])(void) = {
		test_a,
		test_b,
		test_c,
		test_d,
		test_e,
		0
	};

	return (launch_tests(f_tab));
}
