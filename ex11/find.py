# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    find.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/02 06:35:43 by zasabri           #+#    #+#              #
#    Updated: 2023/04/02 21:36:33 by zasabri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/usr/local/bin/python3

import urllib.request
import json

pokemon_name = input("Enter the name of a Pokemon: ").lower()
url = "https://pokeapi.co/api/v2/pokemon/" + pokemon_name
try:
  response=urllib.request.get(url).json()
  res=urllib.request.get(url)
  if res.status_code == 200:
    print("Name: {}".format(response["name"]))
    for ability in response['abilities']:
      print("- {}".format(ability['ability']['name'].capitalize()))
except:
  print("Not found")