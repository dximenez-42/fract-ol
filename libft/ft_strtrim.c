/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dximenez <dximenez@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:16:39 by dximenez          #+#    #+#             */
/*   Updated: 2024/01/17 19:58:37 by dximenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_index(const char *s1, const char *set, int start)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = ft_strlen(s1);
	while (s1[i] != '\0')
	{
		if (start && ft_strchr(set, s1[i]) == 0)
			break ;
		else if (!start && ft_strchr(set, s1[size - i - 1]) == 0)
			break ;
		i++;
	}
	if (start)
		return (i);
	else
		return (size - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*mem;
	int		begin;
	int		end;

	if (s1 == 0)
		return (0);
	if (set == 0)
		return (ft_strdup(s1));
	begin = get_index(s1, set, 1);
	end = get_index(s1, set, 0);
	if (begin >= end)
		return (ft_strdup(""));
	mem = (char *)malloc(sizeof(char) * (end - begin + 1));
	if (mem == 0)
		return (0);
	ft_strlcpy(mem, s1 + begin, end - begin + 1);
	return (mem);
}

/*
int main()
{
	printf("%s\n", ft_strtrim("abcdef", "ba"));
	// printf("%d\n", ft_set_contains_c("ber", 'a'));
}
*/