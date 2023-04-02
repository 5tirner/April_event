/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sss.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 01:55:16 by zasabri           #+#    #+#             */
/*   Updated: 2023/04/02 05:30:06 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
	char 			str[255];
	int				check;
	struct timeval time;
	char			*save;
	
	printf("Choose rock, paper, or scissors: ");
	scanf("%s", str);
	check = 0;
	if (strncmp(str, "paper", strlen(str)) && strncmp(str, "scissors", strlen(str)) 
		&& strncmp(str, "rock", strlen(str)))
	{
		while (1)
		{
			write(2, "Choose rock, paper, or scissors: ", 33);
			char str2[8];
			scanf("%s", str2);
			if (strncmp(str2, "paper", strlen(str2)) && strncmp(str2, "scissors", strlen(str2))
				&& strncmp(str2, "rock", strlen(str2)))
				continue ;
			else
			{
				check = 1;
				save =  str2;
				break ;
			}
		}
	}
	char *str3[4] = {"paper", "rock", "sissors", NULL};
	int	r;
	while (1)
	{
		gettimeofday(&time, NULL);
		int t = (time.tv_sec * 0.1)+(time.tv_sec * 0.1);
		r = (((rand() % 10) + t) / 2) % 10;
		//printf("%d\n", r);
		if (r >=0 && r <= 2)
			break;
	}
	if (check == 0)
	{
		if (str[0] == 'p' && str3[r][0] == 'r')
			printf("Congratulations! You won! The computer chose %s.\n", str3[r]);
		else if (str[0] == 'p' && str3[r][0] == 's')
			printf("Sorry, you lost. The computer chose %s\n", str3[r]);
		else if (str[0] == 'r' && str3[r][0] == 's')
			printf("Congratulations! You won! The computer chose %s.\n", str3[r]);
		else if (str[0] == 'r' && str3[r][0] == 'p')
			printf("Sorry, you lost. The computer chose %s\n", str3[r]);
		else if (str[0] == 's' && str3[r][0] == 'p')
			printf("Congratulations! You won! The computer chose %s.\n", str3[r]);
		else if (str[0] == 's' && str3[r][0] == 'r')
			printf("Sorry, you lost. The computer chose %s\n", str3[r]);
		else
			printf("Draw, The computer chose %s.\n", str3[r]);
	}
	else
	{
		if (save[0] == 'p' && str3[r][0] == 'r')
			printf("Congratulations! You won! The computer chose %s.\n", str3[r]);
		else if (save[0] == 'p' && str3[r][0] == 's')
			printf("Sorry, you lost. The computer chose %s\n", str3[r]);
		else if (save[0] == 'r' && str3[r][0] == 's')
			printf("Congratulations! You won! The computer chose %s.\n", str3[r]);
		else if (save[0] == 'r' && str3[r][0] == 'p')
			printf("Sorry, you lost. The computer chose %s\n", str3[r]);
		else if (save[0] == 's' && str3[r][0] == 'p')
			printf("Congratulations! You won! The computer chose %s.\n", str3[r]);
		else if (save[0] == 's' && str3[r][0] == 'r')
			printf("Sorry, you lost. The computer chose %s\n", str3[r]);
		else
			printf("Draw, The computer chose %s.\n", str3[r]);
	}
}