/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 05:41:55 by zasabri           #+#    #+#             */
/*   Updated: 2023/04/02 06:13:12 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	ft_count_words(const char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while ((str[i]) && (str[i] == c))
			i++;
		if (str[i])
		{
			while (str[i] && str[i] != c)
				i++;
			j += 1;
		}
	}
	return (j);
}

static int	ft_len(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
	{
		i++;
	}
	return (i);
}

static char	**ft_free_allocation(char **s, int k)
{
	while (k >= 0)
	{
		free(s[k]);
		k--;
	}
	free(s);
	return (NULL);
}

char	**ft_split(char const *s1, char c)
{
	char	**arr;
	int		k;
	int		j;

	k = 0;
	if (s1 == NULL)
		return (NULL);
	arr = (char **)calloc((ft_count_words(s1, c) + 1), sizeof(char *));
	if (!arr)
		return (NULL);
	while (*s1)
	{
		while (*s1 && *s1 == c)
			s1++;
		if (*s1)
		{
			arr[k] = (char *)calloc(ft_len(s1, c) + 1, sizeof(char));
			if (!arr[k++])
				return (ft_free_allocation(arr, k - 1));
			j = 0;
			while (*s1 && (*s1 != c))
				arr[k - 1][j++] = *(s1++);
		}
	}
	return (arr);
}

int	get_the_longest_one(char *av)
{
	int	len = 0, i = 0;
	int j = 0;
	while (av[i])
	{
		if (av[i] == ' ')
		{
			if (j > len)
				len = j;
			j = -1;
		}
		j++;
		i++;
	}
	if (!len)
		return (j);
	else
		return (len);
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int	len = get_the_longest_one(av[1]);
		int i = -1;
		char **str = ft_split(av[1], ' ');
		while (++i < len + 4)
			printf("*");
		printf("\n");
		i = 0;
		while (str[i])
		{
			printf("* ");
			if (strlen(str[i]) == len)
				printf("%s *\n", str[i]);
			else
			{
				int j = strlen(str[i]) - 1;
				printf("%s", str[i]);
				while (++j < len)
					printf(" ");
				printf("*\n");
			}
			i++;
		}
		i = -1;
		while (++i < len + 4)
			printf("*");
		printf("\n");
	}
}