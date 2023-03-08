/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:32:12 by jlanza            #+#    #+#             */
/*   Updated: 2023/03/08 18:23:11 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

unsigned char	g_return_value = 0;

/* ne plus trim les espaces */
/*attention, ne pas utiliser l'enve du main*/
/*
int	main(int argc, char **argv, char **env)
{
	t_param	prm;
	t_node	*root;
	int		i;

	i = 1;
	if (argc < 2)
		return (1);
	ft_memset(&prm, 0, sizeof(t_param));
	clone_env(&prm, env);
	while (i < argc)
	{
		root = parse(&prm, argv[i]);
		print_ast(&prm, root);
		ft_printf("\n");
		i++;
	}
	empty_garbage(&prm, -1);
	return (0);
}*/

int	main(int argc, char *argv[], char *env[])
{
	char	*cmd;
	t_param	prm;
	t_node	*root;

	(void)argv;
	cmd = NULL;
	if (argc != 1)
		return (ft_printf_fd(2, "minishell: too many arguments"), 1);
	ft_memset(&prm, 0, sizeof(t_param));
	clone_env(&prm, env);
	print_minishell_title();
	prm.do_ = 1;
	while (prm.do_)
	{
		init_signal();
		readline_new_prompt(&cmd);
		if (cmd == NULL)
		{
			ft_printf("exit\n");
			break ;
		}
		{
			ft_printf("exit\n");
			break ;
		}
		if (ft_strlen(cmd) > 0)
			add_history(cmd);
		root = parse(&prm, cmd);
		if (root != NULL)
			exec_root(&prm, root);
	}
	empty_garbage(&prm, -1);
	rl_clear_history();
	return (g_return_value);
}
