/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sforster <sforster@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 10:22:35 by sforster          #+#    #+#             */
/*   Updated: 2023/11/29 11:22:19 by sforster         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}
/*

fonctionne pas...
int main(void)
{
	t_list	*root;
	t_list	*lastlist;
	char	*last_node;
	
	root = malloc(sizeof(t_list));
	root->next = malloc(sizeof(t_list));
	root->next->next = malloc(sizeof(t_list));
	root->next->next->next = malloc(sizeof(t_list));

	root->content = "23";
	root->next->content = "34";
	root->next->next->content = "454";
	root->next->next->next->content = NULL;

	lastlist = ft_lstlast(root);
	last_node = ft_strdup((char *)lastlist->content);
	
*/