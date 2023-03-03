/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_gc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:48:31 by mbocquel          #+#    #+#             */
/*   Updated: 2023/03/03 12:18:58 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

void	*ft_malloc_gc(t_param *prm, int id, size_t size)
{
	void	*result;

	result = malloc(size);
	if (result == NULL)
		return (NULL);
	if (garbage_col(prm, id, result))
		return (NULL);
	return (result);
}

void	*ft_calloc_gc(t_param *prm, int id, size_t nmemb, size_t size)
{
	void	*result;

	result = ft_calloc(nmemb, size);
	if (result == NULL)
		return (NULL);
	if (garbage_col(prm, id, result))
		return (NULL);
	return (result);
}

char	*ft_substr_gc(t_param *prm, char *s, unsigned int start, size_t len)
{
	char	*result_str;
	size_t	i;
	size_t	len_max;

	len_max = len;
	if (ft_strlen(s) - start < len_max && start <= ft_strlen(s))
	{
		len_max = ft_strlen(s) - start;
	}
	else if (start > ft_strlen(s))
		len_max = 0;
	result_str = (char *)ft_calloc_gc(prm, prm->source.id,
			(len_max + 1), sizeof(char));
	if (result_str == NULL)
		return (NULL);
	i = 0;
	while (i < len_max)
	{
		result_str[i] = s[(size_t)start + i];
		i++;
	}
	result_str[i] = '\0';
	return (result_str);
}

char	*ft_strdup_gc(t_param *prm, const char *s)
{
	char	*dest;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[len])
		len++;
	dest = (char *)ft_malloc_gc(prm, prm->source.id, (len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}