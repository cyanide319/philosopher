/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:56:20 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/11/24 13:20:06 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

// void	init_rules(t_rules	*rules, int argc, char **argv)
// {
// 	rules->nb_philo = ft_atol(argv[1]);
// 	rules->tm_to_die = ft_atol(argv[2]);
// 	rules->tm_to_eat = ft_atol(argv[3]);
// 	rules->tm_to_sleep = ft_atol(argv[4]);
// 	if (argc == 6)
// 		rules->nb_of_eat = ft_atol(argv[5]);
// 	else
// 		rules->nb_of_eat = INT_MAX;
// }

int	main(int argc, char **argv)
{
	t_rules	rules;

	if (argc >= 5 && argc <= 6)
		check_errors(&rules, argc, argv);
	else
		error_quit(2, &rules);
}
