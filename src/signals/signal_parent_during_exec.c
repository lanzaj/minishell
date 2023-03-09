/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_parent_during_exec.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:25:13 by jlanza            #+#    #+#             */
/*   Updated: 2023/03/09 10:09:18 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	handle_sigint_parent_during_exec(int sig)
{
	ft_printf("\n");
	g_return_value = 130;
	exit(130);
	(void)sig;
}

void	handle_sigquit_parent_during_exec(int sig)
{
	g_return_value = 131;
	ft_printf("Quit (core dumped)\n");
	exit(131);
	(void)sig;
}

void	init_signal_parent_during_exec(void)
{
	signal(SIGINT, &handle_sigint_parent_during_exec);
	signal(SIGQUIT, &handle_sigquit_parent_during_exec);
}
