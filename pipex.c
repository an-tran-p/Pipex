/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atran <atran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:02:26 by atran             #+#    #+#             */
/*   Updated: 2025/01/29 21:11:06 by atran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_strarr(char **str_arr)
{
	int	i;

	i = 0;
	if (str_arr)
	{
		if (str_arr[i])
			free (str_arr[i]);
		i ++;
	}
	free(str_arr);
}

char	*find_path(char *cmd, char **envp)
{
	int	i;
	char	**paths;
	char	*top_path;
	char	*path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i ++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		top_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(top_path, cmd);
		free(top_path);
		if (access(path, F_OK) == 0)
			return (path);
		else
			free(path);
		i ++;
	}
	ft_free_strarr(paths);
	return (NULL);
}

void	execute(char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	path = find_path(cmd[0], envp);
	if (!path)
	{
		ft_free_strarr(cmd);
		perror("Can't find path to execute cmd\n");
		return ;
	}
	if (execve(path, cmd, envp) == -1)
		perror("Execution fails\n");
	ft_free_strarr(cmd);
	free(path);
}

int	main(int argc, char **argv, char **envp)
{
	char	*file1;
	char	*file2;
	char	*cmd1;
	char	*cmd2;
	int		fd1;
	int		fd2;

	if (argc != 5)
	{
		perror("Error: 4 arguments needed <file1> <cmd1> <cmd2> <file2>\n");
		return (1);
	}
	file1 = argv[1];
	cmd1 = argv[2];
	file2 = argv[3];
	cmd2 = argv[4];
	fd1 = open(file1, O_RDONLY);
	fd2 = open(file2, O_RDWR | O_CREAT);
	if (fd1 == -1 || fd2 == -1)
	{
		perror("Error opening file\n");
		return (1);
	}
	if (dup2(fd1, STDIN_FILENO) == -1)
	{
		perror("Error directing input");
		close(fd1);
		return (1);
	}
	close(fd1);
	execute(argv[2], envp);
	ft_printf("hello");
}
