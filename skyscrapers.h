/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skyscrapers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 13:06:58 by mhaddad           #+#    #+#             */
/*   Updated: 2025/09/20 13:07:28 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef SKYSCRAPERS_H
# define SKYSCRAPERS_H

typedef struct s_clues
{
	int	colup[4];
	int	coldown[4];
	int	rowleft[4];
	int	rowright[4];
}	t_clues;

int		fov(int *line);
int		clue(int grid[4][4], t_clues clues);
int		is_valid(int grid[4][4], int row, int col, int num);
int		solve(int grid[4][4], int row, int col, t_clues clues);
void	print(int grid[4][4]);

int		input(int argc, char **argv, int values[16]);
void	fill(int values[16], t_clues *clues);
void	start(int grid[4][4]);

#endif
