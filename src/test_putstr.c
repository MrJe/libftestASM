/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 17:58:26 by jmichaud          #+#    #+#             */
/*   Updated: 2019/05/30 18:21:57 by jmichaud         ###   ########.fr       */
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
	int		fd_ft;
	int		save_out;

	fd_ft = open("test_file_stdout", O_RDWR | O_TRUNC | O_CREAT, 0666);
	if (fd_ft < 0)
		return (fperr("FD ERROR (fd_ft=%d)\n", fd_ft));

	save_out = dup(STDOUT_FILENO);
	dup2(fd_ft, STDOUT_FILENO);
	ft_ret = ft_putstr(s);
	dup2(save_out, STDOUT_FILENO);

	if (ft_ret == 0)
		return (fperr("value: %s; _ft: |%d|\n", s, ft_ret));
	if (cmp_file_str(fd_ft, s))
		return (fperr("return value is fine but char not well printed, see test_file_*\n"));
	close(fd_ft);
	return (SUCCESS);
}

static int	test_a(void)
{
	return (test("Hello World"));
}

static int	test_b(void)
{
	return (test("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nullam quis euismod sapien. Sed id felis arcu. Aenean nunc dolor, volutpat vitae felis non, finibus dictum metus. Duis non mi quis purus varius sodales vitae at sem. Praesent vel ante semper, imperdiet augue sed, mattis tortor. Praesent elementum lacinia purus. Nunc convallis turpis ornare viverra faucibus."));
}

static int	test_c(void)
{
	return (test("ajout d'un retour a la ligne\n"));
}

static int	test_d(void)
{
	return (test("\t\n\r\t _isspace_\n"));
}

int			test_putstr(void)
{
	int		(*f_tab[])(void) = {
		test_a,
		test_b,
		test_c,
		test_d,
		0
	};

	return (launch_tests(f_tab));
}
