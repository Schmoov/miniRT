/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:00:29 by hsoysal           #+#    #+#             */
/*   Updated: 2025/04/16 19:01:41 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_structs.h"
#include <stdbool.h>
#include <stdlib.h>

enum
{
	BASE = 10
};

bool	ft_isspace(char character)
{
	return (character == ' ' || character == '\t' || character == '\n'
		|| character == '\r' || character == '\v' || character == '\f');
}

bool	ft_isdigit(char character)
{
	return (character >= '0' && character <= '9');
}

char	*skip_whitespace(char *str)
{
	#pragma unroll
	while (ft_isspace(*str))
		str++;
	return (str);
}

unsigned long	custom_str_to_int(const char *str, char **endptr)
{
	unsigned long	result;
	int				digit;

	result = 0;
	str = skip_whitespace((char *)str);
	while (*str)
	{
		if (ft_isdigit(*str))
			digit = *str - '0';
		else
			break ;
		result = result * BASE + digit;
		str++;
	}
	if (endptr)
		*endptr = (char *)str;
	return (result);
}

float	custom_strof(const char *str, char **endptr)
{
	float	result;
	float	fraction;
	int		divisor;
	int		sign;

	result = 0.0F;
	fraction = 0.0F;
	divisor = 1;
	sign = 1;
	str = skip_whitespace((char *)str);
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
	{
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = result * BASE + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		str++;
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

char	*parse_int(char *str, unsigned int *value)
{
	*value = custom_str_to_int(str, &str);
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

char	*parse_rgb(char *str, t_RGB *color)
{
	str = parse_int(str, &color->r);
	if (*str++ != ',')
		return (NULL);
	str = parse_int(str, &color->g);
	if (*str++ != ',')
		return (NULL);
	str = parse_int(str, &color->b);
	return (skip_whitespace(str));
}
