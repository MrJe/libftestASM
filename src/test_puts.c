/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_puts.c                                        :+:      :+:    :+:   */
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

static int	test(char const *s)
{
	int		ft_ret;
	int		sys_ret;

	int	save_out = dup(STDOUT_FILENO);
	close(STDOUT_FILENO);
	printf("\n%s: ", g_fname);
	fflush(stdout);
	ft_ret = ft_puts(s);
	printf("puts      : ");
	fflush(stdout);
	sys_ret = puts(s);
	dup2(save_out, STDOUT_FILENO);
	if (sys_ret != ft_ret && (ft_ret == 0 || sys_ret == 0))
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
	return (test("Pas de retour ligne"));
}

static int	test_2(void)
{
	return (test("ajout d'un retour a la ligne\n"));
}

int			test_puts(void)
{
	int		(*f_tab[])(void) = {
		test_0,
		test_1,
		test_2,
		0
	};

	return (launch_tests(f_tab));
}
