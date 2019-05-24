#include "unit_test.h"
#include "libftASM.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#define TAB_SIZE 1000

static int	test(char *s1, char const *s2)
{
	char	sys_ret[TAB_SIZE];
	char	ft_ret[TAB_SIZE];

	strcpy(sys_ret, s1);
	strcpy(ft_ret, s1);
	strcat(sys_ret, s2);
	ft_strcat(ft_ret, s2);
	if (strcmp(ft_ret, sys_ret) != 0)
		return (fperr("_ft: |%s|; sys: |%s|\n",
						ft_ret, sys_ret));
	return (SUCCESS);
}

static int	test_a(void)
{
	char		*s1 = "";
	char const	*s2 = "";

	return (test(s1, s2));
}

static int	test_b(void)
{
	char		*s1 = "I AM NOT EMPTY";
	char const	*s2 = "";

	return (test(s1, s2));
}

static int	test_c(void)
{
	char		*s1 = "";
	char const	*s2 = "I AM NOT EMPTY";

	return (test(s1, s2));
}

static int	test_d(void)
{
	char		*s1 = "WE ARE NOT EMPTY";
	char const	*s2 = "WE ARE NOT EMPTY";

	return (test(s1, s2));
}

static int	test_e(void)
{
	char		*s1 = "I AM THE SMALLEST";
	char const	*s2 = "Daenerys of the House Targaryen, the First of Her Name, The Unburnt, Queen of the Andals, the Rhoynar and the First Men, Queen of Meereen, Khaleesi of the Great Grass Sea, Protector of the Realm, Lady Regent of the Seven Kingdoms, Breaker of Chains and Mother of Dragons";

	return (test(s1, s2));
}

static int	test_f(void)
{
	char		*s1 = "Daenerys of the House Targaryen, the First of Her Name, The Unburnt, Queen of the Andals, the Rhoynar and the First Men, Queen of Meereen, Khaleesi of the Great Grass Sea, Protector of the Realm, Lady Regent of the Seven Kingdoms, Breaker of Chains and Mother of Dragons";
	char const	*s2 = "I AM THE SMALLEST";

	return (test(s1, s2));
}

int			test_strcat(void)
{
	int		(*f_tab[])(void) = {
		test_a,
		test_b,
		test_c,
		test_d,
		test_e,
		test_f,
		0
	};

	return (launch_tests(f_tab));
}
