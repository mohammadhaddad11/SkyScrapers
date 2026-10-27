/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 12:38:51 by mhaddad           #+#    #+#             */
/*   Updated: 2025/09/20 12:38:54 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "skyscrapers.h"

int	solve(int grid[4][4], int row, int col, t_clues clues)
{
	int	num;

	if (row == 4)
		return (clue(grid, clues));
	if (col == 4)
		return (solve(grid, row + 1, 0, clues));
	if (grid[row][col] != 0)
		return (solve(grid, row, col + 1, clues));
	num = 1;
	while (num <= 4)
	{
		if (is_valid(grid, row, col, num))
		{
			grid[row][col] = num;
			if (solve(grid, row, col + 1, clues))
				return (1);
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}
