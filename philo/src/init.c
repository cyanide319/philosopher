/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:53:51 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/11/28 14:40:15 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

time_t	init_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	init_philo(t_rules *rules)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	rules->philo = malloc(sizeof(t_philo) * (rules->nb_philo));
	rules->mute_forks = malloc(sizeof(t_philo) * (rules->nb_philo));
	if (!rules->philo || !rules->mute_forks)
		error_quit(3, rules);
	while (i < rules->nb_philo)
	{
		rules->philo[i].id = j;
		rules->philo[i].forks.left = i;
		if (pthread_mutex_init(&rules->mute_forks[i], NULL) != 0)
			error_quit(4, rules);
		if (j == rules->nb_philo)
			rules->philo[i].forks.right = 0;
		else
			rules->philo[i].forks.right = j;
		i++;
		j++;
	}
}

void	init_rules(t_rules	*rules, int argc, char **argv)
{
	rules->nb_philo = ft_atol(argv[1]);
	rules->tm_to_die = ft_atol(argv[2]);
	rules->tm_to_eat = ft_atol(argv[3]);
	rules->tm_to_sleep = ft_atol(argv[4]);
	if (argc == 6)
		rules->nb_of_eat = ft_atol(argv[5]);
	else
		rules->nb_of_eat = INT_MAX;
	rules->start_time = init_time();
	init_philo(rules);
}
