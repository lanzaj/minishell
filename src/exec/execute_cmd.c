/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 06:52:28 by jlanza            #+#    #+#             */
/*   Updated: 2023/03/09 11:12:10 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	execute_cmd(t_pipe *args, int n_cmd)
{
	char	**cmd;
	char	*path_cmd;
	int		return_value;

	cmd = args->argv[n_cmd]->cmd;
	return_value = 0;
	if (cmd == NULL)
		return (1);
	if (!check_is_builtin(cmd[0]))
		return_value = get_path_name(args, &path_cmd, cmd);
	if (return_value != 0)
		return (return_value);
	if (exec_cmd(args, path_cmd, cmd) == -1)
	{
		return (command_not_found(cmd, cmd));
	}
	return (0);
}
