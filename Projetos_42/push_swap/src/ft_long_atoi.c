/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_long_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasmar < lucasmar@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:51:04 by lucasmar          #+#    #+#             */
/*   Updated: 2022/07/09 18:22:04 by lucasmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../includes/push_swap.h>

static int	ft_space(char c);

long	ft_long_atoi(const char *str)
{
	long	a;
	long	r;
	long	c;

	c = 1;
	a = 0;
	r = 0;
	while (ft_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			c = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		r = (r * 10) + ((*str++) - '0');
		a++;
	}
	return (r * c);
}

static int	ft_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}
