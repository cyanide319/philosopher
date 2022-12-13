/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:53:55 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/12/12 19:31:21 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*reaping(void *arg)
{
	t_rules	*rules;
	int		i;

	rules = (t_rules *)arg;
	i = 0;
	while (rules->dth_flag == false)
	{
		if ((init_time() - rules->start_time) - rules->philo[i].last_eat
			> rules->tm_to_die && rules->dth_flag == false)
		{
			rules->dth_flag = true;
			pthread_mutex_lock(&rules->mute_write);
			printf("%ld %d is dead\n", (init_time() - rules->start_time),
				rules->philo[i].id);
			pthread_mutex_unlock(&rules->mute_write);
		}
		i = (i + 1) % rules->nb_philo;
	}
	close_threads(rules);
	return (0);
}

void	*feasting(void *arg)
{
	t_rules	*rules;
	int		i;
	int		j;

	rules = (t_rules *)arg;
	i = 0;
	j = 0;
	while (rules->dth_flag == false)
	{
		if (rules->philo[i].nb_eat == rules->nb_of_eat)
			j++;
		if (j == rules->nb_philo && rules->dth_flag == false)
		{
			pthread_mutex_lock(&rules->mute_write);
			rules->dth_flag = true;
			printf("They all ate and thought happily ever after\n");
			pthread_mutex_unlock(&rules->mute_write);
			break ;
		}
		i = (i + 1) % rules->nb_philo;
	}
	close_threads(rules);
	return (0);
}

void	*routine(void *arg)
{
	t_rules	*rules;
	int		i;

	rules = (t_rules *)arg;
	i = rules->nb_t;
	while (rules->dth_flag == false)
	{
		if (rules->dth_flag == false)
			if (eat(rules, i) == false)
				break ;
		if (rules->dth_flag == false)
			if (fucking_sleep(rules, i) == false)
				break ;
		if (rules->dth_flag == false)
			if (think(rules, i) == false)
				break ;
	}
	close_threads(rules);
	return (0);
}
