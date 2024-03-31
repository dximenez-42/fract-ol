/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:59:00 by dximenez          #+#    #+#             */
/*   Updated: 2024/01/26 15:12:38 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*allocate_word(const char *s, size_t end)
{
	char	*mem;

	mem = ft_calloc((end + 1), sizeof(char));
	if (mem == 0)
		return (0);
	ft_strlcpy(mem, s, end + 1);
	return (mem);
}

char	**free_all(char	**mem, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free((void *)mem[i]);
		++i;
	}
	free(mem);
	return (0);
}

size_t	count_words(char const *s, char del)
{
	size_t	c;
	size_t	flag;

	c = 0;
	flag = 0;
	if (s == 0)
		return (0);
	while (*s != '\0')
	{
		if (*s == del)
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			++c;
		}
		++s;
	}
	return (c);
}

size_t	word_size(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		++i;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**mem;
	size_t	size;
	size_t	i;

	if (s == 0)
		return (0);
	mem = ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (mem == 0)
		return (0);
	i = 0;
	while (count_words(s, c) > 0)
	{
		while (*s == c)
			++s;
		size = word_size(s, c);
		mem[i] = allocate_word(s, size);
		if (mem[i] == 0)
			return (free_all(mem, count_words(s, c) + i));
		s = ft_strchr(s, (int)c);
		++i;
	}
	return (mem);
}

// int	main(void)
// {
// 	char *str = "HOLA QUE TAL ESTAS";
// 	char sep = ' ';
// 	char **s = ft_split(str, sep);
// }

// int	main(void)
// {
// 	char *str = "0 0 0 0 0 0 0 0 0";
// 	char sep = ' ';
// 	char **s = ft_split(str, sep);
// }

// int	main(void)
// {
// 	char *str = "      split       this for   me  !       ";
// 	char sep = ' ';
// 	char **s = ft_split(str, sep);
// }

// int	main(void)
// {
// 	char *str = "lorem ipsum dolor sit amet, consectetur adipiscing elit.";
// 	char sep = ' ';
// 	char **s = ft_split(str, sep);
// }

// int	main(void)
// {
// 	char *str = "hello!";
// 	char sep = ' ';
// 	char **s = ft_split(str, sep);
// }