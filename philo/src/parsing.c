/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeaudoi <tbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:52:11 by tbeaudoi          #+#    #+#             */
/*   Updated: 2022/11/22 12:29:35 by tbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	error_quit(int code)
{
	if (code == 1)
		printf("Bad input.\n");
	if (code == 2)
		printf("4 args + 1 optional.\n");
	write (2, "Error\n", 6);
	exit (0);
}

t_bool	check_digits(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

t_bool	check_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i == 10)
			return (false);
		i++;
	}
	return (true);
}

void	init_rules(t_philo *rules, int argc, char **argv)
{
	rules->nb_philo = ft_atoi(argv[1]);
	rules->tm_to_die = ft_atoi(argv[2]);
	rules->tm_to_eat = ft_atoi(argv[3]);
	rules->tm_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		rules->nb_of_eat = ft_atoi(argv[5]);
	else
		rules->nb_of_eat = INT_MAX;
}

void	check_errors(t_philo *rules, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (check_digits(argv[i]) == false
			|| check_len(argv[i]) == false)
			error_quit(1);
		i++;
	}
	init_rules(rules, argc, argv);
}
