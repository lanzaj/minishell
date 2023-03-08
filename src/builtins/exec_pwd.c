/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlanza <jlanza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 02:57:47 by jlanza            #+#    #+#             */
/*   Updated: 2023/03/08 19:14:34 by jlanza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int	exec_pwd(void)
{
	char	*working_directory;

	working_directory = getcwd(NULL, 0);
	if (working_directory == NULL)
	{
		ft_printf_fd(2, "minishell: pwd: %s\n", strerror(errno));
		return (1);
	}
	ft_printf("%s\n", working_directory);
	free(working_directory);
	return (0);
}
