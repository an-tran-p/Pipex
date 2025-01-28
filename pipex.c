/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atran <atran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:02:26 by atran             #+#    #+#             */
/*   Updated: 2025/01/28 19:54:31 by atran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_handling(int flag)
{
	if (flag == 1)
		ft_printf("Error: 4 arguments needed <file1> <cmd1> <cmd2> <file2>\n");
}

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
		error_handling(1);
}
