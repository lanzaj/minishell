/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_child.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 21:07:08 by jlanza            #+#    #+#             */
/*   Updated: 2023/03/08 19:35:30 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	handle_sigint_child(int sig)
{
	exit (130);
	(void)sig;
}

static void	handle_sigquit_child(int sig)
{
	exit (131);
	(void)sig;
}

void	init_signal_child(void)
{
	signal(SIGINT, &handle_sigint_child);
	signal(SIGQUIT, &handle_sigquit_child);
}
