/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:00:29 by hsoysal           #+#    #+#             */
/*   Updated: 2025/06/22 19:22:32 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"

bool	ft_isblank(char character)
{
	return (character == ' ' || character == '\t' || character == '\n'
		|| character == '\r' || character == '\v' || character == '\f'
		|| character == '\0'
		|| character == '\b'
		|| character == '#');
}

int	custom_atoi(const char *str, char **endptr)
{
	int (result) = 0;
	int (sign) = 1;
	str = skip_whitespace((char *)str);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		if (result > (INT_MAX - (*str - '0')) / 10)
		{
			*endptr = NULL;
			return (0);
		}
		result = result * 10 + (*str - '0');
		str++;
	}
	if (endptr)
		*endptr = (char *)str;
	return (result * sign);
}

float	custom_strof(const char *str, char **endptr)
{
	float (fraction) = 0.0F;
	int (divisor) = 1;
	int (sign) = 1;
	if (*str == '-')
		sign = -1;
	str = skip_whitespace((char *)str);
	if (!ft_isdigit(*str) && *str != '-' && *str != '+' && *str != '.')
		return (*endptr = NULL, 0.0F);
	float (result) = (float)custom_atoi(str, (char **)&str);
	if (!str)
		return (*endptr = NULL, 0.0F);
	if (*str == '.')
	{
		str++;
		while (ft_isdigit(*str))
		{
			fraction = fraction * 10 + (*str - '0');
			divisor *= 10;
			str++;
		}
	}
	result += sign * (fraction / (float)divisor);
	if (endptr)
		*endptr = (char *)str;
	return (result);
}

char	*parse_float(char *str, float *value)
{
	*value = custom_strof(str, &str);
	return (str);
}

char	*parse_coord(char *str, t_coord *coord)
{
	str = parse_float(str, &coord->x);
	if (!str || *str != ',')
		return (NULL);
	str++;
	str = parse_float(str, &coord->y);
	if (!str || *str != ',')
		return (NULL);
	str++;
	str = parse_float(str, &coord->z);
	if (str && !ft_isblank(*str))
		return (NULL);
	return (skip_whitespace(str));
}
