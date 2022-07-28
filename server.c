/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:36:06 by bshintak          #+#    #+#             */
/*   Updated: 2022/06/24 12:10:42 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	verif_signal(int num)
{
	static int	power;
	static int	byte;

	if (num == SIGUSR1)
		byte += 1 << (7 - power);
	power++;
	if (power == 8)
	{
		ft_printf("%c", byte);
		power = 0;
		byte = 0;
	}
}

int	main(void)
{
	ft_printf("Server PID: %d\n", getpid());
	signal(SIGUSR1, verif_signal);
	signal(SIGUSR2, verif_signal);
	while (1)
		pause();
}
