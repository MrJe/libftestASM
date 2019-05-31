/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 11:50:26 by jmichaud          #+#    #+#             */
/*   Updated: 2019/05/31 18:32:02 by gpoblon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"
#include "libftASM.h"
#include <string.h>

#define CHAR_SET 'x'
#define TAB_SIZE 101

static int	check_memory(char *mem, int size)
{
	int		i;

	i = -1;
	while (++i < size)
		if (mem[i] != '\0')
			return (FAILURE);
	--i;
	while (++i < TAB_SIZE)
		if (mem[i] != CHAR_SET)
			return (FAILURE);
	return (SUCCESS);
}

static int	test(int size)
{
	char	mem[TAB_SIZE];

	memset(&mem, CHAR_SET, TAB_SIZE);
	ft_bzero(&mem, size);
	return (check_memory(mem, size));
}
static int	test_a(void)
{
	return (test(TAB_SIZE));
}

static int	test_b(void)
{
	return (test(TAB_SIZE - TAB_SIZE));
}

static int	test_c(void)
{
	return (test(TAB_SIZE - (TAB_SIZE / 2)));
}

static int	test_d(void)
{
	return (test(TAB_SIZE - 1));
}

static int	test_e(void)
{
	return (test(1));
}

static int	test_f(void)
{
	return (test(3));
}

int			test_bzero(void)
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
