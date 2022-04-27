/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebezerra < ebezerra@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 01:27:47 by alfausti          #+#    #+#             */
/*   Updated: 2022/04/18 05:49:51 by ebezerra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_col_up(int grid[4][4], int pos, int entry[16])
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	if (pos / 4 == 3)
	{
		while (i < 4)
		{
			if (grid[i][pos % 4] > max)
			{
				max = grid[i][pos % 4];
				count++;
			}
			i++;
		}
		if (entry[pos % 4] != count)
			return (1);
	}
	return (0);
}

int	check_row_right(int grid[4][4], int pos, int entry[16])
{
	int	i;
	int	max_size;
	int	visible_towers;

	i = 4;
	max_size = 0;
	visible_towers = 0;
	if (pos % 4 == 3)
	{
		while (--i >= 0)
		{
			if (grid[pos / 4][i] > max_size)
			{
				max_size = grid[pos / 4][i];
				visible_towers++;
			}
		}
		if (entry[12 + pos / 4] != visible_towers)
			return (1);
	}
	return (0);
}

int	check_col_down(int grid[4][4], int pos, int entry[16])
{
	int	i;
	int	max;
	int	count;

	i = 3;
	max = 0;
	count = 0;
	if (pos / 4 == 3)
	{
		while (i >= 0)
		{
			if (grid[i][pos % 4] > max)
			{
				max = grid[i][pos % 4];
				count ++;
			}
			i--;
		}
		if (entry[4 + pos % 4] != count)
			return (1);
	}
	return (0);
}

int	check_row_left(int grid[4][4], int pos, int entry[16])
{
	int	i;
	int	max;
	int	count;

	i = 0;
	max = 0;
	count = 0;
	if (pos % 4 == 3)
	{
		while (i < 4)
		{
			if (grid[pos / 4][i] > max)
			{
				max = grid[pos / 4][i];
				count++;
			}
			i++;
		}
		if (entry[8 + pos / 4] != count)
			return (1);
	}
	return (0);
}

int	check_case_is(int grid[4][4], int pos, int entry[16])
{
	if (check_row_left(grid, pos, entry) == 1)
		return (1);
	if (check_row_right(grid, pos, entry) == 1)
		return (1);
	if (check_col_down(grid, pos, entry) == 1)
		return (1);
	if (check_col_up(grid, pos, entry) == 1)
		return (1);
	return (0);
}
