/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_signal.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmichaud <jmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 16:52:33 by jmichaud          #+#    #+#             */
/*   Updated: 2019/05/21 16:55:55 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CATCH_SIGNAL_H
# define CATCH_SIGNAL_H

/*
** catch_signal.c
*/
# define NB_SIGNAL	4
# define ABRT_S		6
# define BUSE_S		10
# define SEGV_S		11
# define TIME_S		14
# define ABRT_N		"ABRT"
# define BUSE_N		"BUSE"
# define SEGV_N		"SEGV"
# define TIME_N		"TIMEOUT"
# define ERROR_MSG	"ERROR"

typedef struct		s_signal
{
	int				signal;
	char const		*name;
}					t_signal;

#endif
