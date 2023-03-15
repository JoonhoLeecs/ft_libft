/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:45:39 by joonhlee          #+#    #+#             */
/*   Updated: 2023/03/14 19:27:06 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*buffer;
	int				i;
	unsigned char	*ptr_src;
	unsigned char	*ptr_dst;

	buffer = (unsigned char *) malloc (len);
	if (buffer == NULL)
		return (dst);
	i = 0;
	ptr_src = src;
	ptr_dst = dst;
	while (i < len)
	{
		*(buffer + i) = *(ptr_src + i);
		i++;
	}
	while (i < len)
	{
		*(ptr_dst + i) = *(buffer + i);
		i++;
	}
	free(buffer);
	return ((void *)ptr_dst);
}
