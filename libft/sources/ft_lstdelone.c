/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lararamirez <lararamirez@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 19:40:16 by lramirez          #+#    #+#             */
/*   Updated: 2017/09/25 18:06:11 by lararamirez      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	del((*alst)->data, (*alst)->data_size);
	free(*alst);
	*alst = NULL;
}
