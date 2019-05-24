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

#define CHAR_SET 'x'
#define TAB_SIZE 10

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

static int	test_x(int size)
{
	char	mem[TAB_SIZE];

	memset(&mem, CHAR_SET, TAB_SIZE);
	ft_bzero(&mem, size);
	return (check_memory(mem, size));
}
static int	test_0(void)
{
	return (test_x(TAB_SIZE));
}

static int	test_1(void)
{
	return (test_x(TAB_SIZE - TAB_SIZE));
}

static int	test_2(void)
{
	return (test_x(TAB_SIZE - (TAB_SIZE / 2)));
}

static int	test_3(void)
{
	return (test_x(TAB_SIZE - 1));
}

int			test_bzero(void)
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
