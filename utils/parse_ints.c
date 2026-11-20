/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ints.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdeglos <thdeglos@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 16:42:15 by tcloix            #+#    #+#             */
/*   Updated: 2026/11/13 20:21:33 by thdeglos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	parse_digits(const char *s, long long limit, long long *value)
{
	int	digit;

	*value = 0;
	while (*s)
	{
		digit = *s - '0';
		if (digit < 0 || digit > 9)
			return (0);
		if (*value > (limit - digit) / 10)
			return (0);
		*value = *value * 10 + digit;
		s++;
	}
	return (1);
}

int	parse_int(const char *s, int *result)
{
	long long	value;
	long long	limit;
	int			negative;

	if (s == NULL || result == NULL || *s == '\0')
		return (0);
	negative = (*s == '-');
	if (*s == '-' || *s == '+')
		s++;
	if (*s == '\0')
		return (0);
	limit = 2147483647;
	if (negative)
		limit++;
	if (!parse_digits(s, limit, &value))
		return (0);
	if (negative)
		value = -value;
	*result = (int) value;
	return (1);
}
