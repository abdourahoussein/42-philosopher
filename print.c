/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhousse <abhousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 03:51:19 by abhousse          #+#    #+#             */
/*   Updated: 2022/11/15 06:07:22 by abhousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_p(t_philo	*philoso, char *str)
{
	printf ("%d %d is %s\n", get_time()
		- philoso->info->temps_d, philoso->id, str);
}

int	routine(t_philo	*philoso)
{
	pthread_mutex_lock(&philoso->fourchette);
	print_p(philoso, "has taken a fork");
	if (philoso->id == philoso->info->nbr_philos)
		pthread_mutex_lock(&philoso->info->premier->fourchette);
	else
		pthread_mutex_lock(&(philoso + 1)->fourchette);
	print_p(philoso, "has taken a fork");
	print_p(philoso, "is eating");
	philoso->dern_rep = get_time();
	ft_usleep(philoso->info->t_mange);
	philoso->n_mange++;
	if (philoso->n_mange == philoso->info->nbr_must_eat)
		philoso->info->i++;
	pthread_mutex_unlock(&philoso->fourchette);
	if (philoso->id == philoso->info->nbr_philos)
		pthread_mutex_unlock(&philoso->info->premier->fourchette);
	else
		pthread_mutex_unlock(&(philoso + 1)->fourchette);
	print_p(philoso, "is sleeping");
	ft_usleep(philoso->info->t_dort);
	print_p(philoso, "is thinking");
	return (0);
}

int	detruire(t_info	*info)
{
	int	i;

	i = 0;
	while (i < info->nbr_philos)
	{
		pthread_mutex_destroy(&info->premier->fourchette);
		i++;
		info->premier++;
	}
	return (0);
}
