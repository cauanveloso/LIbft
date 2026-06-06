#include "libft.h"
#include <ctype.h>
#include <stdio.h>

static void test_isalpha(void)
{
	int tests[] = {'A', 'z', '5', ' ', '\n'};
	int i = 0;

	printf("\n=== ft_isalpha ===\n");
	while (i < 5)
	{
		printf("'%c' -> ft:%d | libc:%d %s\n",
			   tests[i],
			   ft_isalpha(tests[i]),
			   isalpha(tests[i]),
			   (ft_isalpha(tests[i]) != 0) == (isalpha(tests[i]) != 0)
				   ? "✅"
				   : "❌");
		i++;
	}
}

static void test_isdigit(void)
{
	int tests[] = {'0', '9', 'A', ' ', '\n'};
	int i = 0;

	printf("\n=== ft_isdigit ===\n");
	while (i < 5)
	{
		printf("'%c' -> ft:%d | libc:%d %s\n",
			   tests[i],
			   ft_isdigit(tests[i]),
			   isdigit(tests[i]),
			   (ft_isdigit(tests[i]) != 0) == (isdigit(tests[i]) != 0)
				   ? "✅"
				   : "❌");
		i++;
	}
}

static void test_isalnum(void)
{
	int tests[] = {'A', '9', '#', ' ', '\n'};
	int i = 0;

	printf("\n=== ft_isalnum ===\n");
	while (i < 5)
	{
		printf("'%c' -> ft:%d | libc:%d %s\n",
			   tests[i],
			   ft_isalnum(tests[i]),
			   isalnum(tests[i]),
			   (ft_isalnum(tests[i]) != 0) == (isalnum(tests[i]) != 0)
				   ? "✅"
				   : "❌");
		i++;
	}
}

static void test_isascii(void)
{
	int tests[] = {0, 65, 127, 128, 200};
	int i = 0;

	printf("\n=== ft_isascii ===\n");
	while (i < 5)
	{
		printf("%d -> ft:%d | libc:%d %s\n",
			   tests[i],
			   ft_isascii(tests[i]),
			   isascii(tests[i]),
			   (ft_isascii(tests[i]) != 0) == (isascii(tests[i]) != 0)
				   ? "✅"
				   : "❌");
		i++;
	}
}

static void test_isprint(void)
{
	int tests[] = {'A', ' ', '~', '\n', 127};
	int i = 0;

	printf("\n=== ft_isprint ===\n");
	while (i < 5)
	{
		printf("%d -> ft:%d | libc:%d %s\n",
			   tests[i],
			   ft_isprint(tests[i]),
			   isprint(tests[i]),
			   (ft_isprint(tests[i]) != 0) == (isprint(tests[i]) != 0)
				   ? "✅"
				   : "❌");
		i++;
	}
}

static void test_toupper(void)
{
	char tests[] = {'a', 'z', 'A', '5', '#'};
	int i = 0;

	printf("\n=== ft_toupper ===\n");
	while (i < 5)
	{
		printf("'%c' -> ft:'%c' | libc:'%c' %s\n",
			   tests[i],
			   ft_toupper(tests[i]),
			   toupper(tests[i]),
			   ft_toupper(tests[i]) == toupper(tests[i])
				   ? "✅"
				   : "❌");
		i++;
	}
}

static void test_tolower(void)
{
	char tests[] = {'A', 'Z', 'a', '5', '#'};
	int i = 0;

	printf("\n=== ft_tolower ===\n");
	while (i < 5)
	{
		printf("'%c' -> ft:'%c' | libc:'%c' %s\n",
			   tests[i],
			   ft_tolower(tests[i]),
			   tolower(tests[i]),
			   ft_tolower(tests[i]) == tolower(tests[i])
				   ? "✅"
				   : "❌");
		i++;
	}
}

int main(void)
{
	test_isalpha();
	test_isdigit();
	test_isalnum();
	test_isascii();
	test_isprint();
	test_toupper();
	test_tolower();
	return (0);
}