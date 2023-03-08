/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:50:05 by mbocquel          #+#    #+#             */
/*   Updated: 2023/03/08 11:32:29 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

char	*get_word(t_param *prm)
{
	t_token	peek;
	char	*token;

	peek = peek_tk(prm);
	if (!(peek == TK_WORD || peek == TK_SQUOTE || peek == TK_WORD_SUB
			|| peek == TK_DQUOTE))
		return (NULL);
	token = get_token(prm);
	if (get_t_token(token) == TK_WORD)
		return (token);
	if (get_t_token(token) == TK_WORD_SUB)
		return (substitute_word(prm, token));
	if (get_t_token(token) == TK_SQUOTE)
		return (get_word_squote(prm));
	if (get_t_token(token) == TK_DQUOTE)
		return (get_word_dquote(prm, TRUE));
	return (NULL);
}

char	*get_word_squote(t_param *prm)
{
	char	*word;
	size_t	pos_start;

	word = NULL;
	pos_start = prm->source.cur;
	while (peek_tk(prm) != TK_SQUOTE && peek_tk(prm) != TK_EOF)
		get_token(prm);
	if (peek_tk(prm) == TK_EOF)
	{
		prm->source.error = ERR_SQUOTE_CLOSE;
		return (NULL);
	}
	if (peek_tk(prm) == TK_SQUOTE)
		get_token(prm);
	word = ft_substr_gc(prm, prm->source.line, pos_start,
			prm->source.cur - pos_start - 1);
	return (word);
}

char	*get_word_dquote(t_param *prm, t_bool sub)
{
	char	*word;

	word = NULL;
	while (!(peek_tk(prm) == TK_DQUOTE || peek_tk(prm) == TK_EOF))
	{
		word = ft_strjoin_gc(prm, prm->source.id, word, get_space(prm));
		if (peek_tk(prm) == TK_WORD_SUB && sub == TRUE)
			word = ft_strjoin_gc(prm, prm->source.id, word,
					substitute_word(prm, get_token(prm)));
		else
			word = ft_strjoin_gc(prm, prm->source.id, word, get_token(prm));
	}
	if (peek_tk(prm) == TK_EOF)
	{
		prm->source.cur = ERR_DQUOTE_CLOSE;
		return (NULL);
	}
	word = ft_strjoin_gc(prm, prm->source.id, word, get_space(prm));
	get_token(prm);
	return (word);
}

char	*get_endheredoc(t_param *prm)
{
	char	*token;

	token = get_token(prm);
	if (get_t_token(token) == TK_SQUOTE)
		return (get_word_squote(prm));
	if (get_t_token(token) == TK_DQUOTE)
		return (get_word_dquote(prm, FALSE));
	if (get_t_token(token) == TK_WORD || get_t_token(token) == TK_WORD_SUB)
		return (token);
	else
	{
		prm->source.error = ERR_PARSING;
		return (NULL);
	}
}