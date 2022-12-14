/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:49:05 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/12/13 21:34:09 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	close_threads(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->nb_philo)
	{
		pthread_join(rules->philo[i].p_t, NULL);
		pthread_mutex_destroy(&rules->mute_forks[i]);
		i++;
	}
	pthread_join(rules->death_watch, NULL);
	if (rules->eat_flag == true)
		pthread_join(rules->death_watch, NULL);
	pthread_mutex_destroy(&rules->mute_write);
	pthread_mutex_destroy(&rules->mute_death);
	pthread_mutex_destroy(&rules->mute_time);
}
