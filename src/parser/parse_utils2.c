/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:45:04 by hsoysal           #+#    #+#             */
/*   Updated: 2025/06/15 15:40:26 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/miniRT.h"
#include <limits.h>

char	*skip_whitespace(char *str)
{
	if (!str)
		return (NULL);
	while (*str && *str != '#' && ft_isblank(*str))
		str++;
	if (*str == '#')
	{
		while (*str && *str != '\n')
			str++;
	}
	return (str);
}

unsigned long	str_to_u_int(const char *str, char **endptr)
{
	unsigned long	result;
	int				digit;

	result = 0;
	str = skip_whitespace((char *)str);
	if (!ft_isdigit(*str))
	{
		if (endptr)
			*endptr = NULL;
		return (0);
	}
	while (str && *str)
	{
		if (ft_isdigit(*str))
			digit = *str - '0';
		else
			break ;
		if (result > (ULONG_MAX - digit) / 10)
			break ;
		result = result * 10 + digit;
		str++;
	}
	if (endptr)
		*endptr = (char *)str;
	return (result);
}

char	*parse_uint(char *str, unsigned int *value)
{
	*value = str_to_u_int(str, &str);
	return (str);
}

char	*parse_rgb(char *str, t_RGB *color)
{
	str = skip_whitespace(str);
	str = parse_uint(str, &color->r);
	if (!str || *str++ != ',')
		return (NULL);
	str = parse_uint(str, &color->g);
	if (!str || *str++ != ',')
		return (NULL);
	str = parse_uint(str, &color->b);
	if (str == NULL || !ft_isblank(*str))
		return (NULL);
	return (str);
}

bool	char_is_blank(char *str)
{
	if (!str)
		return (false);
	return (ft_isblank(*str));
}
