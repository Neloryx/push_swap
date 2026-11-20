/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_lstmap.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tcloix <tcloix@student42lehavre.fr>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/17 16:33:23 by tcloix           #+#    #+#              */
/*   Updated: 2026/10/20 13:23:25 by tcloix          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*final;
	t_list	*elem;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	final = NULL;
	while (lst)
	{
		content = f(lst->content);
		elem = ft_lstnew(content);
		if (!elem)
		{
			del(content);
			ft_lstclear(&final, del);
			return (NULL);
		}
		ft_lstadd_back(&final, elem);
		lst = lst->next;
	}
	return (final);
}
// #include "libft.h"
// #include <stdio.h>
// #include <stdlib.h>

// void *f(void *content)
// {
//     return (ft_strdup((char *)content));
// }

// void del(void *content)
// {
//     free(content);
// }

// int main(void)
// {
//     t_list *lst = ft_lstnew(ft_strdup("bonjour"));
//     t_list *new;

//     ft_lstadd_back(&lst, ft_lstnew(ft_strdup("le monde")));

//     new = ft_lstmap(lst, f, del);

//     while (new)
//     {
//         printf("%s\n", (char *)new->content);
//         new = new->next;
//     }
//     return (0);
// }
