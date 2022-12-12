/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:57:50 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/12/09 20:47:28 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_bool	print_output(t_rules *rules, int i, char *str)
{
	pthread_mutex_lock(&rules->mute_write);
	if (rules->dth_flag == true)
	{
		pthread_mutex_unlock(&rules->mute_write);
		return (false);
	}
	printf("%ld %d %s\n", (init_time() - rules->start_time),
		rules->philo[i].id, str);
	pthread_mutex_unlock(&rules->mute_write);
	return (true);
}

t_bool	eat(t_rules *rules, int i)
{
	pthread_mutex_lock(&rules->mute_forks[rules->philo[i].forks.left]);
	if (rules->dth_flag == true)
		return (false);
	if (print_output(rules, i, LF) == false || rules->dth_flag == true)
		return (false);
	pthread_mutex_lock(&rules->mute_forks[rules->philo[i].forks.right]);
	if (rules->dth_flag == true)
		return (false);
	if (print_output(rules, i, RF) == false || rules->dth_flag == true)
		return (false);
	rules->philo[i].last_eat = init_time() - rules->start_time;
	if (rules->dth_flag == true)
		return (false);
	if (print_output(rules, i, EAT) == false || rules->dth_flag == true)
		return (false);
	init_wait_time(rules, rules->tm_to_eat);
	if (rules->dth_flag == true)
		return (false);
	pthread_mutex_unlock(&rules->mute_forks[rules->philo[i].forks.left]);
	pthread_mutex_unlock(&rules->mute_forks[rules->philo[i].forks.right]);
	rules->philo[i].nb_eat++;
	return (true);
}

t_bool	fucking_sleep(t_rules *rules, int i)
{
	if (rules->dth_flag == true)
		return (false);
	if (print_output(rules, i, SLP) == false || rules->dth_flag == true)
		return (false);
	init_wait_time(rules, rules->tm_to_sleep);
	if (rules->dth_flag == true)
		return (false);
	return (true);
}

t_bool	think(t_rules *rules, int i)
{
	if (rules->dth_flag == true)
		return (false);
	if (print_output(rules, i, THK) == false || rules->dth_flag == true)
		return (false);
	if (rules->dth_flag == true)
		return (false);
	return (true);
}
