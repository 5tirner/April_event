/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 23:11:03 by zasabri           #+#    #+#             */
/*   Updated: 2023/04/04 00:31:49 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int check_arg(char *av)
{
    int i = 0;
    while (av[i])
    {
        if (!isdigit(av[i]) && av[i] != '+')
            return (1);
        if (i != 0 && av[i] == '+')
            return (1);
        i++;
    }
    return (0);
}
int main(int ac, char **av)
{
    char *str = "                    ";
    if (ac == 2)
    {
        if (check_arg(av[1]))
            return (printf("Please Enter positive natural number\n"));
        int p = atoi(av[1]);
        int i = 0;
        int width = 1;
        int hight = 0;
        int save = p;
        int space = p * 5;
        int mid;
        while (i < p)
        {
            while (hight < save)
            {
                int j = -1;
                while (++j < space)
                    printf(" ");
                printf("/");
                j = -1;
                if (i + 1 == p)
                {
                    while (++j < width)
                    {
                        int mid = width / 2;
                        if (hight >= p - 1)
                        {
                            if (j == mid || j == mid - 1 || j == mid + 1)
                                printf("|");
                            else
                                printf("*");
                        }
                        else
                            printf("*");
                    }
                }
                else
                {
                    while (++j < width)    
                        printf("*");
                }
                printf("\\\n");
                j = -1;
                hight++;
                width += 2;
                space--;
            }
            save++;
            i++;
            width+=4;
            space-=2;
            hight = 0;
        }
    }
}
