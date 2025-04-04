/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athekkan <athekkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:39:15 by athekkan          #+#    #+#             */
/*   Updated: 2023/11/21 18:40:01 by athekkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	string_lenght(int n)
{
	long int	num;
	int			len;

	num = n;
	len = 1;
	if (num < 0)
	{
		len++;
		num = -num;
	}
	while (num >= 10)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	num;
	long int	len;

	len = string_lenght(n);
	num = n;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	if (num < 0)
	{
		num = -num;
		*str = '-';
	}
	str[len] = '\0';
	len--;
	while (num >= 10)
	{
		str[len] = 48 + (num % 10);
		num /= 10;
		len--;
	}
	if (num >= 0 && num < 10)
		str[len] = 48 + (num % 10);
	return (str);
}
