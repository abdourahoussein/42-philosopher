/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhousse <abhousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 03:43:58 by abhousse          #+#    #+#             */
/*   Updated: 2022/11/15 00:43:56 by abhousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_time(void)
{
	int				ret;
	struct timeval	tps;

	ret = 0;
	gettimeofday(&tps, NULL);
	ret = (tps.tv_sec * 1000) + (tps.tv_usec / 1000);
	return (ret);
}

void	ft_usleep(int ms)
{
	int	debut;

	debut = get_time();
	while ((get_time() - debut) < ms)
		usleep(50);
}
