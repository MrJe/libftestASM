/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testception.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 12:35:42 by jmichaud          #+#    #+#             */
/*   Updated: 2019/05/22 13:03:45 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"
#include <string.h>
#include <stdlib.h>

static int		success_test(void)
{
	return (SUCCESS);
}

static int		fail_test(void)
{
	return (FAILURE);
}

static int		segv_test(void)
{
	strlen(NULL);
	return (FAILURE);
}

static int		buse_test(void)
{
	strcpy("Hello World!", "BUS ERROR");
	return (FAILURE);
}

static int		time_test(void)
{
	while (1) ;
	return (FAILURE);
}

int				testception_ok(void)
{
	int		(*f_tab[])(void) = {
		success_test, success_test, success_test, success_test,
		success_test, success_test, success_test, success_test,
		success_test, success_test, success_test, success_test,
		success_test, success_test, success_test, success_test,
		success_test, success_test, success_test, success_test,
		success_test, success_test, success_test, success_test,
		success_test, success_test, 0
	};

	return (launch_tests(f_tab));
}

int				testception_ko(void)
{
	int		(*f_tab[])(void) = {
		success_test, fail_test, success_test, fail_test,
		fail_test, success_test, fail_test, success_test,
		success_test, fail_test, success_test, fail_test,
		0
	};

	return (launch_tests(f_tab));
}

int				testception_signal(void)
{
	int		(*f_tab[])(void) = {
		fail_test, segv_test, buse_test, success_test,
		success_test, time_test, fail_test,
		0
	};

	return (launch_tests(f_tab));
}
