/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra < ebezerra@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 01:27:59 by alfausti          #+#    #+#             */
/*   Updated: 2022/04/18 05:52:46 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	check_double(int grid[4][4], int pos, int size)
{
	int	i;

	i = -1;
	while (++i < pos / 4)
		if (grid[i][pos % 4] == size)
			return (1);
	i = -1;
	while (++i < pos % 4)
		if (grid[pos / 4][i] == size)
			return (1);
	return (0);
}

void	ft_initialize_solution(int solution[4][4], int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			solution[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	solve(int grid[4][4], int entry[16], int pos)
{
	int	size;

	if (pos == 16)
		return (1);
	size = 0;
	while (++size <= 4)
	{
		if (check_double(grid, pos, size) == 0)
		{
			grid[pos / 4][pos % 4] = size;
			if (check_case_is(grid, pos, entry) == 0)
			{
				if (solve(grid, entry, pos + 1) == 1)
					return (1);
			}
			else
				grid[pos / 4][pos % 4] = 0;
		}
	}
	return (0);
}

void	solve_sky(int grid[4][4])
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			ft_putnumber(grid[i][j]);
			if (j != 3)
				ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}

int	main(int argc, char **argv)
{
	int	grid[4][4];
	int	*entry;

	ft_initialize_solution(grid, 4);
	if (check(argc, argv) == 1)
		return (0);
	entry = get_numbers(argv[1]);
	if (solve(grid, entry, 0) == 1)
		solve_sky(grid);
	else
		ft_putstr("Error\n");
	return (0);
}
