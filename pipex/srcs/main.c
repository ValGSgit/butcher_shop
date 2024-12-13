/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagarcia <vagarcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:03:44 by vagarcia          #+#    #+#             */
/*   Updated: 2024/12/13 17:35:12 by vagarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_skipspace(const char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	return (i);
}

int	empty_arg(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (!av[i] || av[i][ft_skipspace(av[i])] == '\0')
			return (1);
		i++;
	}
	return (0);
}

// int main(int ac, char **av, char **env)
// {
//     int pipe_fds[2];
//     pid_t child_pid;
//     int in_fd, out_fd;

//     if (ac != 5 || empty_arg(av))
//         exit_error();
//     in_fd = open(av[1], O_RDONLY);
//     if (in_fd == -1)
//         exit_error();
//     out_fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
//     if (out_fd == -1) {
//         close(in_fd);
//         exit_error();
//     }
//     // Set up the first command
//     pipe(pipe_fds);
//     child_pid = fork();
//     if (child_pid == -1)
// 	{
//         close(in_fd);
//         close(out_fd);
//         close(pipe_fds[0]);
//         close(pipe_fds[1]);
//         exit_error();
//     }
//     if (child_pid == 0)
// 	{

//         dup2(in_fd, STDIN_FILENO);
//         dup2(pipe_fds[1], STDOUT_FILENO);
//         close(in_fd);
//         close(out_fd);
//         close(pipe_fds[0]);
//         close(pipe_fds[1]);
//         do_cp(av + 2, pipe_fds, env);
// 	} 
// 	else
// 	{
//         close(pipe_fds[1]);
//         dup2(pipe_fds[0], STDIN_FILENO);
//         dup2(out_fd, STDOUT_FILENO);
//         close(pipe_fds[0]);
//         close(in_fd);
//         close(out_fd);
//         do_pp(av + 3, pipe_fds, env); // av + 3 points to cmd2
//     }
//     close(pipe_fds[0]);
//     close(pipe_fds[1]);
//     wait(NULL);
//     wait(NULL);

//     return 0;
// }

int	main(int ac, char **av, char **env)
{
	int		pipe_fds[2];
	pid_t	child_pid;
	int		pipe_result;

	if (ac != 5 || empty_arg(av))
		exit_error();
	pipe_result = pipe(pipe_fds);
	if (pipe_result == -1)
		return (close(pipe_fds[0]), close(pipe_fds[1]), exit(EXIT_FAILURE), 1);
	child_pid = fork();
	if (child_pid == -1)
		return (close(child_pid), close(pipe_fds[0]), \
		close(pipe_fds[1]), exit(EXIT_FAILURE), 1);
	if (child_pid == 0)
	{
		do_cp(av, pipe_fds, env);
		close(child_pid);
	}
	else
		do_pp(av, pipe_fds, env);
	close(pipe_result);
	close(pipe_fds[0]);
	close(pipe_fds[1]);
	return (0);
}
