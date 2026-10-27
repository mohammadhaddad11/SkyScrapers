/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clues.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 12:33:12 by mhaddad           #+#    #+#             */
/*   Updated: 2025/09/20 12:33:15 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "skyscrapers.h"

int	check_column(int grid[4][4], int clue_up, int clue_down, int col)
{
	int	line[4];
	int	i;

	i = 0;
	while (i < 4)
	{
		line[i] = grid[i][col];
		i++;
	}
	if (fov(line) != clue_up)
		return (0);
	i = 0;
	while (i < 4)
	{
		line[i] = grid[3 - i][col];
		i++;
	}
	if (fov(line) != clue_down)
		return (0);
	return (1);
}

int	check_row(int grid[4][4], int clue_left, int clue_right, int row)
{
	int	line[4];
	int	i;

	i = 0;
	while (i < 4)
	{
		line[i] = grid[row][i];
		i++;
	}
	if (fov(line) != clue_left)
		return (0);
	i = 0;
	while (i < 4)
	{
		line[i] = grid[row][3 - i];
		i++;
	}
	if (fov(line) != clue_right)
		return (0);
	return (1);
}

int	clue(int grid[4][4], t_clues clues)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!check_column(grid, clues.colup[i], clues.coldown[i], i))
			return (0);
		if (!check_row(grid, clues.rowleft[i], clues.rowright[i], i))
			return (0);
		i++;
	}
	return (1);
}
