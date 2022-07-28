/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:36:10 by bshintak          #+#    #+#             */
/*   Updated: 2022/07/28 10:35:57 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	checker_number(char *pid)
{
	int	i;

	i = 0;
	while (pid[i])
	{
		if ((pid[i] < '0' || pid[i] > '9'))
			return (1);
		i++;
	}
	return (0);
}

void	send_msg(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c >> i & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_printf("\e[31mError\n\e[0mWrong pid 🥺\n");
				exit (0);
			}
		}
		else if (kill(pid, SIGUSR2) == -1)
		{
			ft_printf("\e[31mError\n\e[0mWrong pid 🥺\n");
			exit (0);
		}
		usleep(100);
		i--;
	}
}

int	main(int argc, char **argv)
{
	int			pid;
	char		*message;
	int			i;

	i = 0;
	if (argc != 3)
	{
		ft_printf("\e[31mError\n\e[0mWrong number of arguments 🥺\n");
		return (0);
	}
	if (checker_number(argv[1]) == 1)
	{
		ft_printf("\e[31mError\n\e[0mWrong pid 🥺\n");
		return (0);
	}
	if (argc == 3)
	{
		pid = ft_atoi_libft(argv[1]);
		message = argv[2];
		while (message[i])
			send_msg(pid, message[i++]);
		send_msg(pid, message[i]);
	}
	return (0);
}
