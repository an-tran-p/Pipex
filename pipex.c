/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atran <atran@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:02:26 by atran             #+#    #+#             */
/*   Updated: 2025/02/01 19:39:36 by atran            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute(char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	path = find_path(cmd[0], envp);
	if (!path)
	{
		ft_free_strarr(cmd);
		perror("Command not found\n");
		return ;
	}
	if (execve(path, cmd, envp) == -1)
	{
		ft_free_strarr(cmd);
		free(path);
		perror("Execution fails\n");
		return ;
	}
	ft_free_strarr(cmd);
	free(path);
}

void	execute_child_process(int *fds, char *file1, char *cmd1, char **envp)
{
	int	fd1;

	close(fds[0]);
	fd1 = open(file1, O_RDONLY);
	dup2(fd1, STDIN_FILENO);
	close(fd1);
	dup2(fds[1], STDOUT_FILENO);
	close(fds[1]);
	execute(cmd1, envp);
	return ;
}

void	execute_parent_process(int *fds, char *file2, char *cmd2, char **envp)
{
	int	fd2;

	close(fds[1]);
	fd2 = open(file2, O_RDWR | O_CREAT | O_TRUNC, 0777);
	dup2(fds[0], STDIN_FILENO);
	close(fds[0]);
	dup2(fd2, STDOUT_FILENO);
	close(fd2);
	execute(cmd2, envp);
}

void	create_pipe_and_processes(char **argv, char **envp)
{
	int		fds[2];
	pid_t	pid1;

	if (pipe(fds) == -1)
	{
		perror("Failed creating pipe\n");
		return ;
	}
	pid1 = fork();
	if (pid1 < 0)
	{
		perror("Failed creating process\n");
		return ;
	}
	if (pid1 == 0)
		execute_child_process(fds, argv[1], argv[2], envp);
	else
	{
		waitpid(pid1, NULL, 0);
		execute_parent_process(fds, argv[4], argv[3], envp);
	}
}

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
	{
		perror("Error: 4 arguments needed <file1> <cmd1> <cmd2> <file2>\n");
		return (-1);
	}
	if (check_open_file(argv[1], argv[4]) != 0)
		return (-1);
	create_pipe_and_processes(argv, envp);
	return (0);
}
