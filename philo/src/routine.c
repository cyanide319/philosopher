/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:53:55 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/12/09 20:44:31 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*reaping(void *arg)
{
	t_rules	*rules;
	int		i;

	rules = (t_rules *)arg;
	i = 0;
	while (1)
	{
		if (rules->dth_flag == true)
			break ;
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
	return (0);
}

// void	reaping(t_rules	*rules)
// {
// 	// t_rules	*rules;
// 	int		i;

// 	// rules = (t_rules *)arg;
// 	i = 0;
// 	while (1)
// 	{
// 		if (rules->dth_flag == true)
// 			break ;
// 		if ((init_time() - rules->start_time) - rules->philo[i].last_eat
// 			> rules->tm_to_die)
// 		{
// 			rules->dth_flag = true;
// 			pthread_mutex_lock(&rules->mute_write);
// 			printf("%ld %d is dead\n", (init_time() - rules->start_time),
// 				rules->philo[i].id);
// 			pthread_mutex_unlock(&rules->mute_write);
// 			break ;
// 		}
// 		i = (i + 1) % rules->nb_philo;
// 	}
// }

void	*feasting(void *arg)
{
	t_rules	*rules;
	int		i;
	int		j;

	rules = (t_rules *)arg;
	i = 0;
	j = 0;
	while (1)
	{
		if (rules->dth_flag == true)
			break ;
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
	return (0);
}

// t_bool	eat(t_rules *rules, int i)
// {
// 	pthread_mutex_lock(&rules->mute_forks[rules->philo[i].forks.left]);
// 	if (rules->dth_flag == true)
// 		return (false);
// 	if (print_output(rules, i, LF) == false || rules->dth_flag == true)
// 		return (false);
// 	pthread_mutex_lock(&rules->mute_forks[rules->philo[i].forks.right]);
// 	if (rules->dth_flag == true)
// 		return (false);
// 	if (print_output(rules, i, RF) == false || rules->dth_flag == true)
// 		return (false);
// 	rules->philo[i].last_eat = init_time() - rules->start_time;
// 	if (rules->dth_flag == true)
// 		return (false);
// 	if (print_output(rules, i, EAT) == false || rules->dth_flag == true)
// 		return (false);
// 	init_wait_time(rules, rules->tm_to_eat);
// 	pthread_mutex_unlock(&rules->mute_forks[rules->philo[i].forks.left]);
// 	pthread_mutex_unlock(&rules->mute_forks[rules->philo[i].forks.right]);
// 	rules->philo[i].nb_eat++;
// 	return (true);
// }

// t_bool	fucking_sleep(t_rules *rules, int i)
// {
// 	if (rules->dth_flag == true)
// 		return (false);
// 	if (print_output(rules, i, SLP) == false || rules->dth_flag == true)
// 		return (false);
// 	init_wait_time(rules, rules->tm_to_sleep);
// 	return (true);
// }

// t_bool	think(t_rules *rules, int i)
// {
// 	if (rules->dth_flag == true)
// 		return (false);
// 	if (print_output(rules, i, THK) == false || rules->dth_flag == true)
// 		return (false);
// 	return (true);
// }
