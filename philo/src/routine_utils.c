/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 16:57:50 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/12/09 17:51:52 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_bool	print_output(t_rules *rules, int i, char *str)
{
	if (rules->dth_flag == true)
		return (false);
	pthread_mutex_lock(&rules->mute_write);
	printf("%ld %d %s\n", (init_time() - rules->start_time),
		rules->philo[i].id, str);
	pthread_mutex_unlock(&rules->mute_write);
	return (true);
}

// t_bool	are_we_full(t_rules *rules, int i)
// {
// 	int	j;
	
// 	j = 0;
// 	while (1)
// 	{
// 		if (rules->philo[i].nb_eat <= 0)
// 			j++;
// 		if (j == rules->nb_philo)
// 		{
// 			rules->dth_flag = true;
// 			print_output(rules, i, DTH);
// 			break ;
// 		}
// 	}
// }

// int	check_meal(t_philo *philo)
// {
// 	unsigned int	i;
// 	unsigned int	k;

// 	k = 0;
// 	i = 0;
// 	if (philo->rules->meal_done == true)
// 		return (0);
// 	while (i != philo->rules->philo_total)
// 	{
// 		if (philo[i].nb_meal >= \
// 			(int)philo->rules->number_of_times_each_philosopher_must_eat)
// 		k++;
// 		if (k == philo->rules->philo_total)
// 		{
// 			philo->rules->someone_died = true;
// 			philo->rules->meal_done = true;
// 			printf("All philosophers ate %i time(s)\n", \
// 				philo->rules->number_of_times_each_philosopher_must_eat);
// 			return (0);
// 		}
// 		i++;
// 	}
// 	return (0);
// }