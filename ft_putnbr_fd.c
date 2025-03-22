/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msottana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:27:57 by msottana          #+#    #+#             */
/*   Updated: 2024/11/18 21:23:40 by msottana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static ssize_t	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));

}

ssize_t	ft_putnbr_fd(int n, int fd)
{
	unsigned int	un;
	ssize_t			result;
	ssize_t			tmp_res;

	result = 0;
	if (n < 0)
	{
		result += ft_putchar_fd('-', fd);
		if (result < 0)
			return (-1);
		un = (unsigned int)(-n);
	}
	else
		un = (unsigned int)(n);
	if (un >= 10)
	{
		tmp_res = ft_putnbr_fd(un / 10, fd);
		if (tmp_res < 0)
			return (-1);
		result += tmp_res;
	}
	if (ft_putchar_fd((un % 10) + '0', fd) < 0)
		return (-1);
	return (result + 1);
}
