/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blackjack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 01:42:56 by zasabri           #+#    #+#             */
/*   Updated: 2023/04/02 01:52:56 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int ac, char **av)
{
	if (ac == 2)
	{
		int	t = 0;
		int i = 0;
		char *alph = "TJDK";
		while (av[1][i])
		{
			if (strchr(alph, av[1][i]))
				t += 10;
			else if (isdigit(av[1][i]))
				t += av[1][i] - 48;
			i++;
		}
		int	a;
		if (a > 21)
			a = 1;
		else
			a = 11;
		i = 0;
		while (av[1][i])
		{
			if (av[1][i] == 'A')
				t += a;
			i++;
		}
		if (t > 20)
			t -= 10;
		if (t <= 20 || t >= 30)
			printf("Blackjack!");
		else
			printf("%d", t);
	}
}