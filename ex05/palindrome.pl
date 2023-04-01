# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    palindrome.pl                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/01 18:29:37 by zasabri           #+#    #+#              #
#    Updated: 2023/04/01 19:36:25 by zasabri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
# 
# char	*rev_str(char *str)
# {
	# char	*s;
	# int		i = 0, l = strlen(str) - 1;
	# s = malloc(strlen(str) + 1);
	# while (l >= 0)
	# {
		# s[i] = str[l];
		# l--;
		# i++;
	# }
	# s[i] = '\0';
	# return (s);
# }
# 
# int main()
# {
	# char	s[255];
	# printf("Enter a string: ");
	# scanf("%[^\n]", s);
	# char *str = rev_str(s);
	# if (strncmp(str, s, strlen(s)) == 0)
		# printf("The string is a palindrome!\n");
	# else
		# printf("The string is not a palindrome!\n");
# }

