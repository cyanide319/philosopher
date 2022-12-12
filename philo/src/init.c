/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:53:51 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/12/12 14:47:28 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_thread(t_rules *rules)
{
	int	i;

	i = -1;
	while (++i < rules->nb_philo)
	{
		rules->nb_t = i;
		pthread_create(&rules->philo[i].p_t, NULL, routine, (void *)rules);
		usleep(100);
	}
	if (rules->eat_flag == true)
		pthread_create(&rules->weight_watcher, NULL, feasting, (void *)rules);
	pthread_create(&rules->death_watch, NULL, reaping, (void *)rules);
	close_threads(rules);
}

time_t	init_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	init_wait_time(t_rules *rules, int wait)
{
	time_t	time;

	time = init_time() + wait - rules->start_time;
	while ((init_time() - rules->start_time) < time)
		usleep(50);
}

void	init_philo(t_rules *rules)
{
	int	i;
	int	j;

	i = -1;
	j = 1;
	while (++i < rules->nb_philo)
	{
		rules->philo[i].rules = rules;
		rules->philo[i].id = j;
		rules->philo[i].forks.left = i;
		if (pthread_mutex_init(&rules->mute_forks[i], NULL) != 0)
			error_quit(4, rules);
		if (j == rules->nb_philo)
			rules->philo[i].forks.right = 0;
		else
			rules->philo[i].forks.right = j;
		rules->philo[i].nb_eat = -1;
		rules->philo[i].last_eat = 0;
		j++;
	}
	init_thread(rules);
}

void	init_rules(t_rules	*rules, int argc, char **argv)
{
	rules->dth_flag = false;
	rules->nb_philo = ft_atol(argv[1]);
	rules->tm_to_die = ft_atol(argv[2]);
	rules->tm_to_eat = ft_atol(argv[3]);
	rules->tm_to_sleep = ft_atol(argv[4]);
	if (argc == 6)
	{
		rules->nb_of_eat = ft_atol(argv[5]);
		rules->eat_flag = true;
	}
	else
	{
		rules->nb_of_eat = INT_MAX;
		rules->eat_flag = false;
	}
	rules->start_time = init_time();
	if (pthread_mutex_init(&rules->mute_write, NULL) != 0)
		error_quit(4, rules);
	if (pthread_mutex_init(&rules->mute_death, NULL) != 0)
		error_quit(4, rules);
	init_philo(rules);
}
