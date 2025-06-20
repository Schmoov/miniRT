/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 11:32:44 by parden            #+#    #+#             */
/*   Updated: 2025/06/15 15:26:32 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

//Id rather have it crash on overflow 
static int	ft_seppuku(void)
{
	int	*katana;

	katana = NULL;
	return (*katana);
}

static bool	is_int(long long n)
{
	return (n <= INT_MAX && n >= INT_MIN);
}

static bool	ft_isblank(int c)
{
	return (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v');
}

int	ft_atoi(const char *nptr)
{
	long long	res;
	size_t		i;
	int			sign;

	res = 0;
	i = 0;
	sign = 1;
	while (ft_isblank(nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]) && is_int(sign * res))
	{
		res = 10 * res + nptr[i] - '0';
		i++;
	}
	res *= sign;
	if (!is_int(res))
		ft_seppuku();
	return (res);
}
