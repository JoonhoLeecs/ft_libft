/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:41:36 by joonhlee          #+#    #+#             */
/*   Updated: 2023/03/17 11:15:15 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
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
		}
		i++;
	}
	if (has_c == 0)
		return ((char *)0);
	else
		return (result);
}
