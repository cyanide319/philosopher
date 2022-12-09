/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:53:55 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/12/09 18:24:30 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	reaping(t_rules	*rules)
{
	// t_rules	*rules;
	int		i;

	// rules = (t_rules *)arg;
	i = 0;
	while (1)
	{
		feasting (rules);
		if (rules->dth_flag == true)
			break ;
		else if ((init_time() - rules->start_time) - rules->philo[i].last_eat
			> rules->tm_to_die)
		{
			rules->dth_flag = true;
			print_output(rules, i, DTH);
			break ;
		}
		i = (i + 1) % rules->nb_philo;
	}
}

t_bool	feasting(t_rules	*rules)
{
	// t_rules	*rules;
	int		i;
	int		j;

	// rules = (t_rules *)arg;
	i = 0;
	j = 0;
	while (i <= rules->nb_philo)
	{
		if (rules->philo[i].nb_eat == rules->nb_of_eat)
			j++;
		if (j == rules->nb_philo)
		{
			pthread_mutex_lock(&rules->mute_write);
			rules->dth_flag = true;
			printf("They all ate and thought happily ever after\n");
			pthread_mutex_unlock(&rules->mute_write);
			return (true);
		}
		i++;
	}
	return (false);
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
			eat(rules, i);
		if (rules->dth_flag == false)
			fucking_sleep(rules, i);
		if (rules->dth_flag == false)
			think(rules, i);
	}
	return (0);
}

t_bool	eat(t_rules *rules, int i)
{
	pthread_mutex_lock(&rules->mute_forks[rules->philo[i].forks.left]);
	// if (rules->dth_flag == true)
	// 	return (false);
	if (print_output(rules, i, LF) == false && rules->dth_flag == false)
		return (false);
	pthread_mutex_lock(&rules->mute_forks[rules->philo[i].forks.right]);
	// if (rules->dth_flag == true)
	// 	return (false);
	if (print_output(rules, i, RF) == false && rules->dth_flag == false)
		return (false);
	rules->philo[i].last_eat = init_time() - rules->start_time;
	// if (rules->dth_flag == true)
	// 	return (false);
	if (print_output(rules, i, EAT) == false && rules->dth_flag == false)
		return (false);
	init_wait_time(rules, rules->tm_to_eat);
	pthread_mutex_unlock(&rules->mute_forks[rules->philo[i].forks.left]);
	pthread_mutex_unlock(&rules->mute_forks[rules->philo[i].forks.right]);
	rules->philo[i].nb_eat++;
	return (true);
}

t_bool	fucking_sleep(t_rules *rules, int i)
{
	// if (am_i_dead(rules, i) == true)
	// 	return (false);
	// if (rules->dth_flag == true)
	// 	return (false);
	if (print_output(rules, i, SLP) == false && rules->dth_flag == false)
		return (false);
	init_wait_time(rules, rules->tm_to_sleep);
	return (true);
}

t_bool	think(t_rules *rules, int i)
{
	// if (am_i_dead(rules, i) == true)
	// 	return (false);
	// if (rules->dth_flag == true)
	// 	return (false);
	if (print_output(rules, i, THK) == false && rules->dth_flag == false)
		return (false);
	return (true);
}

	// if (rules->philo[i].last_eat
	// 	- (init_time() - rules->start_time) > rules->tm_to_die)
	// 	return (false);