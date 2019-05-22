/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_signal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 12:56:26 by jmichaud          #+#    #+#             */
/*   Updated: 2019/05/21 16:55:13 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "catch_signal.h"

char const		*catch_signal(int signal)
{
	int				i;
	t_signal const	signal_list[NB_SIGNAL] = {
		{ABRT_S, ABRT_N},
		{BUSE_S, BUSE_N},
		{SEGV_S, SEGV_N},
		{TIME_S, TIME_N}
	};

	i = -1;
	while (++i < NB_SIGNAL)
		if (signal_list[i].signal == signal)
			break ;
	if (i == NB_SIGNAL)
		return (ERROR_MSG);
	else
		return (signal_list[i].name);
}
