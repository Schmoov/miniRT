/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:00:29 by hsoysal           #+#    #+#             */
/*   Updated: 2025/04/17 21:11:43 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "parser_utils.h"
#include "scene_structs.h"
#include <stdbool.h>
#include <stdlib.h>

bool	ft_isspace(char character)
{
	return (character == ' ' || character == '\t' || character == '\n'
		|| character == '\r' || character == '\v' || character == '\f');
}

int	custom_atoi(const char *str, char **endptr)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	str = skip_whitespace((char *)str);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = result * BASE + (*str - '0');
		str++;
	}
	if (endptr)
		*endptr = (char *)str;
	return (result * sign);
}

float	custom_strof(const char *str, char **endptr)
{
	float(result) = 0.0F;
	float(fraction) = 0.0F;
	int(divisor) = 1;
	int(sign) = 1;
	str = skip_whitespace((char *)str);
	result = (float)custom_atoi(str, (char **)&str);
	if (*str == '.' && str++)
	{
		while (ft_isdigit(*str))
		{
			fraction = fraction * BASE + (*str - '0');
			divisor *= BASE;
			str++;
		}
	}
	result += fraction / (float)divisor;
	result *= (float)sign;
	if (endptr)
		*endptr = (char *)str;
	return (result);
}

char	*parse_float(char *str, float *value)
{
	*value = custom_strof(str, &str);
	return (skip_whitespace(str));
}

char	*parse_coord(char *str, t_coord *coord)
{
	str = parse_float(str, &coord->x);
	if (*str++ != ',')
		return (NULL);
	str = parse_float(str, &coord->y);
	if (*str++ != ',')
		return (NULL);
	str = parse_float(str, &coord->z);
	return (skip_whitespace(str));
}
