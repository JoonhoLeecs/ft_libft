/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:48:28 by joonhlee          #+#    #+#             */
/*   Updated: 2023/03/16 13:15:39 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isset(char c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	int		s1_ind;
	int		count;
	char	*result;
	int		result_ind;

	s1_ind = 0;
	count = 0;
	while (s1[s1_ind])
		count += isset(s1[s1_ind++], set);
	result = (char *)malloc((s1_ind - count + 1) * sizeof(char));
	if (result == 0)
		return ((char *)0);
	s1_ind = 0;
	result_ind = 0;
	while (s1[s1_ind])
	{
		if (isset(s1[s1_ind], set) == 0)
			result[result_ind++] = s1[s1_ind];
		s1_ind++;
	}
	result[result_ind] = '\0';
	return (result);
}

static int	isset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}
