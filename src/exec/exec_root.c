/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_root.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:50:34 by jlanza            #+#    #+#             */
/*   Updated: 2023/03/10 12:44:29 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	exec_special_builtins(t_param *prm, char **cmd)
{
	int	ret_val;

	ret_val = g_return_value;
	if (!ft_strcmp(cmd[0], "cd"))
		ret_val = exec_cd(prm, cmd);
	if (!ft_strcmp(cmd[0], "export"))
		ret_val = exec_export(prm, cmd);
	if (!ft_strcmp(cmd[0], "unset"))
		ret_val = exec_unset(prm, cmd);
	if (!ft_strcmp(cmd[0], "exit"))
		ret_val = exec_exit(prm, cmd);
	g_return_value = ret_val;
}

int	exec_root(t_param *prm, t_node *root)
{
	int	pipe_pid;
	int	status;

	init_signal_parent();
	pipe_pid = fork();
	if (pipe_pid == 0)
	{
		init_signal_parent_during_heredoc();
		exec_pipe(prm, root);
	}
	else
	{
		waitpid(pipe_pid, &status, 0);
		if (WIFSIGNALED(status))
			g_return_value = WTERMSIG(status);
		else if (WIFEXITED(status))
			g_return_value = WEXITSTATUS(status);
	}
	if (root->token_type != TK_PIPE)
	{
		while (root->token_type != TK_EXEC)
			root = root->left;
		exec_special_builtins(prm, root->cmd);
	}
	return (g_return_value);
}
