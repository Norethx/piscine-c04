/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:42:54 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/04/02 16:51:19 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi_base(char *str, char *base);

int	ft_verify_base(char *base)
{
	int	i;
	int	scn_i;

	i = 0;
	while (base[i] != '\0')
	{
		scn_i = 0;
		while (base[scn_i] != '\0')
		{
			if ((base[i] == base[scn_i] && i != scn_i)
				|| (base[scn_i] == '+' || base [scn_i] == '-')
				|| (base[scn_i] <= 32 || base[scn_i] > 126))
				return (0);
			scn_i++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	else
		return (i);
}

int	ft_base_value(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	nb_base;
	int	result;
	int	i;
	int	mult;

	nb_base = ft_verify_base(base);
	if (nb_base == 0)
		return (0);
	i = 0;
	mult = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-' || str[i] == base[0])
	{
		if (str[i] == '-')
			mult *= -1;
		i++;
	}
	while (ft_base_value(base, str[i]) != 0 && str[i] != '\0')
	{
		result = (ft_base_value(base, str[i]) + (result * nb_base));
		i++;
	}
	return (result * mult);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	argc = 0;
	if (argv)
	printf("number : %d\n", ft_atoi_base("123zzz","0123456789abcdef"));
}

