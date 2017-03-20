/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgolban <mgolban@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 14:49:32 by mgolban           #+#    #+#             */
/*   Updated: 2016/10/26 14:55:00 by mgolban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	a;
	size_t	b;
	size_t	i;

	if (s == NULL)
		return (0);
	a = 0;
	while (s[a] == ' ' || s[a] == ',' || s[a] == '\n' || s[a] == '\t')
		a++;
	if (s[a] == '\0')
		return (ft_strdup("\0"));
	b = ft_strlen(s) - 1;
	while (s[b] == ' ' || s[b] == ',' || s[b] == '\n' || s[b] == '\t')
		b--;
	str = (char *)malloc(sizeof(char) * (b - a + 2));
	if (str)
	{
		i = 0;
		while (a <= b)
			str[i++] = s[a++];
		str[i] = '\0';
	}
	return (str);
}
