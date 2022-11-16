/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhousse <abhousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 03:00:41 by abhousse          #+#    #+#             */
/*   Updated: 2022/11/15 04:07:03 by abhousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		signe;
	int		resultat;

	i = 0;
	signe = 1;
	resultat = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\t' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-')
	{
		signe *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		resultat = resultat * 10 + (str[i] - 48);
		i++;
	}
	return (resultat * signe);
}

int	verif_arg(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	if (ac < 5 || ac > 6)
		return (printf("erreur : argument invalid"), 1);
	while (av[i])
	{
		if (!ft_atoi(av[i]))
			return (printf("erreur : argument invalid"), 1);
		j = -1;
		while (av[i][++j])
			if (av[i][j] < 48 || av[i][j] > 57)
				return (printf("erreur : argument invalid"), 1);
		i++;
	}
	return (0);
}

int	ft_info(t_info *info, int ac, char **av)
{
	info->nbr_philos = ft_atoi(av[1]);
	info->t_mort = ft_atoi(av[2]);
	info->t_mange = ft_atoi(av[3]);
	info->t_dort = ft_atoi(av[4]);
	if (ac == 6)
		info->nbr_must_eat = ft_atoi(av[5]);
	else
		info->nbr_must_eat = -1;
	return (0);
}
