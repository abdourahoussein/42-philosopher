/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhousse <abhousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 03:00:25 by abhousse          #+#    #+#             */
/*   Updated: 2022/11/15 06:04:49 by abhousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_info
{
	int				nbr_philos;
	int				nbr_must_eat;
	int				t_mort;
	int				t_dort;
	int				t_mange;
	int				i;
	int				temps_d;
	int				continu;
	pthread_t		verif;
	struct s_philo	*premier;
}					t_info;

typedef struct s_philo
{
	int					id;
	int					dern_rep;
	int					n_mange;
	t_info				*info;
	pthread_t			philo;
	pthread_mutex_t		fourchette;
}						t_philo;

// parsing
int		verif_arg(int ac, char **av);
int		ft_atoi(const char *str);
int		ft_info(t_info *info, int ac, char **av);

// temp fonctions

int		get_time(void);
void	ft_usleep(int ms);

// routine function

int		routine(t_philo	*philoso);
int		detruire(t_info	*info);

#endif
