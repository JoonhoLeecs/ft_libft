/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joonhlee <joonhlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:14:23 by joonhlee          #+#    #+#             */
/*   Updated: 2023/03/16 15:04:42 by joonhlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_word(char c_tocheck, char c);
static int	count_word(const char *s, char c);
static void	split_exec(const char *s, char **split_s, char c, int len);
static int	ft_cpy_word(const char *s, int *mark, char **split_s, int word_ind);

char	**ft_split(char const *s, char c)
{
	size_t	len_s;
	int		num_word;
	char	**split_s;

	len_s = ft_strlen(s);
	num_word = count_word(s, c);
	split_s = (char **)malloc((num_word + 1) * sizeof(char *));
	if (split_s == 0)
		return ((char **)0);
	split_exec(s, split_s, c, len_s);
	return (split_s);
}

static int	is_word(char c_tocheck, char c)
{
	int	i;

	i = 0;
	if (c_tocheck == '\0')
		return (0);
	if (c_tocheck == c)
		return (0);
	return (1);
}

static int	count_word(const char *s, char c)
{
	int	i;
	int	wordcheck;
	int	num_word;

	i = 0;
	wordcheck = 0;
	num_word = 0;
	while (s[i])
	{
		if (is_word(s[i], c) - wordcheck == 1)
			num_word += 1;
		wordcheck = is_word(s[i], c);
		i++;
	}
	return (num_word);
}

static void	split_exec(const char *s, char **split_s, char c, int len)
{
	int	s_ind;
	int	wordcheck;
	int	word_ind;
	int	mark[2];

	s_ind = 0;
	wordcheck = 0;
	word_ind = 0;
	while (s_ind <= len)
	{
		if (is_word(s[s_ind], c) - wordcheck == 1)
			mark[0] = s_ind;
		if (is_word(s[s_ind], c) - wordcheck == -1)
		{
			mark[1] = s_ind;
			if (ft_cpy_word(s, mark, split_s, word_ind))
				return ;
			word_ind += 1;
		}
		wordcheck = is_word(s[s_ind++], c);
	}
	split_s[word_ind] = 0;
	return ;
}

static int	ft_cpy_word(const char *s, int *mark, char **split_s, int word_ind)
{
	int	i;

	i = 0;
	split_s[word_ind] = (char *)malloc(mark[1] - mark[0] + 1);
	if (split_s[word_ind] == 0)
		return (1);
	while (mark[0] + i < mark[1])
	{
		split_s[word_ind][i] = s[mark[0] + i];
		i++;
	}
	split_s[word_ind][i] = '\0';
	return (0);
}
