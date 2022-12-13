/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:57:50 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/12/13 17:39:11 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_bool	print_output(t_rules *rules, int i, char *str)
{
	pthread_mutex_lock(&rules->mute_write);
	pthread_mutex_lock(&rules->mute_death);
	if (rules->dth_flag == true)
	{
		pthread_mutex_unlock(&rules->mute_write);
		pthread_mutex_unlock(&rules->mute_death);
		return (false);
	}
	pthread_mutex_unlock(&rules->mute_death);
	pthread_mutex_lock(&rules->mute_time);
	printf("%ld %d %s\n", (init_time() - rules->start_time),
		rules->philo[i].id, str);
	pthread_mutex_unlock(&rules->mute_time);
	pthread_mutex_unlock(&rules->mute_write);
	return (true);
}

t_bool	eat(t_rules *rules, int i)
{
	pthread_mutex_lock(&rules->mute_forks[rules->philo[i].forks.left]);
	if (print_output(rules, i, LF) == false)
		return (false);
	pthread_mutex_lock(&rules->mute_forks[rules->philo[i].forks.right]);
	if (print_output(rules, i, RF) == false)
		return (false);
	pthread_mutex_lock(&rules->mute_time);
	rules->philo[i].last_eat = init_time() - rules->start_time;
	rules->philo[i].nb_eat++;
	pthread_mutex_unlock(&rules->mute_time);
	if (print_output(rules, i, EAT) == false)
		return (false);
	init_wait_time(rules, rules->tm_to_eat);
	pthread_mutex_unlock(&rules->mute_forks[rules->philo[i].forks.left]);
	pthread_mutex_unlock(&rules->mute_forks[rules->philo[i].forks.right]);
	return (true);
}

t_bool	fucking_sleep(t_rules *rules, int i)
{
	if (print_output(rules, i, SLP) == false)
		return (false);
	init_wait_time(rules, rules->tm_to_sleep);
	return (true);
}

t_bool	think(t_rules *rules, int i)
{
	if (print_output(rules, i, THK) == false)
		return (false);
	return (true);
}
