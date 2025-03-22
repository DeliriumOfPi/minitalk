/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msottana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:23:39 by msottana          #+#    #+#             */
/*   Updated: 2024/09/16 09:44:19 by msottana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	char_in_set(int c, char const *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

static int	ft_isspace(int c)
{
	return (char_in_set(c, " \f\n\r\t\v"));
}

static int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	result;

	if (!nptr)
		return (0);
	while (ft_isspace(*nptr))
		nptr++;
	sign = 1;
	if (*nptr == '+' || *nptr == '-')
		sign *= (*nptr++ == '+') * 2 - 1;
	result = 0;
	while (ft_isdigit(*nptr))
		result = result * 10 + *nptr++ - '0';
	return (sign * result);
}
