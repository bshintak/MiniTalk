/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshintak <bshintak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:21:44 by bshintak          #+#    #+#             */
/*   Updated: 2022/06/24 10:35:12 by bshintak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "./Printf/ft_printf.h"
# include "./Libft/libft.h"
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

typedef struct s_signal
{
	int	client;
	int	server;
}				t_signal;

#endif
