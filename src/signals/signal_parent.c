/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_parent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:24:21 by jlanza            #+#    #+#             */
/*   Updated: 2023/03/09 10:09:30 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	handle_sigint_parent(int sig)
{
	g_return_value = 130;
	(void)sig;
}

void	handle_sigquit_parent(int sig)
{
	g_return_value = 131;
	(void)sig;
}

void	init_signal_parent(void)
{
	signal(SIGINT, &handle_sigint_parent);
	signal(SIGQUIT, &handle_sigquit_parent);
}