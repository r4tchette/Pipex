/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonkim <yeonkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 14:27:53 by yeonkim           #+#    #+#             */
/*   Updated: 2020/10/12 14:27:53 by yeonkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;

	if (!(*lst))
		return ;
	while (*lst)
	{
		ptr = *lst;
		*lst = (*lst)->next;
		del(ptr->content);
		free(ptr);
		ptr = NULL;
	}
}
