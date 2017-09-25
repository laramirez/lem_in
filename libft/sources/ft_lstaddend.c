/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 15:27:24 by lararamirez       #+#    #+#             */
/*   Updated: 2017/09/15 15:37:38 by lararamirez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstaddend(t_list **alst, t_list *new)
{
	t_list	*tmp;

    tmp = *alst;
    if (!tmp)
        *alst = new;
    else
    {
        while (tmp->next)
          tmp = tmp->next;
        tmp->next = new;
    }
    new->next = NULL;
}
