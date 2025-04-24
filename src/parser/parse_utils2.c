/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsoysal <hsoysal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 20:45:04 by hsoysal           #+#    #+#             */
/*   Updated: 2025/04/18 03:32:13 by hsoysal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "parser_utils.h"
#include "scene_structs.h"
#include <stddef.h>

char	*skip_whitespace(char *str)
{
	if (!str)
		return (NULL);
	while (ft_isspace(*str))
		str++;
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
		result = result * BASE + digit;
		str++;
	}
	if (endptr)
		*endptr = (char *)str;
	return (result);
}

char	*parse_uint(char *str, unsigned int *value)
{
	*value = str_to_u_int(str, &str);
	return (skip_whitespace(str));
}

char	*parse_rgb(char *str, t_RGB *color)
{
	str = parse_uint(str, &color->r);
	if (!str || *str++ != ',')
		return (NULL);
	str = parse_uint(str, &color->g);
	if (!str || *str++ != ',')
		return (NULL);
	str = parse_uint(str, &color->b);
	return (skip_whitespace(str));
}
