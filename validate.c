/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddad <mhaddad@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 12:37:59 by mhaddad           #+#    #+#             */
/*   Updated: 2025/09/20 12:38:02 by mhaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "skyscrapers.h"
#include <unistd.h>

int	is_valid(int grid[4][4], int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if ((grid[row][i] == num) || (grid[i][col] == num))
			return (0);
		i++;
	}
	return (1);
}
