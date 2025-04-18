/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:58:34 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/04/01 17:56:44 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str);

int	ft_atoi(char *str)
{
	int	result;
	int	i;
	int	mult;

	i = 0;
	mult = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-' || str[i] == '0')
	{
		if (str[i] == '-')
			mult = -mult;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		result = (str[i] - '0') + (result * 10);
		i++;
	}
	return (mult * result);
}
/*
#include <stdio.h>
int     main(int argc, char **argv)
{
	int i;
	int i2;

	if (argc < 3 || argc > 3)
		return (0);
        i = ft_atoi(argv[1]);
        i2 = ft_atoi(argv[2]);

	printf("result : %d\n", i);
	printf("result : %d\n", i2);
}*/
