/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:05:58 by joonhlee          #+#    #+#             */
/*   Updated: 2023/03/14 19:27:18 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptr_src;
	unsigned char	*ptr_dst;

	i = 0;
	ptr_src = src;
	ptr_dst = dst;
	while (i < n)
	{
		*(ptr_dst + i) = *(ptr_src + i);
		i++;
	}
	return ((void *)ptr_dst);
}
