/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhousse <abhousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 03:00:19 by abhousse          #+#    #+#             */
/*   Updated: 2022/11/15 06:04:30 by abhousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*verif(void *arg)
{
	t_philo	*philoso;

	philoso = (t_philo *)arg;
	while (1)
	{
		if (get_time() - philoso->dern_rep > philoso->info->t_mort)
		{
			philoso->info->continu = 0;
			printf ("%d %d is dead\n", get_time()
				- philoso->info->temps_d, philoso->id);
			break ;
		}
		if (philoso->info->i == philoso->info->nbr_philos)
		{
			philoso->info->continu = 0;
			break ;
		}
		if (philoso->id == philoso->info->nbr_philos)
			philoso = philoso->info->premier;
		else
			philoso++;
	}
	return (NULL);
}

void	*action_(void *arg)
{
	t_philo	*philoso;

	philoso = (t_philo *)arg;
	if (!(philoso->id % 2))
		usleep(500);
	while (philoso->info->continu)
		routine(philoso);
	return (NULL);
}

void	init(t_info	*info)
{
	info->temps_d = get_time();
	info->continu = 1;
	info->i = 0;
}

static	int	creation(t_info *info, t_philo	*philoso)
{
	int		i;

	i = 0;
	philoso = malloc(sizeof(t_philo) * info->nbr_philos);
	if (philoso == 0)
		return (0);
	init(info);
	while (i < info->nbr_philos)
	{
		philoso->info = info;
		philoso->n_mange = 0;
		philoso->dern_rep = get_time();
		if (i == 0)
			philoso->info->premier = philoso;
		philoso->id = i + 1;
		pthread_create(&philoso->philo, NULL, &action_, philoso);
		pthread_mutex_init(&philoso->fourchette, NULL);
		i++;
		philoso++;
	}
	pthread_create(&info->verif, NULL, &verif, info->premier);
	while (info->continu)
		;
	detruire(info);
	return (0);
}

int	main(int ac, char **av)
{
	int		i;
	t_info	*info;
	t_philo	*philoso;

	i = 0;
	philoso = NULL;
	info = malloc(sizeof(t_info));
	if (!(info))
		return (1);
	if (verif_arg(ac, av) == 1)
		return (free(info), 1);
	ft_info(info, ac, av);
	if (creation(info, philoso) == 0)
		return (free(info), free(philoso), 0);
	return (0);
}
