/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isalnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 11:50:26 by jmichaud          #+#    #+#             */
/*   Updated: 2019/05/22 18:48:37 by gpoblon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"
#include "libftASM.h"
#include <string.h>

#define CHAR_SET 'x'
#define TAB_SIZE 10

static int	test_x(void)
{
	int	err_count = 0;
	int	i = -1;

	while (i < 256)
	{
		if (ft_isalnum(i) != isalnum(i))
		{
			dprintf(g_fd, "(%s) * value = |%d| * _ft rax: %d; sys rax: %d *\n",
            g_fname, i, ft_isalnum(i), isalnum(i));
			return (EXIT_FAILURE);
		}
		++i;
	}
	return (EXIT_SUCCESS);
}

static int	test_0(void)
{
	return (test_x());
}

int			test_isalnum(void)
{
	int		(*f_tab[])(void) = {
		test_0,
		0
	};

	return (launch_tests(f_tab));
}