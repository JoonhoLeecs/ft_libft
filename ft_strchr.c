/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 16:56:26 by joonhlee          #+#    #+#             */
/*   Updated: 2023/03/15 17:37:58 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len;
	size_t	has_c;
	char	*result;

	i = 0;
	len = ft_strlen(s);
	has_c = 0;
	while ((i < len && c != 0) || (i <= len && c == 0))
	{
		if (s[i] == (char)c)
		{
			has_c = 1;
			result = (char *)(s + i);
			break ;
		}
		i++;
	}
	if (has_c == 0)
		return (NULL);
	else
		return (result);
}
