/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:35:55 by jlanza            #+#    #+#             */
/*   Updated: 2023/03/09 13:21:05 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	is_path(char *str)
{
	if (str[0] == 'P'
		&& str[1] == 'A'
		&& str[2] == 'T'
		&& str[3] == 'H'
		&& str[4] == '=')
		return (1);
	return (0);
}

char	*ft_strjoin3(char *str1, char *str2, char *str3)
{
	char	*tmp;
	char	*res;

	tmp = ft_strjoin(str1, str2);
	if (tmp == NULL)
		return (NULL);
	res = ft_strjoin(tmp, str3);
	free(tmp);
	return (res);
}

static char	**get_path_tab(t_pipe *args, char **cmd)
{
	int		i;
	char	**strs;

	i = 0;
	while (args->prm->env[i] != NULL && !is_path(args->prm->env[i]))
		i++;
	if (args->prm->env[i] == NULL)
	{
		ft_put3str_fd("minishell: ", cmd[0], ": No such file or directory\n", 2);
		return (NULL);
	}
	if (!is_path(args->prm->env[i]))
	{
		ft_put3str_fd("minishell: ", cmd[0], ": Command not found\n", 2);
		return (NULL);
	}
	strs = ft_split(&(args->prm->env[i][5]), ':');
	garbage_split(args->prm, args->prm->source.id, strs);
	return (strs);
}

static int	test_exec_rights(char **path_cmd, char *path,
	char **path_tab, char **cmd)
{
	(void)(path_tab);
	if (!access(path, X_OK))
	{
		*path_cmd = path;
		return (0);
	}
	return (permission_denied(cmd));
}

int	get_path_name(t_pipe *args, char **path_cmd, char **cmd)
{
	int		i;
	char	**path_tab;
	char	*path;

	path_tab = get_path_tab(args, cmd);
	if (path_tab == NULL && !access(cmd[0], F_OK))
		return (test_exec_rights(path_cmd, cmd[0], path_tab, cmd));
	if (path_tab == NULL)
		return (path_not_found(path_tab, cmd));
	i = 0;
	while (path_tab[i] != NULL)
	{
		path = ft_strjoin3(path_tab[i], "/", cmd[0]);
		garbage_col(args->prm, args->prm->source.id, path);
		if (path == NULL)
			return (error_ft_strjoin3(path_tab, cmd));
		if (!access(path, F_OK))
			return (test_exec_rights(path_cmd, path, path_tab, cmd));
		i++;
	}
	if (!access(cmd[0], F_OK))
		return (test_exec_rights(path_cmd, ft_strdup_gc(args->prm,
					args->prm->source.id, cmd[0]), path_tab, cmd));
	return (command_not_found(path_tab, cmd));
}
