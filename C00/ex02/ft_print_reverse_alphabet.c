/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfausti <alfausti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 00:48:16 by alfausti          #+#    #+#             */
/*   Updated: 2022/04/20 02:03:54 by alfausti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c);

void	ft_print_reverse_alphabet(void)
{
	char	reverse;

	reverse = 'z';
	while (reverse >= 'a')
	{
		ft_putchar(reverse);
		reverse--;
	}
}

void	ft_putchar(char C)
{
	write(1, &C, 1);
}
