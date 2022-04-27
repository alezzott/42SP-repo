/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfausti <alfausti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 01:23:00 by alfausti          #+#    #+#             */
/*   Updated: 2022/04/21 23:20:50 by alfausti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_printnum(int a, int b, int c);
void	ft_putchar(char c);

void	ft_print_comb(void)
{
	int	d;
	int	e;
	int	f;

		d = 0;
	while (d < 10)
	{
		e = d + 1;
		while (e < 10)
		{
			f = e + 1;
			while (f < 10)
			{
				ft_printnum (d, e, f);
				f++;
			}
			e++;
		}
		d++;
	}
}

void	ft_printnum(int a, int b, int c)
{
	a += '0';
	b += '0';
	c += '0';
	ft_putchar (a);
	ft_putchar (b);
	ft_putchar (c);
	if (a != '7' || b != '8' || c != '9')
	{
		write (1, ", ", 2);
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

#include <stdio.h>

void	ft_print_comb(void);

int	main(void)
{
	ft_print_comb();
	return (0);
}
