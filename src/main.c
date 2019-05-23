/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:26:54 by jmichaud          #+#    #+#             */
/*   Updated: 2019/05/23 17:05:14 by gpoblon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"
#include "function_to_test.h"
#include <string.h>
#include <fcntl.h>

char const		*g_fname;
FILE			*g_fstream;

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
		g_fname = f_tab[i].name;
		ok += f_tab[i].unit_test();
		++i;
	}
	print_results(ok, i);
}

static int		set_debug_file(void)
{
	if((g_fstream = fopen("trace", "w")) == NULL)
	{
		printf("Could not create the debug trace file!\n");
		return (1);
	}
	return (0);
}

static void		launch_real_test(void)
{
	t_unit_test const	f_tab[] = {
		{"ft_bzero  ", &test_bzero},
		{"ft_strcat ", &test_bzero},
		{"ft_isalnum", &test_isalnum},
		{"ft_isalpha", &test_isalpha},
		{"ft_isascii", &test_isascii},
		{"ft_isprint", &test_isprint},
		{"ft_isdigit", &test_isdigit},
		{"ft_toupper", &test_toupper},
		{"ft_tolower", &test_tolower},
		{"ft_puts   ", &test_bzero},
		{"ft_strlen ", &test_strlen},
		{"ft_memset ", &test_bzero},
		{"ft_memcpy ", &test_bzero},
		{"ft_strdup ", &test_bzero},
		{"ft_cat    ", &test_bzero},
		{"ft_isspace", &test_isspace},
		{"ft_islower", &test_islower},
		{"ft_isupper", &test_isupper},
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
	{
		if (set_debug_file())
			return (1);
		launch_real_test();
	}
	else if (strcmp(argv[1], TEST) == 0)
		launch_testception();
	else
		print_usage();
	fclose(g_fstream);
	return (0);
}
