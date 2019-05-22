/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:26:54 by jmichaud          #+#    #+#             */
/*   Updated: 2019/05/22 14:33:40 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"
#include "function_to_test.h"
#include <string.h>

static void		launch_unit_test(t_unit_test const f_tab[])
{
	int					i;
	int					ok;

	print_header();
	ok = 0;
	i = 0;
	while (f_tab[i].name)
	{
		print_name(f_tab[i].name);
		ok += f_tab[i].unit_test();
		++i;
	}
	print_results(ok, i);
}

static void		launch_real_test(void)
{
	t_unit_test const	f_tab[] = {
		{"ft_bzero  ", &test_bzero},
		{"ft_strcat ", &test_bzero},
		{"ft_isalpha", &test_bzero},
		{"ft_isdigit", &test_bzero},
		{"ft_isalnum", &test_bzero},
		{"ft_isascii", &test_bzero},
		{"ft_isprint", &test_bzero},
		{"ft_toupper", &test_bzero},
		{"ft_tolower", &test_bzero},
		{"ft_puts   ", &test_bzero},
		{"ft_strlen ", &test_bzero},
		{"ft_memset ", &test_bzero},
		{"ft_memcpy ", &test_bzero},
		{"ft_strdup ", &test_bzero},
		{"ft_cat    ", &test_bzero},
		{0, 0}
	};

	launch_unit_test(f_tab);
}

static void		launch_testception(void)
{
	t_unit_test const	f_tab[] = {
		{"ft_ok ", &testception_ok},
		{"ft_ko ", &testception_ko},
		{"ft_sig", &testception_signal},
		{0, 0}
	};

	launch_unit_test(f_tab);
}

int				main(int argc, char const *argv[])
{
	if (argc < 2)
		launch_real_test();
	else if (strcmp(argv[1], TEST) == 0)
		launch_testception();
	else
		print_usage();
	return (0);
}
