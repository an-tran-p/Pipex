/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atran <atran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 18:03:58 by atran             #+#    #+#             */
/*   Updated: 2025/02/01 18:04:41 by atran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_open_file(char *file1, char *file2)
{
	int	fd1;
	int	fd2;

	fd1 = open(file1, O_RDONLY);
	if (fd1 == -1)
	{
		perror("Error opening input file\n");
		return (1);
	}
	close(fd1);
	fd2 = open(file2, O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (fd2 == -1)
	{
		perror("Error opening output file\n");
		return (1);
	}
	return (0);
}
