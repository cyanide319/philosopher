/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:56:20 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/12/09 17:23:09 by tbeaudoi         ###   ########.fr       */
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
	// free(rules->mute_forks);
	// free(rules->philo);
	pthread_mutex_destroy(&rules->mute_write);
	exit(0);
}

void	close_threads(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->nb_philo)
	{
		// if (rules->philo[i].nb_eat == 0 || rules->dth_flag == true)
		// {
		// 	pthread_detach(rules->philo[i].p_t);
		// }
		// if (rules->philo[i].last_eat
		// 	- (init_time() - rules->start_time) > rules->tm_to_die)
		// {
		// 	printf("%ld %d is dead\n", (init_time() - rules->start_time),
		// 		rules->philo[i].id);
		// }
		// else
		pthread_join(rules->philo[i].p_t, NULL);
			// pthread_join(rules->death_watch[i], NULL);
		i++;
	}
	clean_quit(rules);
}

int	main(int argc, char **argv)
{
	t_rules	rules;

	if (argc >= 5 && argc <= 6)
		check_errors(&rules, argc, argv);
	else
		error_quit(2, &rules);
}
