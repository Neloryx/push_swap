/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_itoa.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: tcloix <tcloix@student42lehavre.fr>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/15 16:10:40 by tcloix           #+#    #+#              */
/*   Updated: 2026/10/19 12:32:16 by tcloix          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>
// #include <stdlib.h>

static int	numberlen(long long nbr)
{
	long	count;

	count = !nbr;
	if (nbr < 0)
	{
		count++;
		nbr = -nbr;
	}
	while (nbr)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	nbr;
	char	*res;
	int		count;

	nbr = n;
	count = numberlen(nbr);
	res = malloc(count + 1);
	if (res == NULL)
		return (NULL);
	res[count] = '\0';
	count--;
	if (nbr < 0)
	{
		*res = '-';
		nbr = -nbr;
	}
	if (nbr == 0)
		res[count--] = '0';
	while (nbr)
	{
		res[count--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (res);
}

// int	main(void)
// {
// 	printf("%s\n", ft_itoa(0));
// 	printf("%s\n", ft_itoa(100));
// 	printf("%s\n", ft_itoa(-100));
// }
