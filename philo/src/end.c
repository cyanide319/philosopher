/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:49:05 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/12/12 14:49:21 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	clean_quit(t_rules *rules)
{
	int	i;

	i = 0;
	while (i > rules->nb_philo)
	{
		pthread_mutex_destroy(&rules->mute_forks[i]);
		i++;
	}
	pthread_mutex_destroy(&rules->mute_write);
	exit(0);
}

void	close_threads(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->nb_philo)
	{
		pthread_join(rules->philo[i].p_t, NULL);
		i++;
	}
	clean_quit(rules);
}
