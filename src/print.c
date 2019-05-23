/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:09:33 by jmichaud          #+#    #+#             */
/*   Updated: 2019/05/23 17:49:06 by gpoblon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "unit_test.h"
#include <stdio.h>
#include <stdlib.h> // system()

int			fperr(const char *str, ...)
{
	va_list	args;

	va_start(args, str);
	fprintf(g_fstream, "(%s) ", g_fname);
	fprintf(g_fstream, str, args);
	va_end(args);
	return (FAILURE);
}

void		print_usage(void)
{
	printf("usage: ./libftASM [--test]\n");
}

void		print_header(void)
{
	system("clear");
	printf("%s/*\n** %sLibftASM - Unit Tests%s\n%s**\t%sauthor: jmichaud%s\n%s*/%s\n",
			YELLOW, GREEN, RESET, YELLOW, GREY, RESET, YELLOW, RESET);
}

void		print_results(int ok, int total)
{
	printf("\n%sResults : ", WHITE);
	printf("%s", (ok == total) ? GREEN : RED);
	printf("%d/%d - %s%s\n", ok, total, (ok == total) ? "SUCCESS" : "FAILURE", RESET);
}

void		print_name(char const *name)
{
	printf("%s%s%s :", BLUE, name, RESET);
	fflush(stdout);
}

void		print_error(char const *name)
{
	printf("%s%s%s\n", RED, name, RESET);
}

void		print_letter(char c, int ret)
{
	printf(" %s%c%s", (ret == SUCCESS) ? GREEN : RED, c, RESET);
	fflush(stdout);
}

void		print_signal(char const *signal)
{
	printf("%s[%s]%s", RED, signal, RESET);
	fflush(stdout);
}

void		print_nb_ok(int i, int ko)
{
	printf(" : %s%d/%d%s\n", (ko == 0) ? GREEN : RED, i - ko, i, RESET);
}
