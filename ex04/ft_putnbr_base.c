/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgomes-d <rgomes-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:42:54 by rgomes-d          #+#    #+#             */
/*   Updated: 2025/04/01 17:56:42 by rgomes-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_base(int nbr, char *base);

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
				|| (base[scn_i] < 32 || base[scn_i] > 126))
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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	nb_base;
	int	aux_int_max;

	aux_int_max = 0;
	nb_base = ft_verify_base(base);
	if (nb_base == 0)
		return ;
	if (nbr < 0)
	{
		aux_int_max = 1;
		nbr = (nbr + aux_int_max) * -1;
		ft_putchar('-');
	}
	if (nbr >= nb_base)
	{
		if ((nbr % nb_base) + aux_int_max == nb_base)
			ft_putnbr_base((nbr / nb_base) + aux_int_max, base);
		else
			ft_putnbr_base((nbr / nb_base), base);
		ft_putchar(base[((nbr % nb_base) + aux_int_max) % nb_base]);
	}
	else
		ft_putchar(base[nbr + aux_int_max]);
}
/*
int	main(int argc, char **argv)
{
	argc = 0;
	if (argv)
	ft_putnbr_base(-555555,"01234h6789");
}*/
