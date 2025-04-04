/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:38:33 by athekkan          #+#    #+#             */
/*   Updated: 2023/11/21 18:40:59 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *res, char *temp)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!res)
	{
		res = (char *)malloc(1 * sizeof(char));
		res[0] = '\0';
	}
	if (!res || !temp)
		return (NULL);
	j = 0;
	i = -1;
	str = malloc((ft_strlen(res) + ft_strlen(temp) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (res[++i])
		str[i] = res[i];
	while (temp[j])
		str[i++] = temp[j++];
	str[i] = '\0';
	free(res);
	return (str);
}
