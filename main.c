/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 13:06:25 by mhaddad           #+#    #+#             */
/*   Updated: 2025/09/20 13:06:28 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "skyscrapers.h"
#include <unistd.h>

int	input(int argc, char **argv, int values[16])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (argc != 2)
		return (0);
	while (argv[1][i] && j < 16)
	{
		if (argv[1][i] >= '1' && argv[1][i] <= '4')
			values[j++] = argv[1][i] - '0';
		i++;
	}
	if (j != 16)
		return (0);
	return (1);
}

void	fill(int values[16], t_clues *clues)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (i < 4)
			clues->colup[i] = values[i];
		else if (i < 8)
			clues->coldown[i - 4] = values[i];
		else if (i < 12)
			clues->rowleft[i - 8] = values[i];
		else
			clues->rowright[i - 12] = values[i];
		i++;
	}
}

void	start(int grid[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int		grid[4][4];
	int		values[16];
	t_clues	clues;

	start(grid);
	if (!input(argc, argv, values))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	fill(values, &clues);
	if (solve(grid, 0, 0, clues))
		print(grid);
	else
		write(1, "Error\n", 6);
	return (0);
}
