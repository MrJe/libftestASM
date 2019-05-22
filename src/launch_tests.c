/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:31:26 by jmichaud          #+#    #+#             */
/*   Updated: 2019/05/22 13:14:17 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "unit_test.h"

int			fork_test(int (*unit_test)(void))
{
	pid_t		father;

	if ((father = fork()) == -1)
	{
		print_error("fork() failed");
		return (ERROR);
	}
	if (father > 0)
	{
		wait(&father);
		if (WIFSIGNALED(father))
			return (WTERMSIG(father));
		return (father == SUCCESS ? SUCCESS : FAILURE);
	}
	if (father == 0)
	{
		ualarm(2000000, 0);
		exit((*unit_test)());
	}
	return (ERROR);
}

int			launch_tests(int (*unit_test[])(void))
{
	char const		*result_tab = "abcdefghijklmnopqrstuvwxyz";
	int				i;
	int				ret;
	int				ko;

	ko = 0;
	i = 0;
	while (unit_test[i])
	{
		ret = fork_test(unit_test[i]);
		print_letter(result_tab[i % 26], ret);
		if (ret != SUCCESS)
			++ko;
		if (ret != SUCCESS && ret != ERROR && ret != FAILURE)
			print_signal(catch_signal(ret));
		++i;
	}
	print_nb_ok(i, ko);
	return (ko != 0 ? 0 : 1);
}
