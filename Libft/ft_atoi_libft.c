/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_libft.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:32:13 by bshintak          #+#    #+#             */
/*   Updated: 2022/05/24 13:51:33 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_libft(const char *str)
{
	long	num;
	int		sinal;
	int		i;

	sinal = 1;
	num = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sinal *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
		num = (num * 10) + (str[i++] - 48);
	return (sinal * (int)num);
}
