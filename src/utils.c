/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 16:37:47 by gpoblon           #+#    #+#             */
/*   Updated: 2019/05/31 12:17:24 by jmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"
#include <string.h>
#include <unistd.h>

int	cmp_files(int fd1, int fd2)
{
	ssize_t	f1_ret = 0;
	ssize_t	f2_ret = 0;
	char	f1_buff[BUFF_SIZE + 1];
	char	f2_buff[BUFF_SIZE + 1];

	lseek(fd1, 0, SEEK_SET);
	lseek(fd2, 0, SEEK_SET);
	bzero(f1_buff, BUFF_SIZE + 1);
	bzero(f2_buff, BUFF_SIZE + 1);
	while ((f1_ret = read(fd1, f1_buff, BUFF_SIZE)) >= 0 &&
		(f2_ret = read(fd2, f2_buff, BUFF_SIZE)) >= 0)
	{
		if (f1_ret != f2_ret || strcmp((char *)f1_buff, (char *)f2_buff))
			return (FAILURE);
		if (f1_ret == 0 && f2_ret == 0)
			return (SUCCESS);
		bzero(f1_buff, BUFF_SIZE + 1);
		bzero(f2_buff, BUFF_SIZE + 1);
	}
	return (FAILURE);
}

int	cmp_file_str(int fd1, char const *s)
{
	ssize_t	f1_ret = 0;
	char	f1_buff[BUFF_SIZE + 1];
	ssize_t	s_size = strlen(s);

	lseek(fd1, 0, SEEK_SET);
	bzero(f1_buff, BUFF_SIZE + 1);
	while ((f1_ret = read(fd1, f1_buff, BUFF_SIZE)) >= 0)
	{
		if (f1_ret == 0 && s_size == 0)
			return (SUCCESS);
		if (strcmp((char *)f1_buff, s))
			return (FAILURE);
		s_size -= f1_ret;
		bzero(f1_buff, BUFF_SIZE + 1);
	}
	return (FAILURE);
}
