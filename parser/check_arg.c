/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiacom <engiacom@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:32:01 by engiacom          #+#    #+#             */
/*   Updated: 2025/04/30 14:40:04 by engiacom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_quote(t_arg *arg)
{
	int	q;
	int	dq;

	q = 0;
	dq = 0;
	while (arg)
	{
		if (q == 0 && dq == 0 && arg->type == T_QUOTE)
			q = 1;
		else if (q == 0 && dq == 0 && arg->type == T_DQUOTE)
			dq = 1;
		else if (arg->type == T_QUOTE && q == 1)
			q = 0;
		else if (arg->type == T_DQUOTE && dq == 1)
			dq = 0;
		arg = arg->next;
	}
	return (q + dq);
}

int	check_pipe(t_arg *arg)
{
	int	p;

	p = 0;
	while (arg)
	{
		if (arg->type == T_PIPE)
			p = 1;
		if (arg->type == T_WORD && p == 1)
			p = 0;
		arg = arg->next;
	}
	return (p);
}