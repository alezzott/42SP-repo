/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra < ebezerra@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 01:28:05 by alfausti          #+#    #+#             */
/*   Updated: 2022/04/18 05:35:34 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Prints a single char
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

//prints a list of characters
void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

//gives the length of a list of character (strlen)
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

//similar to (atoi() in stdlib.h)
int	ft_atoi(char *str)
{
	int	i;
	int	nbr;
	int	nbrsubtract;

	i = 0;
	nbr = 0;
	nbrsubtract = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			nbrsubtract++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		nbr = nbr * 10 + (str[i++] - '0');
	if (nbrsubtract % 2 == 1)
		return (nbr * -1);
	return (nbr);
}

//prints a number in the standart output
void	ft_putnumber(int note)
{
	unsigned int	nbr;

	if (note < 0)
	{
		ft_putchar('-');
		nbr = note * -1;
	}
	else
		nbr = note;
	if (nbr / 10 != 0)
		ft_putnumber(nbr / 10);
	ft_putchar(nbr % 10 + 48);
}
