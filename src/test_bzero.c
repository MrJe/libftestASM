/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 11:50:26 by jmichaud          #+#    #+#             */
/*   Updated: 2019/05/22 13:18:27 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

static int	test_0(void)
{
	return (SUCCESS);
}

static int	test_1(void)
{
	return (SUCCESS);
}

static int	test_2(void)
{
	return (SUCCESS);
}

static int	test_3(void)
{
	return (SUCCESS);
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
