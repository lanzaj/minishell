/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_line_interface.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:30:50 by jlanza            #+#    #+#             */
/*   Updated: 2023/03/08 13:50:27 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	print_minishell_title(void)
{
	printf("\033[0;34m");
	printf("\n███╗   ███╗██╗███╗   ██╗██╗███████╗██╗  ██╗███████╗██╗     ██╗\n");
	printf("████╗ ████║██║████╗  ██║██║██╔════╝██║  ██║██╔════╝██║     ██║\n");
	printf("██╔████╔██║██║██╔██╗ ██║██║███████╗███████║█████╗  ██║     ██║\n");
	printf("██║╚██╔╝██║██║██║╚██╗██║██║╚════██║██╔══██║██╔══╝  ██║     ██║\n");
	printf("██║ ╚═╝ ██║██║██║ ╚████║██║███████║██║  ██║");
	printf("███████╗███████╗███████╗\n");
	printf("╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚══════╝╚═╝  ╚═╝");
	printf("╚══════╝╚══════╝╚══════╝\n");
	printf("----");
	printf("---------------------------------------------------------------\n\n");
	printf("\033[0m");
}

void	readline_new_prompt(char **cmd_buf)
{
	if (g_return_value == 0)
		*cmd_buf = readline("\033[1;32m➜  \033[0;33m\e[1mminishell$\e[0m \033[0m");
	else
		*cmd_buf = readline("\033[1;31m➜  \033[0;33m\e[1mminishell$\e[0m \033[0m");
}

void	printf_new_prompt(void)
{
	if (g_return_value == 0)
		ft_printf("\033[1;32m➜  \033[0;33m\e[1mminishell$\e[0m \033[0m");
	else
		ft_printf("\033[1;31m➜  \033[0;33m\e[1mminishell$\e[0m \033[0m");
}
